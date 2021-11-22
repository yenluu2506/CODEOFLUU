n = int(input())
lst = []
for i in range(n):
    lst.append(int(input()))
min_value = lst[0]
for i in lst:
    if i < min_value:
        min_value = i
print(min_value)