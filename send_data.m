close all; % close all figures
clear all; % clear all workspace variables
clc; % clear the command line
fclose('all'); % close all open files
delete(instrfindall);   % Reset Com Port
%delete(timerfindall);   % Delete Timers

s=serial('COM6','BaudRate',57600); 

 
fopen(s);
pause(3);

f1 = 20;
f2 = 30;
amp1 = 1;
amp2 = 1;
duration1 = 1;
duration2 = 1.2 ;
pause_t = 1;

data = [f1,f2,duration1,duration2,pause_t];
for i = 1 : length(data)
    fwrite(s, data(i), 'uint16', 'sync');
end
r = fread(s,1);
if(r == 115)
    disp('Sucessful send of data')
end
timeout = 10;
while(timeout)
    try
        r = fread(s,1)
        if(r == 116)
            disp('Communication between the two arduino sucessfull')
        end
        sw = [sw, r ];
    catch
        timeout = timeout - 1;
    end
end
delete(s);
clear s;