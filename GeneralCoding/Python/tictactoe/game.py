def init():
    a = [['_','_','_'],['_','_','_'],['_','_','_']]
    return a


def show(x):
    for i in range(3):
        s = ""
        for p in range(3):
            s = s + x[i][p] +  ' '
        print(s)

def move_x(x,i,j):
    i = i - 1
    j = j - 1
    if x[i][j] == '_':
        x[i][j] = 'x'
    return x

def move_y(x,i,j):
    i = i - 1
    j = j - 1
    if x[i][j] == '_':
        x[i][j] = 'y'
    return x

def countmoves(x):
    a = 0
    b = 0
    for i in range(3):
        for p in range(3):
            if x[i][p] == 'x':
                a = a + 1
            elif x[i][p] == 'y':
                b = b + 1
    print(f"Moves by: \nPlayer 1: {a}\nPlayer 2: {b}" )

def getmoves(x):
    a = []
    b = []
    for i in range(3):
        for p in range(3):
            if x[i][p] == 'x':
                a.append((i+1,p+1))
            elif x[i][p] == 'y':
                b.append((i+1,p+1))
    return {
        'x': a,
        'y': b
    }

def win(x):
    pass

a = init()
show(a)
move_x(a,1,1)
countmoves(a)
print(getmoves(a))
