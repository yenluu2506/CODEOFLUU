//bai3 
#include <stdio.h>
void menu(){
	int chon;
	printf("----Menu----");
	printf("\n1. Ga ran");
	printf("\n2. Bo kho");
	printf("\n3. Com chien");
	printf("\n4. Vit quay");
	printf("\n5. Thoat");
	printf("\n");
	printf("\nMoi ban lua chon: ");
	scanf("%d", &chon);
	switch(chon){
		case 1:{
			printf("1. Ban da chon ga ran");
			break;
		}
		case 2: {
			printf("2. Ban da chon bo kho");
			break;
		}
		case 3: {
			printf("3. Ban da chon com chien");
			break;
		}
		case 4: {
			printf("4. Ban da chon vit quay");
			break;
		}
		case 5: {
			break;
		}
	}
}
int main(){
	menu();
}
