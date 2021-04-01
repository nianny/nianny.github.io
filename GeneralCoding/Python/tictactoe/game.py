def init():
    a = [['_','_','_'],['_','_','_'],['_','_','_']]
    return a


def show(x):
    for i in range(3):
        s = ""
        for p in range(3):
            s = s + x[i][p]
        print(s)

a = init()
show(a)