#include<stdio.h>
#include<string.h>
struct Sach{
	char TenSach[100];
	char TacGia[100];
	int NamXuatBan;
};
typedef Sach SACH;
void Nhap(SACH &s1){
	fflush(stdin);
	printf("Nhap ten sach: ");
	gets(s1.TenSach);
	fflush(stdin);
	printf("Nhap ten tac gia: ");
	gets(s1.TacGia);
	printf("Nhap nam xuat ban: ");
	scanf("%d",&s1.NamXuatBan);
}
void Xuat(Sach s1){
	printf("\tTen sach: %s\n",s1.TenSach );
	printf("\tTen tac gia: %s\n", s1.TacGia);
	printf("\tNam xuat ban: %d\n",s1.NamXuatBan);
}
void NhapDS(Sach s1[], int n){
	for (int i=0;i<n;i++){
		printf("Nhap quyen thu %d: \n",i);
		Nhap(s1[i]);
	}
}
void XuatDS(Sach s1[], int n){
	for(int i=0; i<n;i++){
		printf("Thong tin quyen thu %d \n", i);
		Xuat(s1[i]);
	}
}
int DemTacGia(Sach s[],int n){
	char Ten[50];
	int dem=0;
	fflush(stdin);
	printf("Nhap vao ten tac gia: ");
	gets(Ten);
	for(int i=0;i<n;i++){
		if(strcmp(Ten,s[i].TacGia)==0)
			dem++;
	}
	return dem;
}
void ThongKe(Sach s[],int n){
	int dem=0;
	printf("\nThong tin sach nam %d: \n", s[0].NamXuatBan);
	for(int i=0;i<n;i++){
		Xuat(s[i]);
		dem++;
		if(s[i+1].NamXuatBan!=s[i].NamXuatBan){
			printf("\t** Nam %d co %d quyen sach\n",s[i].NamXuatBan,dem);
			dem=0;
			if(i<n-1)
				printf("\nThong tin sach nam %d: \n", s[i+1].NamXuatBan);
		}
	}
}
void Menu(){
	int chon, flat=1;
	while(flat){
		printf("1. Nhap danh sach cac quyen sach.\n");
		printf("2. Xuat danh sach cac quyen sach.\n");
		printf("3. Dem so sach theo tac gia.\n");
		printf("4. Thong ke sach.\n");
		printf("5. Thoat.\n");
		printf("Moi ban chon chuc nang: ");
		scanf("%d", &chon);
		switch(chon){
			case 1: 
				struct Sach a[100];
				int n;
				printf ("Nhap n: ");
				scanf ("%d", &n);
				NhapDS(a,n);
				break;
			case 2:
				printf("\nThong tin sach da nhap vao la: \n");
				XuatDS(a,n);
				break;
			case 3:
				printf("Co %d quyen cua tac gia can tim\n",DemTacGia(a,n));
				break;
			case 4:
				ThongKe(a,n);
				break;
			case 5:
				flat=0;		
		}
	}
}
int main(){	
	Menu();
}
