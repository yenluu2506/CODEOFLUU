s = input()

if len(s)<2:
    print("")
else:
    print(s[0:2]+s[-2:])
    # print(s[0:2] + s[len(s) - 2: len(s)])