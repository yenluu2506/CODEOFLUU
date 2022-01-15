class Person:
    #ham init tuong tu nhu ham constructor trong c++
    def __init__(self, name):
        self.name = name
    def say_hi(self):
        print("Hello, my name is", self.name)

p = Person("Yen Luu")
p.say_hi()

