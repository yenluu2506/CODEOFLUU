class Person(object):
    def __init__(self, name):
        self.name = name
    def getName(self):
        return self.name
    #Để kiểm tra xem người này có phải là nhân viên không
    def isEmployee(self):
        return False
class Employee(Person):
    def isEmployee(self):
        return True

emp = Person("1")
print(emp.getName(), emp.isEmployee())
emp = Employee("2")
print(emp.getName(), emp.isEmployee())