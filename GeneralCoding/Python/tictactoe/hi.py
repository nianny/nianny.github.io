board = "" #the tic tac toe board

def init():
    board = [["_", "_", "_"],["_", "_", "_"],["_", "_", "_"]]
    return board

def show(x):
    for i in x:
        toPrint = ""
        for j in i:
            toPrint += j + " "
        print(toPrint)

def move_x(x, i, j):
    x[i-1][j-1] = 'x'

def move_o(x, i, j):
    x[i-1][j-1] = "o"

def countmoves(x):
    count = 0
    for i in x:
     for j in i:
         if (j != "_"):
             count += 1
    print(count)

def getmoves(x):
    toPrint = {'x': [], 'y': []}
    counter1 = 0
    counter2 = 0
    for i in x:
        counter1+=1
        for j in i:
            counter2+=1
            if (x[counter1][counter2] == "x"):
                toPrint['x'].append((counter1+1, counter2+1))
            elif (x[counter1][counter2] == "o"):
                toPrint['y'].append((counter1+1, counter2+1))
        counter2 = 0
    print(toPrint)

def win(x):
    #horizontal and vertical
    for i in range(3):
        #horizontal
        if (x[i][0] == 'x' and x[i][1] == 'x' and x[i][2] == 'x'):
            return 'x'

        if (x[0][i] == 'x' and x[0][i] == 'x' and x[0][i] == 'x'):
            return 'x'
        
        #vertical
        if (x[i][0] == 'y' and x[i][1] == 'y' and x[i][2] == 'y'):
            return 'y'
        
        if (x[0][i] == 'y' and x[0][i] == 'y' and x[0][i] == 'y'):
            return 'y'
    
    #diagonal
    if (x[0][0] == 'x' and x[1][1] == 'x' and x[2][2] == 'x'):
        return 'x'

    if (x[0][0] == 'y' and x[1][1] == 'y' and x[2][2] == 'y'):
        return 'y'

    if (x[2][0] == 'x' and x[1][1] == 'x' and x[0][2] == 'x'):
        return 'x'

    if (x[2][0] == 'y' and x[1][1] == 'y' and x[0][2] == 'y'):
        return 'y'
    
    return 'false'

init()
# print(board[0][0])
print(board)
move_x(board,1,1)
show(board)