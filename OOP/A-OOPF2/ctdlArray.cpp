//// trên lớp
//#include <iostream>
//using namespace std;
//
//class ArrayList {
//public:
//	static const int MAX_SIZE = 100;
//	ArrayList();
//	bool isEmpty() const;
//	int length() const;
//	void insert(const int x, int i);
//	void append(const int x);
//	int retrieve(int i) const;
//	void remove(int i);
//	void print() const;
//	int getLast() const;
//private: 
//	int element[MAX_SIZE];
//	int last;
//};
//
//ArrayList::ArrayList() {
//	last = -1;
//}
//int ArrayList::getLast() const {
//	return last;
//}
//bool ArrayList::isEmpty() const {
//	return (last == -1);
//}
//int ArrayList::length() const {
//	return last + 1;
//}
//void ArrayList::insert(const int x, int i) {
//	if (last + 1 == MAX_SIZE) {
//		cout << "The list is full!" << endl;
//		exit(0);
//	}
//	for (int j = last - 1; j > i; j--) {
//		element[j] = element[i - 1];
//	}
//	element[i] = x;
//}
//void ArrayList::remove(int i) {
//	if (last <= 0) {
//		return;
//	}
//	if (i < 0) {
//		i = 0;
//	}
//	else if (i >= last) {
//		i = last - 1;
//	}
//	for (int j = i; j < last; j++) {
//		element[j] = element[j + 1];
//	}
//	--last;
//}
//int ArrayList::retrieve(int i) const {
//	cout << "Tra ve vi tri: ";
//	cin >> i;
//	int t;
//	for (int j = 0; j <= last; j++)
//		if (j == i)
//			t = element[j];
//	return t;
//}
//void ArrayList::append(const int x) {
//	if (last + 1 == MAX_SIZE) {
//		cout << "The list is full" << endl;
//		exit(0);
//	}
//	element[last + 1] = x;
//	last++;
//}
//void ArrayList::print() const {
//	for (int i = 0; i <= last; i++) {
//		cout << element[i] << " " << endl;
//	}
//}
//
//int main() {
//	ArrayList list;
//	list.append(3);
//	list.print();
//	cout << endl;
//
//	list.append(7);
//	list.print();
//	cout << endl;
//
//	list.append(1);
//	list.print();
//	cout << endl;
//
//	cout << "So luong phan tu cua danh sach la: ";
//	cout << list.length();
//	cout << endl;
//
//	cout << "Chi so cua phan tu cuoi cung cua danh sach la: ";
//	cout << list.getLast();
//	cout << endl;
//
//	list.insert(9, 1);
//	list.print();
//	cout << endl;
//
//	list.remove(0);
//	list.print();
//	cout << endl;
//	
//	list.retrieve(3);
//	list.print();
//	cout << endl;
//
//	return 0;
//}
