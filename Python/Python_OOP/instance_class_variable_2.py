class Student:
    stream = "YL"
    def __init__ (self, roll):
        self.roll = roll
    def setAddress(self, address):
        self.address = address
    def getAddress(self):
        return self.address
a = Student(1)
a.setAddress("YenLuu, 2002")
print(a.getAddress())