class Base(object):
    def __init__(self, x):
        self.x = x
class Derived(Base):
    def __init__(self, x, y):
        self.y = y
        super(Derived, self).__init__(x)
    def printXY(self):
        print(self.x, self.y)
d = Derived(10, 20)
d.printXY()