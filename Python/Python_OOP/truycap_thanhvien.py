class Base(object):
    def __init__(self, x):
        self.x = x
class Derived(Base):
    def __init__(self,x,y):
        Base.x = x
        self.y = y
    def printXY(self):
        print (Base.x, self.y)
d = Derived(10, 20)
d.printXY()