from numpy import matrix
import json

#precompute matrix inverse

with open('inverse.json', 'w') as f:
    data = {};
    for i in range(1,10):
        arr = []
        for x in range(i):
            row = [];
            for y in range(i):
                if (x==y):
                    row.append(4)
                elif (abs(x-y)==1):
                    row.append(1)
                else:
                    row.append(0)
            arr.append(row)
        data[i] = matrix(arr).I.tolist()
        print(i)
    
    f.write(json.dumps(data))
                