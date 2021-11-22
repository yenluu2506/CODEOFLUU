def get_unique_values(lst):
    t = []
    for i in lst:
        if i not in t:
            t.append(i)
    return t


n = int(input())
lst = []
for i in range(n):
    lst.append(int(input()))
print(get_unique_values(lst))