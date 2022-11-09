import random

def run():
    choice1 = random.randint(1,3)
    if choice1 == 1:
        choice2 = random.randint(1, 100)
        if choice2 <= 56:
            output = 2
        elif choice2 <= 81:
            output = 4
        else:
            output = 6
    elif choice1 == 2:
        choice2 = random.randint(1, 100)
        if choice2 <= 51:
            output = 1
        else:
            output = 5
    else:
        output = 3

    return output

ones = 0
twos = 0
draw = 0
for i in range(100000000):
    result1 = run()
    result2 = run()
    if result1 > result2:
        ones += 1
    elif result2 > result1:
        twos += 1
    else:
        draw += 1
print(ones, twos, draw)
print(ones/(ones+twos+draw)*100, twos/(ones+twos+draw)*100, draw/(ones+twos+draw)*100)