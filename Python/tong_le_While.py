a = int(input())
b = int(input())

t=0
while a<=b:
    if(a%2==1):
        t+=a
    a+=1;
print(t)