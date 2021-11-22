n = int(input())
lst = []

for i in range (n):
    lst.append(int(input()))
v = []
for i in lst:
    if i%5==0:
        v.append(i)
if len(v)==0:
    v =[0]
print(v)