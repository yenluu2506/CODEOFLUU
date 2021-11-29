x = int(input("Nhap vao x: "))
def fact(x):
    if x == 0:
        return 1;
    # su dung de qui de tinh giai thua
    return x*fact(x-1)
print(fact(x))