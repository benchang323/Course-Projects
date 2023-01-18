function varargout = Chang_problem3(varargin)
% CHANG_PROBLEM3 MATLAB code for Chang_problem3.fig
%      CHANG_PROBLEM3, by itself, creates a new CHANG_PROBLEM3 or raises the existing
%      singleton*.
%
%      H = CHANG_PROBLEM3 returns the handle to a new CHANG_PROBLEM3 or the handle to
%      the existing singleton*.
%
%      CHANG_PROBLEM3('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CHANG_PROBLEM3.M with the given input arguments.
%
%      CHANG_PROBLEM3('Property','Value',...) creates a new CHANG_PROBLEM3 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Chang_problem3_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Chang_problem3_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Chang_problem3

% Last Modified by GUIDE v2.5 17-Jan-2023 20:05:01

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Chang_problem3_OpeningFcn, ...
                   'gui_OutputFcn',  @Chang_problem3_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Chang_problem3 is made visible.
function Chang_problem3_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Chang_problem3 (see VARARGIN)

% Choose default command line output for Chang_problem3
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Chang_problem3 wait for user response (see UIRESUME)
% uiwait(handles.figure1);

% --- Outputs from this function are returned to the command line.
function varargout = Chang_problem3_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;

% --- Executes on button press in import_RLE.
function import_RLE_Callback(hObject, eventdata, handles)
% hObject    handle to import_RLE (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Check if the file path exists in the handles structure
if isfield(handles, 'rleFilePath')
    % Read the RLE file
    rleData = importdata(handles.rleFilePath);

    % Store the RLE data in the handles structure
    handles.rleData = rleData;

    % Update the handles structure
    guidata(hObject, handles);

else
    % Display an error message if file path does not exist
    errordlg('No RLE file selected', 'Import Error');
end


function import_RLE_file_Callback(hObject, eventdata, handles)
% hObject    handle to import_RLE_file (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of import_RLE_file as text
%        str2double(get(hObject,'String')) returns contents of import_RLE_file as a double

% Get the file path from the user
[fileName, filePath] = uigetfile('*.txt', 'Select RLE file');

% Check if user selected a file
if fileName ~= 0
    % Store the file path in the handles structure
    handles.rleFilePath = fullfile(filePath, fileName);

    % Update the edit text box with the file path
    set(hObject, 'String', handles.rleFilePath);

    % Update the handles structure
    guidata(hObject, handles);
end

% --- Executes during object creation, after setting all properties.
function import_RLE_file_CreateFcn(hObject, eventdata, handles)
% hObject    handle to import_RLE_file (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes on button press in random_matrix.
function random_matrix_Callback(hObject, eventdata, handles)
% hObject    handle to random_matrix (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Clear previous frame
cla(handles.axes1);

% Create a random matrix of size 50x50
matrix = randi([0,1],50,50);

% Pad the array so it has enough space
matrix = padarray(matrix,[50, 50],0,'both');

% Store the matrix in the handles structure
handles.matrix = matrix;

% Display the matrix in the axes1
colormap(gray);
imagesc(matrix);
title("Results");

% Update the handles structure
guidata(hObject, handles);


% --- Executes on button press in load.
function load_Callback(hObject, eventdata, handles)
% hObject    handle to load (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Check if the matrix exists in the handles structure
if isfield(handles, 'matrix')
    handles = rmfield(handles,'matrix');
end

% Check if the axes exists in the handles structure
if isfield(handles, 'axes1')
    axesHandle = handles.axes1;
    cla(axesHandle);
end


% Check if the required fields exist in the handles structure
if isfield(handles, 'rleData')
    
    % Decode the RLE data into a matrix
    matrix = RLE_decoder(handles.rleData);

    % Pad the array so it has enough space
    matrix = padarray(matrix,[50, 50],0,'both');

    % Store the matrix in the handles structure
    handles.matrix = matrix;

    % Display the matrix in the axes1
    colormap(gray);
    imagesc(matrix);
    title("Results");

    % Update the handles structure
    guidata(hObject, handles);
elseif isfield(handles, 'matrix') 
    % Store the matrix in the handles structure
    handles.matrix = matrix;

    % Display the matrix in the axes1
    colormap(gray);
    imagesc(matrix);
    title("Results");

    % Update the handles structure
    guidata(hObject, handles);
else
    % Display an error message if required fields do not exist
    errordlg('RLE data, axes1, and matrix fields are required', 'Load Error');
end


% --- Executes on button press in step.
function step_Callback(hObject, eventdata, handles)
% hObject    handle to step (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Check if the matrix exists in the handles structure
if isfield(handles, 'matrix')
    % Clear previous frame
    cla(handles.axes1);

    % Get the matrix from the handles structure
    matrix = handles.matrix;

    % Simulate the next generation using the GOL.m function
    matrix = GOL(matrix);

    % Store the updated matrix in the handles structure
    handles.matrix = matrix;

    % Display the matrix in the axes1
    colormap(gray);
    imagesc(matrix);
    title("Results");

    % Update the handles structure
    guidata(hObject, handles);
else
    % Display an error message if matrix does not exist
    errordlg('No matrix loaded', 'Step Error');
end


% --- Executes on button press in play.
function play_Callback(hObject, eventdata, handles)
% hObject    handle to play (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Retrieve the number of generations and frame rate from the handles structure
generations = handles.generations;
frame_rate = handles.frame_rate;

% Set the initial matrix for the simulation
if isfield(handles, 'rleData')
    matrix = RLE_decoder(handles.rleData);
end

matrix = handles.matrix;

% Loop through the specified number of generations
for i = 1:generations
    % Clear previous frame
    cla(handles.axes1);

    % Update the matrix using the GOL function
    matrix = GOL(matrix);
    
    % Display the matrix in the plot
    colormap(gray);
    imagesc(matrix);
    title("Results");
    
    % Update the handles structure
    guidata(hObject, handles);
    
    % Wait for the specified frame rate before continuing the loop
    pause(1/frame_rate);
end


% --- Executes on button press in stop.
function stop_Callback(hObject, eventdata, handles)
% hObject    handle to stop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of stop

% Get the current state of the stop button
stop_state = get(hObject,'Value');

% If the stop button is pressed, set the stop flag in the handles structure
if stop_state == 1
    handles.stop_flag = 1;
else
    handles.stop_flag = 0;
end

% Update the handles structure
guidata(hObject, handles);


% --- Executes on button press in export_movie.
function export_movie_Callback(hObject, eventdata, handles)
% hObject    handle to export_movie (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on selection change in frame_rate.
function frame_rate_Callback(hObject, eventdata, handles)
% hObject    handle to frame_rate (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns frame_rate contents as cell array
%        contents{get(hObject,'Value')} returns selected item from frame_rate

% Get the selected value from the popup menu
contents = cellstr(get(hObject,'String'));
selection = contents{get(hObject,'Value')};

% Extract the frame rate from the selection string
frame_rate = str2double(selection(1:3));

% Store the frame rate in the handles structure
handles.frame_rate = frame_rate;

% Update the handles structure
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function frame_rate_CreateFcn(hObject, eventdata, handles)
% hObject    handle to frame_rate (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in generations.
function generations_Callback(hObject, eventdata, handles)
% hObject    handle to generations (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns generations contents as cell array
%        contents{get(hObject,'Value')} returns selected item from generations

% Get the selected value from the popup menu
contents = cellstr(get(hObject,'String'));
selection = contents{get(hObject,'Value')};

% Extract the number of generations from the selection string
generations = str2double(selection(1:4));

% Store the number of generations in the handles structure
handles.generations = generations;

% Update the handles structure
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function generations_CreateFcn(hObject, eventdata, handles)
% hObject    handle to generations (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in clear.
function clear_Callback(hObject, eventdata, handles)
% hObject    handle to clear (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Check if the RLE data exists in the handles structure
if isfield(handles, 'rleData')
    handles = rmfield(handles,'rleData');
end

% Check if the matrix exists in the handles structure
if isfield(handles, 'matrix')
    handles = rmfield(handles,'matrix');
end

% Check if the axes exists in the handles structure
if isfield(handles, 'axes1')
    axesHandle = handles.axes1;
    cla(axesHandle);
end

% Update the handles structure
guidata(hObject, handles);
