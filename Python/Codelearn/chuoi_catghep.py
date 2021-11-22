s1 = input()
s2 = input()

tmp = s1[0:2] + s2[2:]
s1 = s2[0:2] + s1[2:]
s2 = tmp;

print(s1 + " " + s2)