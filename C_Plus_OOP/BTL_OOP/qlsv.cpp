#include <iostream>
#include <string.h>
#include <Vector>
#include <fstream>
#include "DoHoa.h"
int pos_x=0,pos_y=0;
const int GIA = 331000;
const int DOC = 20;
const int Nen = 238;
const int Man = 241;
const int mc = 245;
using namespace std ;
class SinhVien{
	protected:
		int mssv;
		string tensv;
		string khoalop;
		string tag="null";
	public :
		SinhVien();
		~SinhVien();
		virtual void NhapSV();
		virtual void XuatSV();
		virtual long HocPhi()=0;
		virtual string gettag();
		virtual int getmssv(){
			return mssv;
		}
		virtual void Ghiflie(ofstream &fileout){
			fileout<<tag<<"|"<<mssv<<"|"<<tensv<<"|"<<khoalop;
			fileout<<endl;
		}
};
SinhVien::SinhVien(){
	
}
SinhVien::~SinhVien(){
}
void SinhVien::NhapSV(){
	system("cls");
	ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|",Man);Mau("     |   MSSV   |    Ho ten    | Khoa ",mc);Mau("                                         |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,13,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;    
		ToMau(DOC,25,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,26,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,29,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,30,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,31,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,32,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,33,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,35,"|_____________________________________|",Nen);cout<<endl; 
	textcolor(Man);
	pos_x=36;
	pos_y=10;
	gotoxy(pos_x,pos_y);
	cout<<"|";
	cin>>mssv;
	fflush(stdin);	
	pos_x+=11;
	gotoxy(pos_x,pos_y);
	cout<<"|";
	getline(cin,tensv);
	fflush(stdin);
	pos_x+=15;
	gotoxy(pos_x,pos_y);
	cout<<"|";
	getline(cin,khoalop);
	fflush(stdin);
	textcolor(7);
}
void SinhVien::XuatSV(){
	ToMau(DOC+11,9,"|   MSSV   |    Ho ten    | Khoa | Tin chi | HP Ky | Phi phu | Nam DH | Noi DH | HP ",12);cout<<endl;
	textcolor(10);
	pos_x=31;
	gotoxy(pos_x,pos_y);
	cout<<"|"<<mssv;
	fflush(stdin);	
	pos_x+=11;
	gotoxy(pos_x,pos_y);
	cout<<"|"<<tensv;
	fflush(stdin);
	pos_x+=15;
	gotoxy(pos_x,pos_y);
	cout<<"|"<<khoalop;
	fflush(stdin);
	textcolor(7);
}
string SinhVien::gettag(){
	return tag;
}
		
class SinhVienVuaHocVuaLam:public SinhVien{
	private:
		float hocphitheoky,phiphuthu;
		string tag="svvhvl";
	public:
		void NhapSV();
		void XuatSV();
		long HocPhi();
		string gettag(){
			return tag;
		}
		int getmssv(){
			return mssv;
		}
		void Ghiflie(ofstream &fileout){
			fileout<<tag<<"|"<<mssv<<"|"<<tensv<<"|"<<khoalop<<"|"<<hocphitheoky<<"|"<<phiphuthu;
			fileout<<endl;
		}
};
void SinhVienVuaHocVuaLam::NhapSV(){
	SinhVien::NhapSV();
	pos_x+=7;
	pos_y--;
	gotoxy(pos_x,pos_y);
	ToMau(pos_x,pos_y,"| HP Ky ",mc);
	pos_y++;
	gotoxy(pos_x,pos_y);
	textcolor(Man);
	cout<<"|";
	cin>>hocphitheoky;
	fflush(stdin);
	pos_x+=8;
	pos_y--;
	ToMau(pos_x,pos_y,"| Phi phu |",mc);
	pos_y++;
	gotoxy(pos_x,pos_y);
	textcolor(Man);
	cout<<"|";
	cin>>phiphuthu;
	fflush(stdin);
	textcolor(7);
}
void SinhVienVuaHocVuaLam::XuatSV(){
	SinhVien::XuatSV();
	pos_x+=17;
	gotoxy(pos_x,pos_y);
	textcolor(10);
	cout<<"|"<<hocphitheoky;
	pos_x+=8;
	gotoxy(pos_x,pos_y);
	textcolor(10);
	cout<<"|"<<phiphuthu;
	textcolor(7);
	pos_x+=28;
	gotoxy(pos_x,pos_y);
	textcolor(10);
	cout<<"|"<<HocPhi();
	pos_y++;
}
long SinhVienVuaHocVuaLam::HocPhi(){
	return hocphitheoky+phiphuthu;
}

