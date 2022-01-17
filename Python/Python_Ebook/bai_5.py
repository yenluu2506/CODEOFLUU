# một class có ít nhất 2 method:
#getString: để nhận một chuỗi do người dùng nhập vào từ giao diện điều khiển.
#printString: in chuỗi vừa nhập sang chữ hoa.
#Thêm vào các hàm hiểm tra đơn giản để kiểm tra method của class.
class IOString(object):
    def __init__(self):
        self.s = ''
    def getString(self):
        self.s = input("Nhap chuoi: ")
    def printString(self):
        #uper chuyen chuoi thanh chuoi hoa
        print(self.s.upper())
strObj = IOString()
strObj.getString()
strObj.printString()