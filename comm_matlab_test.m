% Matlab script for the pyscho physic try

%% Global Initialization

close all;              % close all figures
clc;                    % clear the command line
fclose('all');          % close all open files
delete(instrfindall);   % Reset Com Port
%delete(timerfindall);  % Delete Timers
digits(6)               % Calculus with 6 digits
if(exist('s','var'))
    if(isa(s,'serial')) % Suppress the serial variable if it exists
        delete(s);
        clear all; %#ok<CLSCR>
    end
end

%% Connection with the arduino

Info = instrhwinfo('serial');
ports = Info.AvailableSerialPorts;
port = ports(end);


s=serial(port,'BaudRate',57600); 

fopen(s);
pause(3);

%% Experimental paramters

f1 = 40;
f2 = 15;

% Amplitude should be below 1, no check in scripts though
a1 = 0.5;
a2 = 0.6;

% Duration given in ms
duration = 1000; 
pause_t = 1000;

exp = [f1, f2, a1, a2, duration, pause_t];

%% Send the parameters to the arduino
disp('Sending data to the arduino A0')


exp_mod = [];
for i = 1:length(exp)
if(exp(i) < 2^16)
    temp = num2str(exp(i));
    exp_mod = [exp_mod temp unicode2native('\n')]; %#ok<AGROW>
        
else
    error('Number too high')
end
end

fwrite(s,unicode2native('\n'));
for i=1:length(exp_mod)    
    fwrite(s,exp_mod(i));
    if(fread(s,1) == 115)
        disp('Sending sucessfull')
    else
        warning('the sending of data may not be as sucessfull as axpected by Mister FRIEDL') %#ok<WNTAG>
    end
end
fwrite(s,unicode2native('\t'));
  

%% Wait for the stimuli

total_duration = (2*duration + pause_t)/1000; %total duration in s
pause(total_duration);


%% Get the feedback from th earduino and display the results

disp('Reading the results from the arduino')

readasync(s);

feedback = [];  %Raw data incoming from arduino
timeout = 10^2; %Timeout for the reading 

while(j < timeout && length(feedback) < timeout/2)
    feedback = [feedback,native2unicode(fread(s,1))]; %#ok<AGROW,N2UNI>
    j = j + 1;
end

[time, button_pressed] = arduino2matlab(feedback, timeout);

% display the result
sprintf('time elapsed in ms : %d \n',time)
sprintf('button pressed : %s \n', button_pressed)
 

%% Delete the connection with Matlab, reset the variables
stopasync(s);
delete(s);
clear s;