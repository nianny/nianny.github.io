import math
ans = 0

for i in range(1, 45):
    print((i*16.0), math.floor((i*16.0)/45.0))
    ans += math.floor((i*16.0)/45.0)
print(ans)