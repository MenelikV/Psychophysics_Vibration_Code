%% Original sine wave calculated for some frequency and amplitude as the mother sine wave as a look up table
f= 1; %% original frequency is 1 Hz, and therefore the lowest frequency which can be reached.
t=0:.0001:1; % resolution in time of 10.000 samples. 
sine_table=sin(2*pi*f*t);
subplot(211);
plot(t,sine_table);
xlim([0 0.1]);
ylabel ('Amplitude');
xlabel ('Time Index');
title ('Sine wave');

%% Linear interpolation
f_new = 500; %% new frequency
% reduce the number of points by factor f_new
sine_table_new= sine_table(1:f_new:end); 
t_new = t(1:1:length(sine_table_new));
subplot(212);
plot(t_new,sine_table_new);
xlim([0 0.1]);
%   y0 = sine_table[];
%   x0 = sine_table[];
%   y1 = sine_table[];
%   x1 = sine_table[];
%   x = 
%   y = y0+(y1-y0)*((x-x0)/(x1-x0));