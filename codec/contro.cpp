#include<stdio.h>
int a=10;
int *b;
int **c;
int main (){
	b=&a;
	c=&b;
	//*b=*b+1;
	// a=a+1
	//b=b+1
	*b=a+1;
	printf("*b = %d", *b);
	printf("\n*b = %d", *b);
	
}
