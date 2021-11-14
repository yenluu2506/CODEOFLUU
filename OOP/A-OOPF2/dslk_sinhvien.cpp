//#include <iostream>
//#include <string>
//
//using namespace std;
//
////tao cau truc sinh vien
//struct Sinhvien {
//	int id;
//	string fullname;
//	string dob;
//	float gpa;
//	string classs;
//	string major;
//};
//
////cau truc danh sach lien ket don
//struct Node {
//	Sinhvien* data;
//	Node* next;
//};
//struct List {
//	Node* head;
//};
//void danhsach(List*& list) {
//	list = new List;
//	list->head = NULL;
//}
//
//Sinhvien* nhapSinhvien() {
//	Sinhvien* sinhvien = new Sinhvien;
//	cout << "Nhap ma sinh vien: ";
//	cin >> sinhvien->id;
//	cout << "Nhap ho va ten:";
//	getline(cin, sinhvien->fullname);
//	cout << "Nhap ngay sinh: ";
//	getline(cin, sinhvien->dob);
//	cout << "Nhap diem trung binh: ";
//	cin >> sinhvien->gpa;
//	cout << "Nhap lop: ";
//	getline(cin, sinhvien->classs);
//	cout << "Nhap nganh hoc: ";
//	getline(cin, sinhvien->major);
//}
//
//Node* CreateNode(Sinhvien* sinhvien) {
//	Node* node = new Node;
//	if (node != NULL) {
//		node->data = sinhvien;
//		node->next = NULL;
//	}
//	else
//		cout << "Cap phat bo nho khong thanh cong.";
//	return node;
//}
//void InsertLast(List*& list, Sinhvien* sinhvien)
//{
//	Node* node = CreateNode(sinhvien);
//	if (list->head == NULL)
//	{
//		list->head = node;
//	}
//	else
//	{
//		Node* pTmp = list->head;
//
//		while (pTmp->next != NULL)
//		{
//			pTmp = pTmp->next;
//		}
//		pTmp->next = node;
//	}
//}
//void PrintList(List* list)
//{
//	Node* pTmp = list->head;
//	if (pTmp == NULL)
//	{
//		cout << "Danh sach rong";
//		return;
//	}
//	while (pTmp != NULL)
//	{
//		Sinhvien* sinhvien = pTmp->data;
//		cout << sinhvien->id << "\t" << sinhvien->fullname << "\t" << sinhvien->dob << "\t" << sinhvien->gpa << "\t" << sinhvien->classs << "\t" << sinhvien->major << "\n";
//		pTmp = pTmp->next;
//	}
//}
