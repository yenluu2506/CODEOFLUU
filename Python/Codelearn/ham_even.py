#Initial list
res = []

# Input lengths
lengths = int(input())

# Add element
for i in range(lengths):
    # Input elements
    n = int(input())
    res.append(n)


def evenNum(res):
    tmp=[]
    for i in res:
        if i%2==0:
            tmp.append(i)
    return tmp
print (evenNum(res))