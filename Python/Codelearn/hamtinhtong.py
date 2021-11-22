def sum_of_list(lst):
    t = 0
    for i in lst:
        t+=i
    return t

lst = []
n = int(input())
for i in range(n):
    lst.append(int(input()))
print(sum_of_list(lst))