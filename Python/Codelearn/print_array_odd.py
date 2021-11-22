n = int(input())
lst=[]
for i in range (n):
    lst.append(int(input()))
v=[]
for i in lst:
    if i%2==1:
        v.append(i)
print(v)