class SinhVienChinhQuy:public SinhVien{
	protected:
		int sotinchi;
		string tag="svcq";
	public:
		void NhapSV();
		void XuatSV();
		long HocPhi();
		string gettag(){
			return tag;
		}
		int getmssv(){
			return mssv;
		}
		void Ghiflie(ofstream &fileout){
			fileout<<tag<<"|"<<mssv<<"|"<<tensv<<"|"<<khoalop<<"|"<<sotinchi;
			fileout<<endl;
		}
};
void SinhVienChinhQuy::NhapSV(){
	SinhVien::NhapSV();
	pos_x+=7;
	pos_y--;
	ToMau(pos_x,pos_y,"| Tin chi |",mc);
	pos_y++;
	gotoxy(pos_x,pos_y);
	textcolor(Man);
	cout<<"|";
	cin>>sotinchi;
	fflush(stdin);
	textcolor(7);
}
void SinhVienChinhQuy::XuatSV(){
	SinhVien::XuatSV();	
	pos_x+=7;
	gotoxy(pos_x,pos_y);
	textcolor(10);
	cout<<"|"<<sotinchi;
	pos_x+=46;
	gotoxy(pos_x,pos_y);
	textcolor(10);
	cout<<"|"<<HocPhi();
	textcolor(7);	
	pos_y++;
}
long SinhVienChinhQuy::HocPhi(){
	return GIA*sotinchi;
}

class SinhVienDuHoc:public SinhVien{
	private:
		int sonamduhoc;
		string noiduhoc;
		string tag = "svdh";
	public:
		void NhapSV();
		void XuatSV();
		long HocPhi();
		string gettag(){
			return tag;
		}
		int getmssv(){
			return mssv;
		}
		void Ghiflie(ofstream &fileout){
			fileout<<tag<<"|"<<mssv<<"|"<<tensv<<"|"<<khoalop<<"|"<<sonamduhoc<<"|"<<noiduhoc;
			fileout<<endl;
		}
};
void SinhVienDuHoc::NhapSV(){
	SinhVien::NhapSV();
	pos_x+=9;
	pos_y--;
	ToMau(pos_x,pos_y,"| Nam DH |",mc);
	pos_y++;
	gotoxy(pos_x,pos_y);
	textcolor(Man);
	cout<<"|";
	cin>>sonamduhoc;
	fflush(stdin);
	pos_x+=10;
	pos_y--;
	ToMau(pos_x,pos_y," Noi DH |",mc);
	pos_x--;
	pos_y++;
	gotoxy(pos_x,pos_y);
	textcolor(Man);
	cout<<"|";
	getline(cin,noiduhoc);
	fflush(stdin);
	textcolor(7);
}
void SinhVienDuHoc::XuatSV(){
	SinhVien::XuatSV();
	pos_x+=35;
	gotoxy(pos_x,pos_y);
	textcolor(10);
	cout<<"|"<<sonamduhoc;
	pos_x+=9;
	gotoxy(pos_x,pos_y);
	textcolor(10);
	cout<<"|"<<noiduhoc;
	pos_x+=9;
	gotoxy(pos_x,pos_y);
	textcolor(10);
	cout<<"|"<<HocPhi();
	pos_y++;
	textcolor(7);

}
long SinhVienDuHoc::HocPhi(){
	long x;
	if(noiduhoc=="my"){
		x=20000000*sonamduhoc;
	}else if(noiduhoc=="phap"){
		x=25000000*sonamduhoc;
	}else if(noiduhoc=="duc"){
		x=30000000*sonamduhoc;
	}else{
		return 0;
	}
	return x;
}

