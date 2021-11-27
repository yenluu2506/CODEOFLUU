#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>

using namespace std;
class nguoi
{
	protected:
		char ten[30];
		int ngay;
		char dc[30];
};
class thisinh:public nguoi
{
		char ma[30];
		float diem1;
		float diem2;
		float diem3;
		float tong;
	public:
		void into(char *s1,int a,char *s2,char *s3,float d1,float d2,float d3,float t)
		{
			strcpy(ten,s1);
			ngay=a;
			strcpy(dc,s2);
			strcpy(ma,s3);
			diem1=d1;
			diem2=d2;
			diem3=d3;
			tong=t;
		}
		void show()
		{
			cout<<"    "<<ten<<" "<<ngay<<" "<<dc<<" "<<ma<<" "<<
			diem1<<" "<<diem2<<" "<<diem3<<" "<<tong<<endl;
		}
		char *getma()
		{
			return(ma);
		}
		float gettong()
 		{
			return(tong);
		}
		char* getten()
		{
			return(ten);
	
		}
}ds,a[100],temp,b[100];
int kt(char s[30])
{
	fstream f("ds.dat",ios::in|ios::binary);
	while(f.read((char*)(&ds),sizeof(ds)))
	if(strcmp(s,ds.getma())==0)
	{
		cout<<"ma da trung moi nhap lai !";
		f.close();
		return 0;
	}
	f.close();
	return 1;
}
void nhap()
{
	char s1[30],s2[30],s3[30],s[30];
	int a;
	float d1,d2,d3,t;
	fstream f("ds.dat",ios::app|ios::binary);
	cout<<"nhap ten sv"; cin.getline(s1,30);
	cout<<"nhap nay sinh"; cin>>a;
	cout<<"nhap dia chi";  cin.ignore();cin.getline(s2,30);
	cout<<"nhap ma";	cin.getline(s3,30);
	while(kt(s3)==0) cin.getline(s3,30);
	cout<<"\tDiem  mon 1: ";cin>>d1;
	while(d1<0||d1>10)
	{
		cout<<"\n\tCo loi!Moi nhap lai diem mon 1: ";cin>>d1;
	}
	cout<<"\tDiem  mon 2: ";cin>>d2;
	while(d2<0||d2>10)
	{
		cout<<"\n\tCo loi!Moi nhap lai diem mon 2: ";cin>>d2;
	}
	cout<<"\tDiem  mon 3: ";cin>>d3;
	while(d3<0||d3>10)
	{
		cout<<"\n\tCo loi!Moi nhap lai diem mon 3: ";cin>>d3;
	}
	t=0;
	t=d1+d2+d3;
	ds.into(s1,a,s2,s3,d1,d2,d3,t);
	f.write((char*)(&ds),sizeof(ds));
	f.close();
}
void sapxep1()
{
	int i=0,n=0,j;
	fstream f("ds.dat",ios::in|ios::binary);
	fstream f1("ds1.dat",ios::out|ios::binary);
	while(f.read((char*)(&a[i]),sizeof(a[i])))
	{
	       i++;n++;
	}
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(strcmp(a[i].getma(),a[j].getma())<0)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	for(i=0;i<n;i++)
	{
		a[i].show();
		f1.write((char*)(&a[i]),sizeof(a[i]));
	}
	f.close();
	f1.close();
}
void sapxep2()
{
	int i=0,n=0,j;
	fstream f("ds.dat",ios::in|ios::binary);
	fstream f2("ds2.dat",ios::out|ios::binary);
	while(f.read((char*)(&b[i]),sizeof(b[i])))
	{
	       i++;n++;
	}
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(b[i].gettong()<a[j].gettong())
	{
		temp=b[i];
		b[i]=b[j];
		b[j]=temp;
	}
	for(i=0;i<n;i++)
	{
		b[i].show();
		f2.write((char*)(&b[i]),sizeof(b[i]));
	}
	f.close();
	f2.close();
}
void tim1()
{
	char ss[30];
	fstream f("ds.dat",ios::in|ios::binary);
	cout<<"moi ban nhap ma can tim "; cin.ignore();
	cout<<endl;	cin.getline(ss,30);  cout<<ss;
	while(f.read((char*)(&ds),sizeof(ds)))
	if(strcmp(ss,ds.getma())==0)
	ds.show();
	f.close();
}
void tim2()
{
	char ss[30];
	fstream f("ds.dat",ios::in|ios::binary);
	cout<<"moi ban nhap ten can tim ";
	cout<<endl;	cin.getline(ss,30);
	while(f.read((char*)(&ds),sizeof(ds)))
	if(strcmp(ss,ds.getten())==0)
	ds.show();
	f.close();
}
void tim3()
{
	float g;
	fstream f("ds.dat",ios::in|ios::binary);
	cout<<"nhap diem tong";
	cin>>g;
	while(f.read((char*)(&ds),sizeof(ds)))
	if(ds.gettong()==g)
	ds.show();
	f.close();
}

void in()
{
	fstream f("ds.dat",ios::in|ios::binary);
	while(f.read((char*)(&ds),sizeof(ds)))
	ds.show() ;
	f.close();
}
int main()
{
	nhap();
	in();   cout<<endl;
	sapxep1();
	tim1();
	tim2();
	tim3();
	sapxep2();
	getch();
}