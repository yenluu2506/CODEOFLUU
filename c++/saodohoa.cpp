#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
void main()
{
  int driver=0, mode = 0, maloi;
  initgraph(&driver,&mode,"C:/TC/BGI");
  if ( (maloi=graphresult()) !=0 )
  {
     printf("khong the khoi dong do hoa \n");
     printf("ma loi : &d \nTran Van Nhuom %s ",maloi, grapherrormsg(maloi) );
     getch();
     exit(1);
  }
  randomize(); // kh?i t?o h�m radom (cho s? ng?u nhi�n)
  int i=0;
  while (i<200)
  {
    putpixel(random(639), random(476), WHITE); /* random(639) t?c l� cho s? ng?u nhi�n trong kho?ng 0->639, v? m?t di?m c� to? d? x,y cho ng?u nhi�n v?i m�u tr?ng */
    i++;
  }
  getch();
  int mau=getpixel(100,100); /* l?y m�u c?a di?m ?nh tr�n m�n h�nh t?i v? tr� c� to? d? (100,100) */
  closegraph();
  printf(�mau cua diem anh tai vi tri co toa do (100,100) la : %d�,mau);
  getch();
}