class QLSV{
	private:
		vector<SinhVien *> qlsv;
		SinhVien *sv;
		ofstream fileout;
	public:
		QLSV(){
				
		}
		~QLSV(){
			delete sv;	
		}
		void Nhap();
		void Xuat();
		void menuxuat();
		void Xuatsvcq();
		void Xuatsvdh();
		void Xuatsvvhvl();
		void Sua();
		void Them();
		void Xoa();
		void Clear();
		void TimKiem();
		void SapXepTheoKhoaTuBe();
		void SapXepTheoKhoaTuLon();
		void TrangChu();
		void ghi(ofstream &fileout){
			for(int i=0; i<qlsv.size();i++){
			qlsv.at(i)->Ghiflie(fileout);
		}
	}
};	
void QLSV::Nhap(){
	int x,y;
	
	while(true){
		system("cls");
		ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|          ",Man);Mau("Chon loai sinh vien can them",mc);Mau("                                         |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|            ",Man);Mau("1) Sinh vien chinh quy",mc);Mau("                                             |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|            ",Man);Mau("2) Sinh vien du hoc",mc);Mau("                                                |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|            ",Man);Mau("3) Sinh vien vua hoc vua lam",mc);Mau("                                       |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,13,"|         ",Nen);Mau("|            ",Man);Mau("4) Quay lai menu",mc);Mau("                                                   |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;    
		ToMau(DOC,25,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,26,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,29,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,30,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,31,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,32,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,33,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,35,"|_____________________________________|",Nen);cout<<endl; 
		ToMau(DOC,15,"|         ",Nen);Mau("|            ",Man);Mau("   Nhap yeu cau: ",mc);Mau("                                                  |",Man);Mau("        |",Nen);cout<<endl;
		gotoxy(60,15);textcolor(Man);cin >>x;textcolor(7);
		system("cls");
		switch (x){
				case 1: 
				sv = new SinhVienChinhQuy;
				sv->NhapSV();
				bool st;
 				st = false;
				if(qlsv.size()==0){
					qlsv.push_back(sv);
				}else{
					for(int i=qlsv.size()-1;i>=0;i--){
						if(qlsv.at(i)->getmssv()==sv->getmssv()){
							cout<<"Cung mssv";
							st = true;
					}
				}
				if(st==false) qlsv.push_back(sv);
			}
				break;
			case 2: 
				st = false;
				sv = new SinhVienDuHoc;
				sv->NhapSV();
				if(qlsv.size()==0){
					qlsv.push_back(sv);
				}else{
					for(int i=qlsv.size()-1;i>=0;i--){
						if(qlsv.at(i)->getmssv()==sv->getmssv()){
							cout<<"Cung mssv";
							st = true;
					}
				}
				if(st==false) qlsv.push_back(sv);
			}
				break;
			case 3: 
				st = false;
				sv = new SinhVienVuaHocVuaLam;
				sv->NhapSV();
				if(qlsv.size()==0){
					qlsv.push_back(sv);
				}else{
					for(int i=qlsv.size()-1;i>=0;i--){
						if(qlsv.at(i)->getmssv()==sv->getmssv()){
							cout<<"Cung mssv";
							st = true;
					}
				}
				if(st==false) qlsv.push_back(sv);
			}
				break;
			case 4:
				menuxuat();
				break;
			default: 
		ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|          ",Man);Mau("Chon loai sinh vien can them",mc);Mau("                                         |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|            ",Man);Mau("1) Sinh vien chinh quy",mc);Mau("                                             |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|            ",Man);Mau("2) Sinh vien du hoc",mc);Mau("                                                |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|            ",Man);Mau("3) Sinh vien vua hoc vua lam",mc);Mau("                                       |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,13,"|         ",Nen);Mau("|            ",Man);Mau("4) Quay lai menu",mc);Mau("                                                   |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;    
		ToMau(DOC,25,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,26,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,29,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,30,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,31,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,32,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,33,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,35,"|_____________________________________|",Nen);cout<<endl; 
		ToMau(31,21,"Nhap sai du lieu",mc);				
		}
		ToMau(33,22,"1) Nhap lai",mc);
		ToMau(33,23,"2) Thoat",mc);
		ToMau(35,24,"Nhap lua chon: ",mc);textcolor(Man);cin>>y;textcolor(7);
		if(y==2){
			break;
		}
	}
}

