#include<iostream>
using namespace std;
#define MAX 20


void docfile(char *fname, int a[][MAX], int &n){
	FILE *fp = fopen(fname,"rt");
	if(!fp){
		cout<<"Khong mo duoc file";
		return;
	}
	fscanf(fp,"%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			fscanf(fp, "%d", &a[i][j]);
		}
	}	
	fclose(fp);
}

void inmt(int a[][MAX], int d, int c){
	for(int i = 0; i < d; i++){
		for(int j = 0; j < c; j++){
			cout.width(4);
			cout<<a[i][j];
		}
		cout<<endl;
	}
}

//Kiem tra tu dinh i voi ma mau c co to duoc hay khong
int toduoc(int a[][MAX], int n, int v[], int i, int c){
	for(int j = 0; j < n; j++){
		if(a[i][j] == 1 && v[j] == c) return 0;//Neu dinh i ke dinh j va dinh j da to mau roi
	}
	return 1;
}

//Ham tra ve so dinh da duoc to
int to1mau(int a[][MAX], int n, int v[], int color){
	int count = 0;
	for(int i = 0; i < n; i++){
		if(!v[i] && toduoc(a,n,v,i,color)){
			v[i] = color;
			count++;
		}
	}
	return count;
}

//Ham tra ve so luong mau duoc su dung
int tomau(int a[][MAX], int n, int v[]){
	for(int i = 0; i < n; i++) v[i] = 0;//chua co dinh nao duoc to
	int somau = 0;
	int i = 0;
	while(i < n){
		somau++;
		i += to1mau(a,n,v,somau);
	}
	return somau;
	
}

int main(){
	string color[]={"", "RED", "ORANGE", "YELLOW", "GREEN", "BLACK", "BROWN", "PURPLE"};
	int a[MAX][MAX];
	int n;
	docfile("BTTTUD11_7.txt",a,n);
	inmt(a,n,n);
	int kq;
	int v[MAX];
	kq = tomau(a,n,v);
	cout<<"So mau su dung: "<<kq<<endl;
	cout<<"Ket qua to mau: \n";
	for(int i = 0; i < n; i++){
		cout<<color[v[i]];
		cout.width(10);
	}
	cout<<endl;
	return 0;
}