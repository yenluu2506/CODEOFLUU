#include <stdio.h>
//truyen tham tri
void hoandoi_1(int a, int b){
	int temp = a;
	a =b;
	b=temp;
}
//truyen tham chieu theo dia chi bien
void hoandoi_2(int &a, int &b){
	int temp = a;
	a =b;
	b=temp;
}
//Su dung con tro
void hoandoi_3(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int a=5; int b=10;
	printf("Truoc khi hoan doi 1: a=%d va b = %d", a,b);
	hoandoi_1(a,b);
	printf("\nSau khi hoan doi 1: a=%d va b = %d", a,b);
	printf("\nTruoc khi hoan doi 2: a=%d va b = %d", a,b);
	hoandoi_2(a,b);
	printf("\nSau khi hoan doi 2: a=%d va b = %d", a,b);
	printf("\nTruoc khi hoan doi 3: a=%d va b = %d", a,b);
	hoandoi_3(&a,&b);
	printf("\nSau khi hoan doi 3: a=%d va b = %d", a,b);

}
