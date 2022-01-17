#ham kiem tra mot lop co phai la lop con cua lop khac hay khong
#dung ham issubclass()

class Base(object):
    pass
class Derived(Base):
    pass
print(issubclass(Derived, Base))
print(issubclass(Base, Derived))
d = Derived()
b = Base()

print(isinstance(b, Derived))
print(isinstance(d, Base))