from locale import currency
from tkinter import CURRENT


CURRENT_YEAR = 2022
METER_TO_FEET = 3.281

first_name = input("Input first name: ")
last_name = input("Input last name: ")
year_born = input("When you were born: ")
height_meter = input("Input height(meter): ")

while True:
    gender_input = input("Are you male (yes/no): ")
    if(gender_input == "yes") or (gender_input == "no"):
        break

year_born = int(year_born)
age = CURRENT_YEAR - year_born

height_meter = float(height_meter)
height_feet = height_meter * METER_TO_FEET
height_feet = round(height_meter, 2)

print("\n---")
print("Your name is " + first_name + " " + last_name)
print("{2} is {0} years old in {1}".format(age, CURRENT_YEAR, last_name))
print("You are " + str(height_feet) + " feet tail")

is_male = None

if gender_input == "yes":
    is_male = True
else:
    is_male = False

if is_male == True:
    if height_feet > 6.5:
        print("You are", end=" ")
        for i in range(10):
            print("very", end=" ")
        print("tail as a man")
    elif height_feet>6.0:
        print("You are tail as a man")
    else:
        print("You are short as a man")
else:
    if height_feet > 5.7:
        print("You are tall as a girl")
    elif height_feet < 5.0:
        print("You are", end=" ")
        i=0;
        while i<10:
            print("very", end = " ")
            i+=1
        print("short as a girl")
    else:
        print("You are short as a girl")