void QLSV::Xuat(){
	int x,y;
	while(true){
		system("cls");
		ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|          ",Man);Mau("Chon loai sinh vien can xuat",mc);Mau("                                         |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|            ",Man);Mau("1) Tat ca sinh vien",mc);Mau("                                                |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|            ",Man);Mau("2) Sinh vien chinh quy",mc);Mau("                                             |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|            ",Man);Mau("3) Sinh vien du hoc",mc);Mau("                                                |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,13,"|         ",Nen);Mau("|            ",Man);Mau("4) Sinh vien vua hoc vua lam",mc);Mau("                                       |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|            ",Man);Mau("5) Quay lai menu",mc);Mau("                                                   |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,25,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,26,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,29,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,30,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,31,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,32,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,33,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,35,"|_____________________________________|",Nen);cout<<endl; 
		ToMau(DOC,15,"|         ",Nen);Mau("|            ",Man);Mau("   Nhap yeu cau: ",mc);Mau("                                                  |",Man);Mau("        |",Nen);cout<<endl;
		gotoxy(60,15);textcolor(Man);cin >>x;textcolor(7);
		system("cls");
		switch (x){
			case 1:
				system("cls");
				cout<<"\n\n\n\n\n\n\n\n\n";
				pos_y=10;
				for(int i=0;i<qlsv.size();i++){
					qlsv.at(i)->XuatSV();
					ToMau(30,pos_y++,"_________________________________________________________________________",7);
					pos_y++;
				}	
				break;
			case 2: 
				Xuatsvcq();
				break;
			case 3: 
				Xuatsvdh();
				break;
			case 4: 
				Xuatsvvhvl();
				break;
			case 5:
				menuxuat();
				break;
			default: 
		ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|          ",Man);Mau("Chon loai sinh vien can them",mc);Mau("                                         |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|            ",Man);Mau("1) Sinh vien chinh quy",mc);Mau("                                             |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|            ",Man);Mau("2) Sinh vien du hoc",mc);Mau("                                                |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|            ",Man);Mau("3) Sinh vien vua hoc vua lam",mc);Mau("                                       |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,13,"|         ",Nen);Mau("|            ",Man);Mau("4) Quay lai menu",mc);Mau("                                                   |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;    
		ToMau(DOC,25,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,26,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,29,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,30,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,31,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,32,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,33,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,35,"|_____________________________________|",Nen);cout<<endl; 
		ToMau(31,21,"Nhap sai du lieu",mc);				
		}
		ToMau(33,22,"1) Nhap lai",mc);
		ToMau(33,23,"2) Thoat",mc);
		ToMau(35,24,"Nhap lua chon: ",mc);textcolor(Man);cin>>y;textcolor(7);
		if(y==2){
			break;
		}
	}
}

