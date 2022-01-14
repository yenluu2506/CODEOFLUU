from locale import currency
from tkinter import CURRENT

def ask_yes_no(prompt):
    while True:
        answer = input(prompt)
        if answer == "yes":
            return True
        elif answer == "no":
            return False
        else:
            continue
def calculate_age(year_born, current_year):
    CURRENT_YEAR = 2022
    return current_year - year_born
def convert_meter_to_feet(meter):
    METER_TO_FEET = 3.281
    feet = meter * METER_TO_FEET
    feet = round(feet,2)
    return feet
def print_height_info(height_feet, is_male):
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
            i=0
            while i<10:
                print("very", end = " ")
                i+=1
            print("short as a girl")
        else:
            print("You are short as a girl")
def print_person_info(first_name, last_name, age, CURRENT_YEAR, height_feet, is_vietnamese, is_male):
    print("\n---")
    print("Your name is " + first_name + " " + last_name)
    print("{2} is {0} years old in {1}".format(age, CURRENT_YEAR, last_name))
    print("You are " + str(height_feet) + " feet tail")

    if is_vietnamese == True:
        print("You are from Vietnamese")
    else:
        print("You are not from Vietnamese")
    print_height_info(height_feet, is_male)
def ask_person_info():
    first_name = input("Input first name: ")
    last_name = input("Input last name: ")
    year_born = input("When you were born: ")
    height_meter = input("Input height(meter): ")
    is_male = ask_yes_no("Are you male(yes/no): ")
    is_vietnamese = ask_yes_no("Are you Vietnamese (yes/no): ")
    return first_name, last_name, year_born, height_meter, is_male, is_vietnamese
def main():
    CURRENT_YEAR = 2022
    first_name, last_name, year_born, height_meter, is_male, is_vietnamese = ask_person_info()
    year_born = int(year_born)
    age = calculate_age(year_born, CURRENT_YEAR)
    height_meter = float(height_meter)
    height_feet = convert_meter_to_feet(height_meter)
    print_person_info(first_name, last_name, age, CURRENT_YEAR, height_feet, is_vietnamese, is_male)
    #print_height_info(height_feet, is_male)

main()