close all; % close all figures
clear all; % clear all workspace variables
clc; % clear the command line
fclose('all'); % close all open files
delete(instrfindall);   % Reset Com Port
%delete(timerfindall);   % Delete Timers

xyz = ('String');

disp(xyz)

global COM;

global s;

s = serial('COM7','BaudRate',9600);

fopen(s);

disp('After OPEN')

disp(s)

fprintf(s,xyz);
fread(s,1);

fclose(s);

disp('After CLOSE')

disp(s)