void QLSV::Xuatsvcq(){
	system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n";
	pos_y=10;
	for(int i=0;i<qlsv.size();i++){
		if(qlsv.at(i)->gettag()=="svcq"){
			qlsv.at(i)->XuatSV();
			ToMau(30,pos_y++,"_________________________________________________________________________",7);
			pos_y++;
		}	
	}
}	
void QLSV::Xuatsvdh(){
	system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n";
	pos_y=10;
	for(int i=0;i<qlsv.size();i++){
		if(qlsv.at(i)->gettag()=="svdh"){
			qlsv.at(i)->XuatSV();
			ToMau(30,pos_y++,"_________________________________________________________________________",7);
			pos_y++;
		}	
	}
}
void QLSV::Xuatsvvhvl(){
	system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n";
	pos_y=10;
	for(int i=0;i<qlsv.size();i++){
		if(qlsv.at(i)->gettag()=="svvhvl"){
			qlsv.at(i)->XuatSV();
			ToMau(35,pos_y++,"_________________________________________________________________________",7);
			pos_y++;
		}	
	}
}
void QLSV::Them(){
	system("cls");
	int vt,y;
	do{
	textcolor(7);
		ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,13,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;    
		ToMau(DOC,25,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,26,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,29,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,30,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,31,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,32,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,33,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,35,"|_____________________________________|",Nen);cout<<endl; 
	ToMau(DOC+21,9,"Nhap vi tri can them: ",mc);
	gotoxy(DOC+43,9);
	textcolor(mc);
	cin>>vt;
	textcolor(7);
	if(vt<0||vt>qlsv.size()) {
		ToMau(DOC+21,9,"Vi tri ban nhap khong co trong danh sach",mc);
		ToMau(DOC+21,10,"Ban co muon nhap tiep: ",mc);
		ToMau(DOC+21,11,"1)Nhap tiep",mc);
		ToMau(DOC+21,12,"2)Quay lai",mc);
		ToMau(DOC+21,13,"Nhap lua chon cua ban: ",mc);
		textcolor(mc);
		gotoxy(DOC+44,13);
		cin>>y;
		textcolor(7);
		switch(y){
			case 1:
				break;
			case 2:
				menuxuat();
				break;
			default:
				ToMau(DOC,10,"Lua chon khong dung vui long nhap lai",mc);
				break;
		}
	}
	system("cls");
	}while(vt<0||vt>qlsv.size());
	int x;
		system("cls");	
		ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|          ",Man);Mau("Chon loai sinh vien can them",mc);Mau("                                         |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|            ",Man);Mau("1) Sinh vien chinh quy",mc);Mau("                                             |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|            ",Man);Mau("2) Sinh vien du hoc",mc);Mau("                                                |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|            ",Man);Mau("3) Sinh vien vua hoc vua lam",mc);Mau("                                       |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,13,"|         ",Nen);Mau("|            ",Man);Mau("4) Quay lai menu",mc);Mau("                                                   |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;    
		ToMau(DOC,25,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,26,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,29,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,30,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,31,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,32,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,33,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,35,"|_____________________________________|",Nen);cout<<endl; 
		ToMau(DOC,15,"|         ",Nen);Mau("|            ",Man);Mau("   Nhap yeu cau: ",mc);Mau("                                                  |",Man);Mau("        |",Nen);cout<<endl;
		gotoxy(60,15);textcolor(Man);cin >>x;textcolor(7);
		system("cls");
		switch (x){
			case 1: 
				sv = new SinhVienChinhQuy;
				sv->NhapSV();
				bool st;
 				st = false;
				if(qlsv.size()==0){
					qlsv.push_back(sv);
				}else{
					for(int i=qlsv.size()-1;i>=0;i--){
						if(qlsv.at(i)->getmssv()==sv->getmssv()){
							cout<<"Cung mssv";
							st = true;
					}
				}
				if(st==false) qlsv.insert(qlsv.begin()+vt,sv);
			}
				break;
			case 2: 
				st = false;
				sv = new SinhVienDuHoc;
				sv->NhapSV();
				if(qlsv.size()==0){
					qlsv.push_back(sv);
				}else{
					for(int i=qlsv.size()-1;i>=0;i--){
						if(qlsv.at(i)->getmssv()==sv->getmssv()){
							cout<<"Cung mssv";
							st = true;
					}
				}
				if(st==false) qlsv.insert(qlsv.begin()+vt,sv);
			}
				break;
			case 3: 
				st = false;
				sv = new SinhVienVuaHocVuaLam;
				sv->NhapSV();
				if(qlsv.size()==0){
					qlsv.push_back(sv);
				}else{
					for(int i=qlsv.size()-1;i>=0;i--){
						if(qlsv.at(i)->getmssv()==sv->getmssv()){
							cout<<"Cung mssv";
							st = true;
					}
				}
				if(st==false) qlsv.insert(qlsv.begin()+vt,sv);
			}
				break;
			case 4:
				menuxuat();
			default: cout<<"\nNhap sai du lieu ";				
		}
}
void QLSV::Xoa(){
	system("cls");
	int vt,y;
	do{
	textcolor(7);
		ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,13,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;    
		ToMau(DOC,25,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,26,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,29,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,30,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,31,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,32,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,33,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,35,"|_____________________________________|",Nen);cout<<endl; 
	ToMau(DOC+21,9,"Nhap ma so sinh vien can xoa: ",mc);
	gotoxy(DOC+51,9);
	textcolor(mc);
	cin>>vt;
	textcolor(7);
	if(vt<0||vt>qlsv.size()) {
		ToMau(DOC+21,9,"Vi tri ban nhap khong co trong danh sach",mc);
		ToMau(DOC+21,10,"Ban co muon nhap tiep: ",mc);
		ToMau(DOC+21,11,"1)Nhap tiep",mc);
		ToMau(DOC+21,12,"2)Quay lai",mc);
		ToMau(DOC+21,13,"Nhap lua chon cua ban: ",mc);
		textcolor(mc);
		gotoxy(DOC+44,13);
		cin>>y;
		textcolor(7);
		switch(y){
			case 1:
				break;
			case 2:
				menuxuat();
				break;
			default:
				ToMau(DOC,10,"Lua chon khong dung vui long nhap lai",mc);
				break;
		}
	}
	system("cls");
	}while(vt<0||vt>qlsv.size());
	bool st;
	for(int i=0;i<qlsv.size();i++){
		if(qlsv.at(i)->getmssv()==vt){
			system("cls");
			qlsv.erase(qlsv.begin()+i);
			st = true;
		}
	}
	if(st == false) cout<<"khong tim thay mssv";
	gotoxy(31,21);
	system("pause");
}
void QLSV::Sua(){
	system("cls");
	int vt,y;
	bool st;
	st = false;
	do{
	textcolor(7);
		ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,13,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;    
		ToMau(DOC,25,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,26,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,29,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,30,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,31,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,32,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,33,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,35,"|_____________________________________|",Nen);cout<<endl; 
	ToMau(DOC+21,9,"Nhap ma so sinh vien can xoa: ",mc);
	gotoxy(DOC+51,9);
	textcolor(mc);
	cin>>vt;
	textcolor(7);
	if(vt<0||vt>qlsv.size()) {
		ToMau(DOC+21,9,"Vi tri ban nhap khong co trong danh sach",mc);
		ToMau(DOC+21,10,"Ban co muon nhap tiep: ",mc);
		ToMau(DOC+21,11,"1)Nhap tiep",mc);
		ToMau(DOC+21,12,"2)Quay lai",mc);
		ToMau(DOC+21,13,"Nhap lua chon cua ban: ",mc);
		textcolor(mc);
		gotoxy(DOC+44,13);
		cin>>y;
		textcolor(7);
		switch(y){
			case 1:
				break;
			case 2:
				menuxuat();
				break;
			default:
				ToMau(DOC,10,"Lua chon khong dung vui long nhap lai",mc);
				break;
		}
	}
	system("cls");
	}while(vt<0||vt>qlsv.size());
	for(int i=0;i<qlsv.size();i++){
		if(qlsv.at(i)->getmssv()==vt){
			system("cls");
			if(qlsv.at(i)->gettag()=="svcq"){
				sv = new SinhVienChinhQuy;
				sv->NhapSV();
				qlsv.at(i) = sv;
			}else if(qlsv.at(i)->gettag()=="svdh"){
				sv = new SinhVienDuHoc;
				sv->NhapSV();
				qlsv.at(i) = sv;
			}else if(qlsv.at(i)->gettag()=="svvhvl"){
				sv = new SinhVienVuaHocVuaLam;
				sv->NhapSV();
				qlsv.at(i) = sv;
			}else exit(0);
			st = true;
		}
		
	}
	if(st == false) cout<<"khong tim thay mssv";
	gotoxy(31,21);
	system("pause");
}
void QLSV::Clear(){
	qlsv.clear();
}	
void QLSV::SapXepTheoKhoaTuBe(){
	// for(int i=0;i<qlsv.size();i++){
	// 	for(int j=0;j<qlsv.size()-i-1;j++){
	// 		if(qlsv.at(j)->getmssv()>qlsv.at(j+1)->getmssv()){
	// 			SinhVien*a = qlsv.at(j);
	// 			qlsv.at(j) = qlsv.at(j+1);
	// 			qlsv.at(j+1) = a;
	// 		}	
	// 	}
	// }
	for(int i=0;i<qlsv.size();i++){
		for(int j=0;j<qlsv.size()-i-1;j++){
			if(qlsv.at(j)->getmssv()>qlsv.at(j+1)->getmssv()){
				SinhVien*a = qlsv.at(j);
				qlsv.at(j) = qlsv.at(j+1);
				qlsv.at(j+1) = a;
			}	
		}
	}
	QLSV::Xuat();
}
//void QLSV::SapXepTheoKhoaTuLon(){
//	for(int i=0;i<qlsv.size();i++){
//		for(int j=0;j<qlsv.size()-i-1;j++){
//			if(qlsv.at(j)->getmssv()<qlsv.at(j+1)->getmssv()){
//				SinhVien*a = qlsv.at(j);
//				qlsv.at(j) = qlsv.at(j+1);
//				qlsv.at(j+1) = a;
//			}	
//		}
//	}
//	QLSV::Xuat();
//}

