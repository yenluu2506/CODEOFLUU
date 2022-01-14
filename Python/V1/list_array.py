colors = ["red", "green", "blue"]
print(colors)
print(colors[0])

print(len(colors))

colors.append("yellow")
for i in range(4):
    print(colors[i])
print(len(colors))

last_index = len(colors)-1
print(colors[-1])