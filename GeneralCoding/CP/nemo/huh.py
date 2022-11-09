
import random
def draw():
    bag = random.randint(1, 3)
    if bag == 1:
        b1 = random.randint(1, 100)
        if 1 <= b1 <= 56:
            bird = 2
        elif 57 <= b1 <= 81:
            bird = 4
        else: # 82 <= b1 <= 100
            bird = 6
    elif bag == 2:
        b2 = random.randint(1, 100)
        if 1 <= b2 <= 51:
            bird = 1
        elif 52 <= b2 <= 100:
            bird = 5
    else: # bag == 3
        bird = 3
    return bird

results = [0, 0, 0]   # player 1 wins, player 2 wins, ties

for i in range(10**7):
    bird1 = draw()
    bird2 = draw()
    if bird1 > bird2:
        results[0] += 1
    elif bird2 > bird1:
        results[1] += 1
    else:
        results[2] += 1
sum = results[0] + results[1] + results[2]
print("player 1 won %d times, player 2 won %d times, and there were %d ties" % (results[0], results[1], results[2]))
print(f"player 1 won {results[0]/sum*100} times, player 2 won {results[1]/sum*100} times, and there were {results[2]/sum*100} ties")