s = input()
# chuyen chu thuong thanh hoa
print(s.upper())
# tra ve do dai cua chuoi
print(len(s))
# chuyen mot chuoi ve dang thuong
print(s.lower())
# kiểm tra xem một xâu có chỉ chứa các ký tự chữ và số hay không
print(s.isalnum())
# kiểm tra xem một chuỗi có chứa toàn các ký tự chữ không
print(s.isalpha())
# kiểm tra xem một xâu có chứa toàn các ký tự số hay không
print(s.isnumeric())
# cắt một chuỗi ra thành list các chuỗi khác
print(s.split(" "))
# nối một tập hợp thành một chuỗi sử dụng kí tự cho trước
lst = ["Welcome", "to", "Codelearn.io!"]
print(" ".join(lst))
# thay thế các chuỗi con tìm thấy thành chuỗi con mới
name = "Cod3l3arn"
print(name.replace("3", "e"))