import copy, sys

def showPath(path):
    for position in path:
        sys.stdout.write("(" + str(position[0]) + ", " + str(position[1]) + "), ")
    sys.stdout.write("\n\n")
    sys.stdout.flush()

def findPath(path):
    #showPath(path)
    global finalPath
    x = path[-1][0]
    y = path[-1][1]
    if x == 2 and y == 1:
            showPath(path)
            if len(finalPath) == 0 or len(finalPath) > len (path):
                finalPath[:] = copy.deepcopy(path)
            return
    if x > 0 and matrix[x-1][y] > matrix[x][y]:
            # we can move up
            newPath = copy.deepcopy(path)
            newPath.append([x-1, y])
            findPath(newPath)
    if x < 2 and matrix[x+1][y] > matrix[x][y]:
            # we can move down
            newPath = copy.deepcopy(path)
            newPath.append([x+1, y])
            findPath(newPath)
    if y > 0 and matrix[x][y-1] > matrix[x][y]:
            # we can move left
            newPath = copy.deepcopy(path)
            newPath.append([x, y-1])
            findPath(newPath)
    if y < 1 and matrix[x][y+1] > matrix[x][y]:
            # we can move right
            newPath = copy.deepcopy(path)
            newPath.append([x, y+1])
            findPath(newPath)                    

matrix = [
            [0, 99, 98],
            [1, 3, 87],
            [43, 4, 5],
        ]
        
path = []
path.append([0, 0])
finalPath = []
findPath(path)
print ("Shortest Path: " + str(len(finalPath)) + " steps.\n")
showPath(finalPath)