class Student:
    stream = "yl"
    def __init__ (self, roll):
        self.roll = roll
#doi tuong cua lop Student
a = Student(1)
b = Student(2)

print(a.stream)
print(b.stream)
print(a.roll)
print(Student.stream)