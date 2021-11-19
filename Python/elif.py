temperature = int(input())

if temperature>=100:
    print("Stay at home and enjoy a good movie")
elif temperature >= 92:
    print("Stay at home")
elif temperature == 75:
    print("Go outside and enjoy the weather")
elif temperature <= 0:
    print("It's cool outside")
else:
    print("Let's go to school")