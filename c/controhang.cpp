#include <stdio.h>
int main(){
	int a=1, b=2;
	int *pa=&a;
	//pa=pa+1;
	//*pa=*pa+1;
	//con tro hang
	const int *pb=&b;
	//hang con tro
	int* const pb=&b;
	//*pb=6;
	pb=pa;
}
