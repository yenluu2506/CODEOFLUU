#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
 
//void myfunc(char** param)
//{
//    ++param;
//}
//int main()
//{
//    char* string = (char*)malloc(64);
//    strcpy(string, "hello_World");
//    myfunc(&string);
//    myfunc(&string);
//    printf("%s\n", string);
//    getch();
//} //1.hello_world

//void myfunc(char** param)
//{
//    ++*param;
//}
//int main()
//{
//    char* string = (char*)malloc(64);
//    strcpy(string, "hello_World");
//    myfunc(&string);
//    myfunc(&string);
//    printf("%s\n", string);
//    getch();
//}  //2.llo_world

//int main()
//{
//    int ints[] = { 0, 1, 2, 3 };
//    int* i1 = ints + 1;
//    int a = ++*i1;
//    int b = a + *i1;
//    printf("%d\n", b);
//    getch();
//}  //3.4

//int main()
//{
//    int ints[] = { 0, 5, 10, 15 };
//    int* i2 = ints + 2;
//    int a = *i2++; // a = *(i2++);
//    printf("%d#%d\n", a, *i2);
//    getch();
//}  //4.10#15

//int main()
//{
//    int ints[] = { 0, 1, 2, 3 };
//    int* i1 = ints + 1;
//    int* i2 = ints + 2;
//    int a = ++*i1 + *i2++;
//    int b = *++i1 + *i2--;
//    printf("%d#%d", a, b);
//    getch();
//}  //5.4#4

//int main()
//{
//    int i = 400;
//    int *ptr = &i;
//    *++ptr = 2;
//    printf("%d %d", i, *ptr);
//    getch();
//}  //6.loi //400 2

//int main()
//{
//    char str[] = {"pvpit"};
//    char *s1 = str;
//    s1++;
//    printf("%c", *s1);
//    getch();
//}  //7.v

//int main()
//{
//    char *s = "\12345s\n";
//    printf("%d", strlen(s));
//    printf("\n%s", s);
//    getch();
//}  //8.5

//int main(int argc, char** argv)
//{
//	//Ð?i v?i do?n mã du?i dây, dòng nào s? du?c trình biên d?ch báo cáo là l?i?
//    const char* foo = "wow"; // line 1
//    foo = "top"; // line 2
//    foo[0] = 1; // line 3
//    return 0;
//}  //9.line3

//int main() 
//{ 
//    int x = 5,y = 6;
//    int* const p = &x;
//    p = &y; 
//    printf("%d", (*p)); 
//    getch();
//}  //10.loi chuong trinh /p la con tro hang trình biên dich khong cho phep thay doi dia chi ma con tro p tro toi

//int main() 
//{ 
//    int x = 5, y = 8;
//    const int* p;
//    p = &x;//dong nay thua
//    p = &y;
//    x++;
//    printf("%d", *p); 
//    getch();
//}  //11.8

//int main() 
//{ 
//    int x = 5;
//    const int* p;
//    p = &x;
//    x++;
//    *p = 4;//line loi
//    printf("%d", *p); 
//    getch();
//}  //12. loi

//int main()
//{
//    int a = 320;
//    char *ptr;
//    ptr = (char*)&a;
//    printf("%d ", *ptr);
//    return 0;
//}  //13.64

//int main()
//{
//    int i = 3;
//    int *j;
//    int **k;
//    j = &i;
//    k = &j;
//    printf("%u , %u , %d ", k, *k, **k);
//    return 0;
//}  //14. dia chi cua j, dia chi cua i, 3/k = &j <=> *k = *&j <=> *k = j <=> **k = *j

//int main()
//{
//    char *ptr1 = NULL;
//    char *ptr2 = 0;
//    printf("\n%d", ptr2);
//    strcpy(ptr1, "c"); //loi
//    strcpy(ptr2, "questions");
//    printf("\n%s %s", ptr1, ptr2);
//    getch();
//} //15.loi chuong trinh

//int main()
//{
//    int a = 10;
//    void *p = &a;
//    int *ptr = p; //loi
//    printf("%u\n", *ptr);
//    getch();
//}  //16. loi chuong trinh

//int main()
//{
//    int a = 5, b = 10, c;
//    int *p = &a, *q = &b;
//    c = p - q;
//    printf("%d" , c);
//    getch();
//}  //17.

//int main()
//{
//    int i = 5, j;
//    int *p , *q;
//    p = &i;
//    q = &j;
//    j = 5;
//    printf("%d %d", *p, *q);
//    getch();
//} //18. 5 5

//void main()
//{
//    int i = 5;
//    int *p;
//    p = &i;
//    printf(" %u %u", *&p , &*p);
//    getch();
//}  //19. dia chia cua i  dia chi cua i/*&p = &*p = p = &i

//int main()
//{
//    int array[2][2][3]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
//    printf("%d", array[1][0][2]);
//    getch();
//}  //20. 8

//int main()
//{
//    char arr[8]={'V','I','E','T','N','A','M'}; 
//    char *p; 
//    p=(char *)(arr+2)[2]; 
//    printf("%c", p);  
//    getch();
//}  //21. N /(arr+2)=E=(arr+2)[0]

//int main()
//{
//    char ch[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//    int *p = (int*)ch;
//    p++;
//    printf("%x", *p);
//    getch();
//}  //22. 37363534

//int main()
//{
//    int i = 11;
//    int const * p = &i;
//    p++;
//    printf("%d", *p); 
//    getch();
//}  //23. gia tri rac


//int main() {
//    int number = 50;
//    int *p;
//    p = &number; // luu tru dia chi cua bien number
//    printf("Dia cua con tro p la %d\n", *p);
//    printf("Dia chi cua con tro p la %p", p);
//    return 0;
//}

//int main() {
//    int a = 10, b = 20;
//    int *p1 = &a,*p2 = &b;  
//    printf("Truoc khi hoan doi: *p1=%d *p2=%d\n", *p1, *p2);
//    // hoan doi
//    *p1 = *p1 + *p2;
//    *p2 = *p1 - *p2;
//    *p1 = *p1 - *p2;
//    printf("Sau khi hoan doi: *p1=%d *p2=%d", *p1, *p2);
//    return 0;
//}

//int main() {
//  int i, arr[6],sum = 0;
//  printf("Nhap 6 so nguyen:\n");
//  for(i = 0; i < 6; ++i)
//  {
//      // (arr + i) la tuong duong voi &arr[i]
//      scanf("%d", (arr + i));
// 
//      // *(arr + i) la tuong duong voi arr[i]
//      sum += *(arr + i);
//  }
//  printf("Sum = %d", sum);
//  return 0;
//}

//int main()
//{
//int x = 1;
//short int i = 2;
//float f = 3;
//if (sizeof((x == 2) ? f : i) == sizeof(float))
//printf("float\n");
//else if (sizeof((x == 2) ? f : i) == sizeof(short int))
//printf("short int\n");
//} //float

//main () { struct { int x ;} var = { 5 }, * p = & var ;
// printf ( "% d% d% d" , var . x , p -> x , ( *p ). x ); } 
// //5 5 5