void QLSV::TimKiem(){
	system("cls");
	int vt;
	cout<<"Nhap mssv: ";
	cin>>vt;
	bool st;
	pos_y=10;
	for(int i=0;i<qlsv.size();i++){
		if(qlsv.at(i)->getmssv()==vt){
			system("cls");
			qlsv.at(i)->XuatSV();
			st = true;
			break;
		}
	}
	if(st == false) cout<<"khong tim thay mssv";
	gotoxy(31,21);
	system("pause");
	system("cls");
}

void QLSV::menuxuat(){
	int x,y;
	system("cls");	
	while(1){
		ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|          ",Man);Mau("1.Nhap danh sach sinh vien ",mc);Mau("                                          |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|          ",Man);Mau("2.Xuat DS",mc);Mau("                                                            |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|          ",Man);Mau("3.Them sinh vien tai mot vi tri",mc);Mau("                                      |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|          ",Man);Mau("4.Xoa sinh vien theo MSSV",mc);Mau("                                            |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,13,"|         ",Nen);Mau("|          ",Man);Mau("5.Sua du lieu theo MSSV",mc);Mau("                                              |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|          ",Man);Mau("6.Tim kiem theo MSSV",mc);Mau("                                                 |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|          ",Man);Mau("7.Ghi file",mc);Mau("                                                           |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|          ",Man);Mau("10.Sap xep",mc);Mau("                                                           |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|          ",Man);Mau("8.Quay ve trang chu",mc);Mau("                                                  |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;    
		ToMau(DOC,25,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,26,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,29,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,30,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,31,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,32,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,33,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,35,"|_____________________________________|",Nen);cout<<endl; 
		ToMau(DOC,21,"|         ",Nen);Mau("|            ",Man);Mau("   Nhap yeu cau: ",mc);Mau("                                                  |",Man);Mau("        |",Nen);cout<<endl;
		gotoxy(60,21);textcolor(Man);cin >>x;textcolor(7);
		switch (x){
			case 1:
				Nhap();
				break;
			case 2: 
				Xuat();
				break;
			case 3:
				Them();
				break;
			case 4:
				Xoa();
				break;
			case 5:
				Sua();
				break;
			case 6:
				TimKiem();
				break;		
			case 7:
				fileout.open("SINHVIEN.TXT", ios_base::app);
				ghi(fileout);
				TrangChu();
				break;
			case 8:
				fileout.open("SINHVIEN.TXT", ios_base::in);
				(fileout);
				TrangChu();
				break;
			case 10:
				SapXepTheoKhoaTuBe();
				break;
			case 9:
				TrangChu();
				break;
			default: 	
				ToMau(31,22,"Nhap sai du lieu",mc);				
		}
		ToMau(31,24,"Nhap so khac 0 de menu xuat: ",mc);textcolor(Man);cin>>y;textcolor(7);
		if (y==0){
			break;
		}
		textcolor(7);
		system("cls");
	}
}	


