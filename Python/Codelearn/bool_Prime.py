def is_prime(n):
    count = 0
    i=1
    for i in range (i, n+i):
        if n %i == 0:
            count +=1
    if count == 2:
        return True
    return False


n = int(input())
print(is_prime(n))