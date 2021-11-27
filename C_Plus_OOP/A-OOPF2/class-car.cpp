#include<iostream>
#include<string>

using namespace std;
/* định nghĩa lớp */
class car {
private:
	int  speed;               // tốc độ  
	string  mark;           // nhãn hiệu
	float price;               // giá xe 
public:
	void	setspeed(int);     // gán tốc độ cho xe
	int		getspeed();           // lấy tốc độ xe    
	void	setmark(string);      // gán nhãn cho xe     
	string 	getmark();           // lấy nhãn xe      
	void	setprice(float);      // gán giá cho xe     
	float	getprice();           // lấy giá xe
	void	init(int, string, float);// khởi tạo thông tin về xe
	void	show();               // hiển thị thông tin về xe
};

/* khai báo phương thức bên ngoài lớp */
void car::setspeed(int speedin) { // gán tốc độ cho xe   
	speed = speedin;
}

int car::getspeed() {           // lấy tốc độ xe       
	return speed;
}

void car::setmark(string markin) {     // gán nhãn cho xe      
	mark = markin;
}

string car::getmark() {           // lấy nhãn xe      
	return mark;
}
void car::setprice(float pricein) { // gán giá cho xe      
	price = pricein;
}
float car::getprice() {           // lấy giá xe    
	return price;
}
void car::init(int speedin, string markin, float pricein) {
	speed = speedin;
	mark = markin;
	price = pricein;
	return;
}

void car::show() {                // phương thức hiển thị xe
	cout << "this is a " << mark
		<< " having a speed of  " << speed << "km/h and its price is $" << price << endl;
	return;
}

// hàm main, chuong trình chính 
int main() {

	int length;  	 	 	// chiều dài mảng  	
	float maxprice = 0; 	 	// giá đắt nhất 
	int index = 0;  	 	// chỉ số của xe đắt nhất 
	car* cars;  	 	 	// khai báo mảng đối tượng 
							// nhập số lượng xe, tức là chiều dài mảng  	
	cout << "so luong xe: ";
	cin >> length;
	// cấp phát bộ nhớ động cho mảng  	
	cars = new car[length];
	// khởi tạo các đối tượng trong mảng  	
	for (int i = 0; i < length; i++) {
		int speed;  	 	// (biến tạm) tốc độ  	 	
		string mark;  	// (biến tạm) nhãn hiệu  	 	
		float price; 	 	// (biến tạm) giá xe  	 	
		cout << "xe thu " << i << ": " << endl;
		cout << "toc do (km/h): ";
		cin >> speed;
		cars[i].setspeed(speed); // nhập tốc độ 
		cout << "nhan hieu : ";
		cin >> mark;
		cars[i].setmark(mark);  	// nhập nhãn xe 
		cout << "gia ($): ";
		cin >> price;
		cars[i].setprice(price); // nhập giá xe 
		if (maxprice < price) {
			maxprice = price;
			index = i;
		}
	}

	// tìm xe đắt nhất 
	for (int i = 0; i < length; i++)
		if (i == index) {
			cars[i].show(); // giới thiệu xe đắt nhất  	 	
			break;
		}
	// giải phóng bộ nhớ của mảng 
	delete[] cars;
	system("pause");
	return 0;
}