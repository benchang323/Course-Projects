function [next_gen_mat] = nextgen_CDE(in_mat)
    % next_gen_matput matrix
    next_gen_mat = zeros(size(in_mat));
    % Minus padded amount
    for i=1:length(in_mat)-50
        for j=1:length(in_mat)
            % Normal Case (8 Neighbors)
            if (i ~= 1) && (i ~= length(in_mat)) && (j ~= 1) && (j ~= length(in_mat))
                % Amount of live neighbors
                ln = sum(sum(in_mat(i-1:i+1, j-1:j+1)))-in_mat(i, j);
                % Apply the 4 rules for the current cell
                % Live cell conditions
                if in_mat(i, j) == 1
                    % Any live cell with two or three live neighbors lives on to the next generation.
                    if (ln < 2) || (ln > 3)
                        next_gen_mat(i, j) = 0;
                    % Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                    % Any live cell with more than three live neighbors dies, as if by overpopulation.
                    else
                        next_gen_mat(i, j) = 1;
                    end
                % Dead cell conditions
                else
                    % Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if ln == 3
                        next_gen_mat(i, j) = 1;
                    end
                end
            % Corner Cases (3 Neighbors)
            % Top Left Corner
            elseif i == 1 && j == 1
                ln = in_mat(i, j+1) + in_mat(i+1, j+1) + in_mat(i+1, j);
                % Apply the 4 rules for the current cell
                % Live cell conditions
                if in_mat(i, j) == 1
                    % Any live cell with two or three live neighbors lives on to the next generation.
                    if (ln < 2) || (ln > 3)
                        next_gen_mat(i, j) = 0;
                    % Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                    % Any live cell with more than three live neighbors dies, as if by overpopulation.
                    else
                        next_gen_mat(i, j) = 1;
                    end
                % Dead cell conditions
                else
                    % Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if ln == 3
                        next_gen_mat(i, j) = 1;
                    end
                end
            % Top Right Corner
            elseif i == 1 && j == length(in_mat)
                ln = in_mat(i+1, j) + in_mat(i+1, j-1) + in_mat(i, j-1);
                % Apply the 4 rules for the current cell
                % Live cell conditions
                if in_mat(i, j) == 1
                    % Any live cell with two or three live neighbors lives on to the next generation.
                    if (ln < 2) || (ln > 3)
                        next_gen_mat(i, j) = 0;
                    % Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                    % Any live cell with more than three live neighbors dies, as if by overpopulation.
                    else
                        next_gen_mat(i, j) = 1;
                    end
                % Dead cell conditions
                else
                    % Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if ln == 3
                        next_gen_mat(i, j) = 1;
                    end
                end
            % Bottom Left Corner
            elseif i == length(in_mat) && j == 1
                ln = in_mat(i-1, j) + in_mat(i-1, j+1) + in_mat(i, j+1);
                % Apply the 4 rules for the current cell
                % Live cell conditions
                if in_mat(i, j) == 1
                    % Any live cell with two or three live neighbors lives on to the next generation.
                    if (ln < 2) || (ln > 3)
                        next_gen_mat(i, j) = 0;
                    % Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                    % Any live cell with more than three live neighbors dies, as if by overpopulation.
                    else
                        next_gen_mat(i, j) = 1;
                    end
                % Dead cell conditions
                else
                    % Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if ln == 3
                        next_gen_mat(i, j) = 1;
                    end
                end
            % Bottom Right Corner
            elseif i == length(in_mat) && j == length(in_mat)
                ln = in_mat(i, j-1) + in_mat(i-1, j-1) + in_mat(i-1, j);
                % Apply the 4 rules for the current cell
                % Live cell conditions
                if in_mat(i, j) == 1
                    % Any live cell with two or three live neighbors lives on to the next generation.
                    if (ln < 2) || (ln > 3)
                        next_gen_mat(i, j) = 0;
                    % Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                    % Any live cell with more than three live neighbors dies, as if by overpopulation.
                    else
                        next_gen_mat(i, j) = 1;
                    end
                % Dead cell conditions
                else
                    % Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if ln == 3
                        next_gen_mat(i, j) = 1;
                    end
                end
            % Border Cases (5 Neighbors)
            % Top Border
            elseif i == 1
                ln = in_mat(i, j-1) + in_mat(i, j+1) + in_mat(i+1, j-1) + in_mat(i+1, j) + in_mat(i+1, j+1);
                % Apply the 4 rules for the current cell
                % Live cell conditions
                if in_mat(i, j) == 1
                    % Any live cell with two or three live neighbors lives on to the next generation.
                    if (ln < 2) || (ln > 3)
                        next_gen_mat(i, j) = 0;
                    % Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                    % Any live cell with more than three live neighbors dies, as if by overpopulation.
                    else
                        next_gen_mat(i, j) = 1;
                    end
                % Dead cell conditions
                else
                    % Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if ln == 3
                        next_gen_mat(i, j) = 1;
                    end
                end
            % Bottom Border
            elseif i == length(in_mat)
                ln = in_mat(i, j-1) + in_mat(i, j+1) + in_mat(i-1, j-1) + in_mat(i-1, j) + in_mat(i-1, j+1);
                % Apply the 4 rules for the current cell
                % Live cell conditions
                if in_mat(i, j) == 1
                    % Any live cell with two or three live neighbors lives on to the next generation.
                    if (ln < 2) || (ln > 3)
                        next_gen_mat(i, j) = 0;
                    % Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                    % Any live cell with more than three live neighbors dies, as if by overpopulation.
                    else
                        next_gen_mat(i, j) = 1;
                    end
                % Dead cell conditions
                else
                    % Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if ln == 3
                        next_gen_mat(i, j) = 1;
                    end
                end
            % Left Border
            elseif j == 1
                ln = in_mat(i-1, j) + in_mat(i-1, j+1) + in_mat(i, j+1) + in_mat(i+1, j+1) + in_mat(i+1, j);
                % Apply the 4 rules for the current cell
                % Live cell conditions
                if in_mat(i, j) == 1
                    % Any live cell with two or three live neighbors lives on to the next generation.
                    if (ln < 2) || (ln > 3)
                        next_gen_mat(i, j) = 0;
                    % Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                    % Any live cell with more than three live neighbors dies, as if by overpopulation.
                    else
                        next_gen_mat(i, j) = 1;
                    end
                % Dead cell conditions
                else
                    % Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if ln == 3
                        next_gen_mat(i, j) = 1;
                    end
                end
            % Right Border
            elseif j == length(in_mat)
                ln = in_mat(i-1, j) + in_mat(i-1, j-1) + in_mat(i, j-1) + in_mat(i+1, j-1) + in_mat(i+1, j);
                % Apply the 4 rules for the current cell
                % Live cell conditions
                if in_mat(i, j) == 1
                    % Any live cell with two or three live neighbors lives on to the next generation.
                    if (ln < 2) || (ln > 3)
                        next_gen_mat(i, j) = 0;
                    % Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                    % Any live cell with more than three live neighbors dies, as if by overpopulation.
                    else
                        next_gen_mat(i, j) = 1;
                    end
                % Dead cell conditions
                else
                    % Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    if ln == 3
                        next_gen_mat(i, j) = 1;
                    end
                end
            end
        end
    end
end