#include <stdio.h>

int main(){
	int var;
	printf("Nhap var: ");
	scanf("%d", &var);
	printf("\nGia tri cua var la: %d", var);
	printf("\nDia chi cua var la: %p", &var);
	
	int *pc, c;
	c = 5;
	pc = &c;
	printf("\n Gia tri cua c la: %d", *pc);
	printf("\n Dia chi cua c la: %p", pc);
	
	*pc = 1;
	printf("\n Gia tri cua c la: %d", *pc);
	printf("\n Dia chi cua c la: %p", pc);
}
