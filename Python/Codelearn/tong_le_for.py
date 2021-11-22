a = int(input())
b = int(input())

t=0
for a in range (a, b+1):
    if(a%2==1):
        t+=a
    a+=1;
print(t)