function [mat] = RLE_decoder(file)
% Removed since import already importdata() the RLE file
% % Import string data from file
% file = importdata(file);

% Find the dimensions of pattern
matches = regexp(file, 'x = \d+, y = \d+', 'match');

% Find the cell that contains x and y values
for i = 1:numel(matches)
   if ~isempty(matches{i})
       size_string = matches{i};
       break;
   end
end

% Get the specific x and y values
tokens = regexp(size_string, '(\d+)', 'tokens');
x = str2double(tokens{1}{1});
y = str2double(tokens{1}{2});

% Initialize the array
mat = zeros(y, x);

% Find the GOL pattern
pattern = regexp(file, '(.*!)$', 'match');

% Find the cell that contains the pattern
for i = 1:numel(pattern)
   if ~isempty(pattern{i})
       GOL_string = cell2mat(pattern{i});
       break;
   end
end

% Populate the matrix with GOL_string
run_length = 0;

% Initialize positions
x_pos = 1;
y_pos = 1;

for i = 1:length(GOL_string)
    current_char = GOL_string(i);
    % Set Length
    if isstrprop(current_char, 'digit')
        run_length = run_length*10 + str2double(current_char);
    % Execute
    else
        % Dead cell
        if current_char == 'b'
            % Missing number assumption
            if run_length == 0;
                run_length = 1;
            end
            % Shift
            x_pos = x_pos + run_length; 
            % Reset
            run_length = 0; 
        % Live cell
        elseif current_char == 'o'
            % Missing number assumption
            if run_length == 0 
                run_length = 1;
            end
            % Populate matrix
            for j = 1:run_length
                mat(y_pos,x_pos) = 1;
                x_pos = x_pos + 1;
            end
            run_length = 0;
        elseif current_char == '$'
            x_pos = 1;
            y_pos = y_pos + 1;
        end
    end
end

end

