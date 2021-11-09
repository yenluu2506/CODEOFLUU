#include<stdio.h>
#include<string.h>
int main(){
	FILE *teptin;
	int sophantu, biendem;
	printf("Nhap so phan tu: ");
	scanf("%d", &sophantu);
	if((teptin = fopen("nhiphan.dat", "wb"))==NULL){
		printf("Khong the ghi duoc.");
	}
	else
		for(biendem=0; biendem<sophantu; biendem++)
		fwrite(&biendem, sizeof(int), 1, teptin);
		fclose(teptin);
	teptin = fopen("nhiphan.dat", "rb");
	while(fread(&biendem, sizeof(int), 1, teptin)==1)
		printf("%d", biendem);
	fclose(teptin);
	return 0;
}
