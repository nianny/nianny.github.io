import random

a=0
b=0
for i in range(1000000):
    
    
    trigger = True
    
    while(trigger):
        x=random.randint(1,6)+random.randint(1,6);
        y=random.randint(1,6)+random.randint(1,6);
        if (x==6):
            a+=1
            trigger = False
            continue
        
        if (y==7):
            b+=1
            trigger = False
            continue

print(a,b,a/(a+b))