void QLSV::TrangChu(){
	int x,y;
	bool a=true;
	while(a){
		system("cls");
		ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|          ",Man);Mau("                         TRANG CHU",mc);Mau("                                   |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|            ",Man);Mau("1) QUAN LY SINH VIEN",mc);Mau("                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|            ",Man);Mau("2) THONG TIN NHOM",mc);Mau("                                                  |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|            ",Man);Mau("3) THOAT",mc);Mau("                                                           |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,25,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;    
		ToMau(DOC,26,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,29,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,30,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,31,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,32,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,33,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,35,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,36,"|_____________________________________|",Nen);cout<<endl;
		 ToMau(DOC,13,"|         ",Nen);Mau("|            ",Man);Mau("   Nhap yeu cau: ",mc);Mau("                                                  |",Man);Mau("        |",Nen);cout<<endl;
		 gotoxy(60,13);textcolor(Man);cin >>x;textcolor(7);
		system("cls");
		switch (x){
			case 1: 
				menuxuat();
				break;
			case 2: 
				int y;
				system("cls");
		ToMau(DOC,1,"____________________________________________________________________________________________________",14);cout<<endl;
		ToMau(DOC,2,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,3,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,4,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,5,"|         ",Nen);Mau("_________________________________________________________________________________",227);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,6,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl; 
		ToMau(DOC,7,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,8,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,9,"|         ",Nen);Mau("|          ",Man);Mau("                     THONG TIN NHOM",mc);Mau("                                  |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,10,"|         ",Nen);Mau("|            ",Man);Mau("1) NGUYEN DANG AN NINH - 6151071081",mc);Mau("                                |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,11,"|         ",Nen);Mau("|            ",Man);Mau("2) PHAN THI KIM NHUNG - 6151071018",mc);Mau("                                 |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,12,"|         ",Nen);Mau("|            ",Man);Mau("3) KIEU THI MONG HIEN  - 6151071046",mc);Mau("                                |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,14,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,15,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,16,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,17,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,18,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,19,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,20,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,21,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,22,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,23,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,24,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;
		ToMau(DOC,25,"|         ",Nen);Mau("|                                                                               |",Man);Mau("        |",Nen);cout<<endl;    
		ToMau(DOC,26,"|         ",Nen);Mau("|_______________________________________________________________________________|",Man);Mau("        |",Nen);cout<<endl;  
		ToMau(DOC,27,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,28,"|                                                                                                  |",Nen);cout<<endl;
		ToMau(DOC,29,"|                                                                                                  |",Nen);cout<<endl;     
		ToMau(DOC,30,"|__________________________________________________________________________________________________|",Nen);cout<<endl; 
		ToMau(DOC+41,31,"|                 |",Nen);cout<<endl;    
		ToMau(DOC+41,32,"|                 |",Nen);textcolor(7);cout<<endl;  
		ToMau(DOC+31,33,"__________|                 |__________",Nen);cout<<endl;  
		ToMau(DOC+31,34,"|                                     |",Nen);cout<<endl;  
		ToMau(DOC+31,35,"|                                     |",Nen);cout<<endl;
		ToMau(DOC+31,36,"|_____________________________________|",Nen);cout<<endl;
		 ToMau(DOC,13,"|         ",Nen);Mau("|            ",Man);Mau("Nhap so bat ki de quay lai trang chu",mc);Mau("                               |",Man);Mau("        |",Nen);cout<<endl;
		 gotoxy(85,13);textcolor(Man);cin>>y;textcolor(7);
			if(y!=0)
				TrangChu();
			else TrangChu();
				break;
			case 3: 
				exit(0);
				break;
			default:	
				ToMau(31,22,"Nhap sai du lieu",mc);	
		}
	}
}

int main()
{
	ofstream fileout;
	resizeConsole(1000,670);
	QLSV QL;
	QL.TrangChu();
    return 0;
}

