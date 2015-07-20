%
%   SerialArduino
%
%   Makes a serial connection via COM3 to the Arduino. Uses the
%   BytesAvailableFcn event to trigger a function to record data sent by
%   device. The recorded value and time are stored in the vectors values
%   and times respectively.
%
%   Inputs: Time (in seconds) to listen to device.
%   Outputs: Times and Values
%
%   Tested in Matlab 2009b
%
%   Written 12 February 2010
%   by Leo Kent
%
%   http://leo.me.uk/
%

function [times values] = SerialArduino (time)

 
    % Declare the vectors to hold time and value data.
    times = zeros(0,1);
    values = zeros(0,1);
 
    % Setup serial connection.
    ser = serial('COM7', 'BaudRate', 57600);
 
    % Attach the callback function.
    ser.BytesAvailableFcnMode = 'terminator';
    ser.BytesAvailableFcn = @Callback;
 
    % Open the connection.
    fopen(ser);
 
    % Record the time at which we open the connection.
    start_time = tic;
 
    % This is the callback function for when bytes are availble.
    % It adds the received value to the values array and gets time.
    function Callback(obj, event)
 
        % Get the new values.
        v = str2double(fscanf(obj));
        t = toc(start_time);
 
        % Update the vectors.
        values = [values; v];
        times = [times; t];
 
    end
 
    % Wait 5 seconds and close connection.
    % time = 5;
    pause(time);
 
    % Close the serial port connection.
    fclose(ser);
 

 
end