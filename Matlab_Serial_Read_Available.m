close all; % close all figures
clear all; % clear all workspace variables
clc; % clear the command line
fclose('all'); % close all open files
delete(instrfindall);   % Reset Com Port
%delete(timerfindall);   % Delete Timers

time = 15;

[times values] = SerialArduino (time)

    % Plot the output.
    plot(times, values);
    ylim([0 4095])