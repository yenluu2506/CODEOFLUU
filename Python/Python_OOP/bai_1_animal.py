class animal():
    name = ' '
    age = 0
    def __init__(self, name = ' ', age = 0):
        self.name = name
        self.age = age
    def show(self):
        print ('My name is ', self.name)
    def run(self):
        print ('Animal is running...')
    def go(self):
        print ('Animal is going...')

class dog(animal):
    def run(self):
        print ('Dog is running...')

myanimal = animal()
myanimal.show()
myanimal.run()
myanimal.go()

mydog = dog('Lucky')
mydog.show()
mydog.run()
mydog.go()