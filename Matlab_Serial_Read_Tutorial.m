close all; % close all figures
clear all; % clear all workspace variables
clc; % clear the command line
fclose('all'); % close all open files
delete(instrfindall);   % Reset Com Port
%delete(timerfindall);   % Delete Timers

Info = instrhwinfo('serial');
ports = Info.AvailableSerialPorts;
port = ports(end);

s=serial(port,'BaudRate',57600); 


%get(s,{'InputBufferSize','BytesAvailable'})
%set(s,'BaudRate', 115200);
%set(s,'DataBits', 8);
%set(s,'StopBits', 1);
fopen(s);
pause(3);

%s.ReadAsyncMode = 'continuous';

% % Start asynchronous reading
readasync(s);

while(true)

for i = 1:1:100

out(i) = fscanf(s, '%d');
%out = fscanf(s, '%d')
%out = fscanf(s, s.BytesAvailable)
end
end

stopasync(s);
delete(s);
clear s;