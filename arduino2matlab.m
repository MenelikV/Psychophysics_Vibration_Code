%Function to process the incoming raw data from the arduino
function [time, button_pressed] = arduino2matlab(feedback,timeout)
    if(isempty(feedback))
        error('empty feedback after the timeout');
    end
    if(length(feedback) < timeout/2 - 1)
    
    warning('the reception of the incoming data may not be successful'); %#ok<WNTAG>
    end

    possible_indices = {find(feedback == 'r');find(feedback == 'b')};
   
    % Check if a letter has been detected 
    
    if(isempty(possible_indices))
     error('Pressed button not dectected');
    end
    
    [~,indice] = max(cellfun(@length,possible_indices)); %Indice of the non empty cell
    
    switch indice
        case 1
            button_pressed = 'red';
            letter =  'r';
        case 2
            button_pressed = 'black';
            letter = 'b';
        otherwise
            error('Pressed button not recognized')
            
    end
    
    letter_indices =  find(feedback == letter);
    len_number = letter_indices(2) - letter_indices(1) - 3;
    time_array = feedback(letter_indices(1)+1:letter_indices(1)+len_number);
    time = str2num(time_array); %#ok<ST2NM>
end
