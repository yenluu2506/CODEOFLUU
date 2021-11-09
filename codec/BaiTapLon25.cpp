#include<stdio.h>
#include<stdlib.h>
struct Students{
    char name[50];
    char sex[30];
    char provincial[30];
    int old;
    int mssv;  
};
typedef struct Students STUDENTS;
void EnterStudent(STUDENTS *sv){
    fflush(stdin);
    printf("\nNhap ten sinh vien: ");
    gets(sv->name);
    printf("\nNhap gioi tinh sinh vien: ");
    gets(sv->sex);
    printf("\nNhap que quan sinh vien: ");
    gets(sv->provincial);
    printf("\nNhap tuoi sinh vien: ");
    scanf("%d",&sv->old);
    printf("\nNhap ma so  sinh vien: ");
    scanf("%d",&sv->mssv);
}
void EnterStudents(STUDENTS *sv, int n){
    printf("\nNhap so luong sinh vien: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       printf("Nhap sinh vien thu %d:\n",i+1);
       sv=(STUDENTS*)realloc(sv,n*sizeof(STUDENTS));
       EnterStudent(&*(sv+i));
    }
}
void ExportStudent(STUDENTS *sv){
	printf("\nTen sinh vien: %s",sv->name);
	printf("\nGioi tinh sinh vien: %s",sv->sex);
    printf("\nQue quan sinh vien: %s",sv->provincial);
    printf("\nTuoi sinh vien: %d",sv->old);
    printf("\nMa so sinh vien: %d",sv->mssv);	
}
void ExportStudents(STUDENTS *sv, int n){
	printf("====Xuat danh sach sinh vien====");
	for(int i=0;i<n;i++){
       printf("\nXuat sinh vien thu %d:",i+1);
       ExportStudent(sv+i);
    }
}
int main(){
	Students *sv;
	sv = (Students *sv)(malloc(sizeof(Students)));
	EnterStudent();
	ExportStudent();
}
