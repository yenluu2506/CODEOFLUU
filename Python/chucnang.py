n = int(input())
lst = []
for i in range(n):
    lst.append(int(input()))
# sap xep tang
lst.sort()
print(lst)
# sap xep giam
lst.sort(reverse=True)
print(lst)
# tra ve tong so phan tu co trong list
print(len(lst))
# max min
print(max(lst))
print(min(lst))
# insert
lst.insert(2,8)
print(lst)
# remove
lst.remove(3)
print(lst)
# pop xoa phan tu voi chi so cho truoc
lst.pop(1)
print(lst)
# reverse dao nguoc list
lst.reverse(lst)
print(lst)
# count dem su xuat hien cua thanh vien
print(lst.count(2))
# clear xoa het phan tu ben trong list
lst.clear()
print(lst)