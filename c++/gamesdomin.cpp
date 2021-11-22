#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<process.h>
#include<iostream>
#include<dos.h>
//**********Tao Menu*****************************************/
#define pixTOrc(x) (8*(x-1))
#define INC 5
#define ROW 15
#define COL 8
#define MAXITEM 5
int Start();
 
typedef char option[15];
option mainMenu[]= {
"NEW GAME.",
"OPEN GAME.",
"SAVE",
"ABOUT ME",
"CLOSE"
};
 
void normalvideo(int x,int y,char *str)
{
x=pixTOrc(x);
y=pixTOrc(y);
outtextxy(x,y,str);
}
 
void reversevideo(int x,int y,char *str)
{
x=pixTOrc(x);
y=pixTOrc(y);
setcolor(YELLOW);
sound(400);
delay(100);
nosound();
outtextxy(x,y,str);
setcolor(WHITE);
sound(500);
delay(100);
nosound();
}
 
char menu()
{
settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
setcolor(WHITE);
int i,done;
for(i = 1; i < MAXITEM; i++)
normalvideo(COL, (i*INC)+ROW, mainMenu[i]);
 
reversevideo(COL,ROW, mainMenu[0]);
i = done = 0;
do
{
 
setfillstyle(SOLID_FILL,BLUE);
settextstyle(SMALL_FONT,HORIZ_DIR,5);
bar(pixTOrc(2),pixTOrc(52.5),pixTOrc(75),pixTOrc(5 5));
setcolor(LIGHTCYAN);
switch(i)
{
case 0 : outtextxy(pixTOrc(5),pixTOrc(52.75),"New --> New game: Snake 7.0, Mine 5.0, Tertriss 1.0, PingPong 2.0...v.v..");
break;
case 1 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Open --> Chuong trinh gia lap playtion. Hien nay muc nay minh da xoa. ");
break;
case 2 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Save --> Save file game. Hien nay muc nay minh da xoa.");
break;
case 3 : outtextxy(pixTOrc(5),pixTOrc(52.75),"About Me --> Nguoi viet: Luu Huynh Chau Pha 03CT1C DH KHTN");
break;
case 4 : outtextxy(pixTOrc(5),pixTOrc(52.75),"Close the Program --> See you again !!!!!!!!!!!");
break;
}
 
setcolor(WHITE);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 
int key = getch();
switch (key)
{
 
case 00:
key = getch();
switch (key)
{
case 72:
normalvideo(COL, (i*INC)+ROW, mainMenu[i]);
i--;
if (i == -1)
i = MAXITEM-1;
reversevideo(COL,(i*INC)+ROW,mainMenu[i]);
break;
case 80:
normalvideo(COL, (i*INC)+ROW, mainMenu[i]);
i++;
if (i == MAXITEM)
i = 0;
reversevideo(COL, (i*INC)+ROW, mainMenu[i]);
break;
}
break;
case 13:
done = 1;
}
 
}
while (!done);
return(i+49);
}
 
void advertise(){
setcolor(BLUE);
outtextxy(pixTOrc(30),pixTOrc(20),"LuuHuynhChauPha 03CT1C");
outtextxy(pixTOrc(30),pixTOrc(26),"ahp16122311@yah oo.co.uk");
setcolor(YELLOW);
}
 
int control_menu()
{ int flag=0;
char choice;
do
{
choice = menu();
switch (choice)
{
case '1': //New
setcolor(BLUE);
outtextxy(pixTOrc(40),pixTOrc(15),"...New...");
advertise();
getch();
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(pixTOrc(28),pixTOrc(14),pixTOrc(80),pixTOrc(50 ));
advertise();
flag=1;
settextstyle(0,0,0);
//Start();
goto out;
 
 
case '2': //Open
setcolor(BLUE);
outtextxy(pixTOrc(40),pixTOrc(15),"...Open...");
advertise();
getch();
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(pixTOrc(28),pixTOrc(14),pixTOrc(80),pixTOrc(50 ));
advertise();
break;
 
case '3': //Save
setcolor(BLUE);
outtextxy(pixTOrc(40),pixTOrc(15),"...Save...");
advertise();
 
getch();
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(pixTOrc(28),pixTOrc(14),pixTOrc(80),pixTOrc(50 ));
advertise();
break;
 
case '4': //Modify the status of item in inventory
setcolor(BLUE);
outtextxy(pixTOrc(40),pixTOrc(15),"...About Me...");
advertise();
getch();
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(pixTOrc(28),pixTOrc(14),pixTOrc(80),pixTOrc(50 ));
advertise();
settextstyle(0,0,0);
flag=3;
goto out;
 
case '5': //Close the program
setcolor(BLUE);
outtextxy(pixTOrc(40),pixTOrc(15),"...CLOSE...");
advertise();
delay(1000);
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(pixTOrc(28),pixTOrc(14),pixTOrc(80),pixTOrc(50 ));
advertise();
flag=2;
cleardevice();
outtextxy(getmaxx()/2-70,getmaxy()/2-70,"See you again !!!");
delay(2000);
goto out;
}
 
} while (choice != MAXITEM);
out:
return flag;
}
 
 
 
int Menu()
{
int i,j,k;
settextjustify(0,2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(0,0,640,480);
 
setcolor(DARKGRAY);
rectangle(0,0,639,480);
rectangle(1,1,638,479);
setcolor(BLACK);
rectangle(2,1,637,478);
rectangle(3,1,636,477);
 
settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
setcolor(BLUE);
outtextxy(pixTOrc(8),pixTOrc(2),"MENU -->> Ngay 02, Thang 03, Nam 2004");
setfillstyle(HATCH_FILL,DARKGRAY);
for(i=15,j=70;i<40||j>40;i++,j--)
{
bar(pixTOrc(8),pixTOrc(7),pixTOrc(i),pixTOrc(7.5)) ;
delay(10);
bar(pixTOrc(j),pixTOrc(7),pixTOrc(70),pixTOrc(7.5) );
delay(20);
}
 
bar(pixTOrc(7),pixTOrc(14),pixTOrc(25),pixTOrc(50) );
k=control_menu();
return k;
}
 
//--------Important Functions----------------------------
void Initgraph()
{ int gdriver=DETECT,gmode,errorcode;
initgraph(&gdriver,&gmode,"c:/borlandc/bgi");
errorcode=graphresult();
if(errorcode!=grOk)
{ cout<<"Xin chao ban!!! That tiec, ban da khong de dung vi tri\
tap tin c:/borlandc/bgi/evavga.bgi";
cout<<"\n\nChuong trinh se thoat ra...Mong ban quay lai...";
cout<<"\n\nNhan mot phim bat ky de thoat ra....Thank you.";
getch();
exit(1);
}
}
void Closegraph()
{ closegraph();
}
//*********************************************/
 
struct MOUSE
{
int mouse_trang_thai;
int mouse_x;
int mouse_y;
};
int mouse_reset(void);
void Khoi_dong_mouse(void);
void Thoat_mouse(void);
void Trang_thai_mouse(MOUSE &mouse);
void mouse_horizontal_range(int xmin, int xmax);
void mouse_vertical_range(int ymin, int ymax);
/*----------------------------------------------------------------------*/
int mouse_reset(void)
{
_AX=0;
geninterrupt(0x33);
return(_AX);
}
 
/*----------------------------------------------------------------------*/
 
void Khoi_dong_mouse(void)
{
_AX=1;
geninterrupt(0x33);
}
 
/*----------------------------------------------------------------------*/
 
void Thoat_mouse(void)
{
_AX=2;
geninterrupt(0x33);
}
 
/*----------------------------------------------------------------------*/
 
void Trang_thai_mouse(MOUSE &mouse)
{
_AX=3;
geninterrupt(0x33);
mouse.mouse_trang_thai=_BX;
mouse.mouse_x=_CX;
mouse.mouse_y=_DX;
} /* Trang_thai_mouse */
 
/*----------------------------------------------------------------------*/
 
void Chieu_doc_mouse(int xmin, int xmax)
{
_AX=7;
_CX=xmin;
_DX=xmax;
geninterrupt(0x33);
}
 
/*----------------------------------------------------------------------*/
 
void Chieu_ngang_mouse(int ymin, int ymax)
{
_AX=8;
_CX=ymin;
_DX=ymax;
geninterrupt(0x33);
} /* Chieu_ngang_mouse */
#define YES 1
#define NO 0
 
#define dx 15 /* X pixels by square */
#define dx 15 /* Y pixels by square */
 
#define DEFI_dong 30 /* Default number of squares */
#define DEFI_cot 28
 
#define MINE 255-'0' /* So that when it prints, it prints char 0xff */
 
#define STSQUARE struct PHAN_TU
 
STSQUARE {
unsigned char trang_thai_phantu; /* Number of mines in the surround squares */
unsigned char open; /* Square is open */
unsigned char press; /* Square is pressed */
unsigned char mark; /* Square is marked */
} *phan_tu;
 
#define DEFINE_Trang_thai(x,y) (phan_tu+(x)*ti.cot_max+(y))->trang_thai_phantu
#define DEFINE_Open(x,y) (phan_tu+(x)*ti.cot_max+(y))->open
#define DEFINE_Press(x,y) (phan_tu+(x)*ti.cot_max+(y))->press
#define DEFINE_Mark(x,y) (phan_tu+(x)*ti.cot_max+(y))->mark
struct Ti
{
int toa_do_x_tren, /* Offset of first pixel X */
toa_do_y_tren,
dong_max, /* Number of squares in X */
cot_max,
so_mine, /* Mines discovered */
initmines, /* Number of initial mines */
sqclosed, /* Squares still closed */
maxy; /* Max. number of y pixels of the screen */
};
void Graph_init(void);
void Read_(Ti &ti);
void Set_mines(Ti &ti,int nminas);
void Set_square(Ti ti,int x, int y, int status);
void Mouse_set(Ti ti);
void Draw_squares(Ti ti);
int Do_all(Ti &ti,MOUSE &mouse);
void Blow_up(Ti ti);
void Open_square(Ti ti,int x, int y);
int Open_near_squares(Ti ti,int x, int y);
/************************************************** *******************/
void About_me()
{ cleardevice();
settextstyle(2,HORIZ_DIR,5);
outtextxy(100,100,"Tang cac ban 27/03/2004");
setcolor(12);
outtextxy(20,200,"Chuong trinh nay, Pha xin tang rieng cho:");
setcolor(11);
outtextxy(50,210,"Cac ban tren forum: is-edu.");
setcolor(12);
outtextxy(70,220,"Chuc cac ban mot nam moi vui ve.");
setcolor(15);
outtextxy(200,300,"Luu Huynh Chau Pha 03CT1C");
getch();
}
/***************** Main Function. ************************************************** *****/
void main(void)
{ int flag=0;
if (!mouse_reset())
{
cputs(" ERROR: Minh khong tim thay thiet bi chuot trong may ban.\r\n");
exit(2);
}
Initgraph();
do
{
 
if(flag==1) Start();
if(flag==3) About_me();
}while( (flag=Menu())!=2 );
Closegraph();
}
/************************************************** ****/
int Start()
{ MOUSE mouse;
Ti ti;
Read_(ti);
Mouse_set(ti);
do {
randomize();
cleardevice();
Set_mines(ti,ti.so_mine=ti.initmines);
Khoi_dong_mouse();
Draw_squares(ti);
}
while (Do_all(ti,mouse) != '\x1b');
delete [] phan_tu;
return 0;
}
 
/*----------------------------------------------------------------------*/
 
void Read_(Ti &ti)
{
int x, y, m;
cleardevice();
setfillstyle(SOLID_FILL,LIGHTGRAY);
settextjustify(LEFT_TEXT,CENTER_TEXT);
x=y=m=0;
ti.maxy=getmaxy();
ti.toa_do_x_tren=100;
ti.dong_max=DEFI_dong;
if (ti.maxy==479) {
ti.toa_do_y_tren=30;
ti.cot_max=DEFI_cot;
}
else {
ti.toa_do_y_tren=25;
ti.cot_max=20;
}
if (x>0 && x<ti.dong_max)
ti.dong_max=x;
if (y>0 && y<ti.cot_max) {
ti.toa_do_y_tren+=((ti.cot_max-y)*dx)>>1;
ti.cot_max=y;
}
ti.initmines= m ? m : ti.dong_max*ti.cot_max*4/25; /* There are about 16% of mines */
if ((phan_tu=new PHAN_TU[ti.dong_max*ti.cot_max])==NULL) {
closegraph();
cputs("ERROR: Not enought memory");
exit(3);
}
} /* Read_param */
 
/*----------------------------------------------------------------------*/
 
void Set_mines(Ti &ti,int nminas)
{
STSQUARE *p;
int i, x, y, a, b;
 
ti.sqclosed=ti.dong_max*ti.cot_max-nminas;
p=phan_tu;
for (i=(ti.dong_max)*(ti.cot_max); i>0; i--, p++)
p->trang_thai_phantu = p->open = p->press = p->mark = NO;
 
for (i=nminas; i>0; i--)
{
while (DEFINE_Trang_thai(x=random(ti.dong_max), y=random(ti.cot_max)) == MINE);
DEFINE_Trang_thai(x,y)=MINE;
}
for(x=0;x<ti.dong_max;x++)
for(y=0;y<ti.cot_max;y++)
{ if(DEFINE_Trang_thai(x,y)==MINE)
{ a=x-1;
b=y-1;
if(a>=0&&b>=0&&a<ti.dong_max&&b<ti.cot_max&&DEFINE _Trang_thai(a,b)!=MINE)
DEFINE_Trang_thai(a,b)+=1;
b=y;
if(a>=0&&b>=0&&a<ti.dong_max&&b<ti.cot_max&&DEFINE _Trang_thai(a,b)!=MINE)
DEFINE_Trang_thai(a,b)+=1;
b=y+1;
if(a>=0&&b>=0&&a<ti.dong_max&&b<ti.cot_max&&DEFINE _Trang_thai(a,b)!=MINE)
DEFINE_Trang_thai(a,b)+=1;
a=x;
b=y-1;
if(a>=0&&b>=0&&a<ti.dong_max&&b<ti.cot_max&&DEFINE _Trang_thai(a,b)!=MINE)
DEFINE_Trang_thai(a,b)+=1;
a=x;
b=y+1;
if(a>=0&&b>=0&&a<ti.dong_max&&b<ti.cot_max&&DEFINE _Trang_thai(a,b)!=MINE)
DEFINE_Trang_thai(a,b)+=1;
a=x+1;
b=y-1;
if(a>=0&&b>=0&&a<ti.dong_max&&b<ti.cot_max&&DEFINE _Trang_thai(a,b)!=MINE)
DEFINE_Trang_thai(a,b)+=1;
b=y;
if(a>=0&&b>=0&&a<ti.dong_max&&b<ti.cot_max&&DEFINE _Trang_thai(a,b)!=MINE)
DEFINE_Trang_thai(a,b)+=1;
b=y+1;
if(a>=0&&b>=0&&a<ti.dong_max&&b<ti.cot_max&&DEFINE _Trang_thai(a,b)!=MINE)
DEFINE_Trang_thai(a,b)+=1;
}
}
} /* Set_mines */
 
/*----------------------------------------------------------------------*/
 
/*
If status=1 then draw the square up, if it's 0 then draw it down
*/
void Set_square(Ti ti,int x, int y, int status)
{
int x_left, x_right, y_top, y_bottom;
 
Thoat_mouse();
x_left=ti.toa_do_x_tren+dx*x;
x_right=x_left+dx-1;
y_top=ti.toa_do_y_tren+dx*y;
y_bottom=y_top+dx-1;
 
setfillstyle(SOLID_FILL, LIGHTGRAY);
bar(x_left, y_top, x_right, y_bottom);
if (status) {
setcolor(WHITE);
line(x_left,y_top,x_left,y_bottom-1);
line(x_left,y_top,x_right-1,y_top);
setcolor(DARKGRAY);
line(x_right,y_bottom,x_left,y_bottom);
line(x_right,y_bottom,x_right,y_top);
switch (DEFINE_Mark(x,y)) {
case 2 : setfillstyle(SOLID_FILL, LIGHTBLUE);
setcolor(LIGHTBLUE);
break;
case 1 : setfillstyle(SOLID_FILL, LIGHTRED);
setcolor(LIGHTRED);
break;
default: setcolor(LIGHTGRAY);
}
fillellipse(ti.toa_do_x_tren+dx*x+dx/2, ti.toa_do_y_tren+dx*y+dx/2, 3, 3);
switch (DEFINE_Mark(x,y)) {
case 2 :
case 1 : setfillstyle(SOLID_FILL, YELLOW);
setcolor(YELLOW);
fillellipse(ti.toa_do_x_tren+dx*x+dx/2,ti.toa_do_y_tren+dx*y+dx/2, 1, 1);
}
}
else {
ti.sqclosed--;
setcolor(RED);
line(x_left,y_top,x_left,y_bottom);
line(x_left,y_top,x_right,y_top);
}
Khoi_dong_mouse();
} /* Set_square */
 
/*----------------------------------------------------------------------*/
 
void Mouse_set(Ti ti)
{
Chieu_doc_mouse(ti.toa_do_x_tren, ti.toa_do_x_tren+dx*ti.dong_max-3);
Chieu_ngang_mouse(ti.toa_do_y_tren, ti.toa_do_y_tren+dx*ti.cot_max-3);
} /* Mouse_set */
 
/*----------------------------------------------------------------------*/
 
void Draw_squares(Ti ti)
{
int x, y;
Thoat_mouse();
 
setcolor(15);
setfillstyle(3,1);
bar(0,0,getmaxx(),getmaxy());
setfillstyle(2,14);
bar(0,getmaxy()-15,getmaxx(),getmaxy());
outtextxy(20,20,"Luu Huynh Chau Pha 03CT1C...Ngay lam xong: 23/01/2004");
setcolor(15);
outtextxy(getmaxx()-300,getmaxy()-23,"Chuc cac ban nam moi vui ve..2004");
 
for (x=0; x<ti.dong_max; x++)
for (y=0; y<ti.cot_max; y++)
Set_square(ti,x,y,1);
Khoi_dong_mouse();
} /* Draw_squares */
 
/*----------------------------------------------------------------------*/
 
/*
Here we do all the job
*/
int Do_all(Ti &ti,MOUSE &mouse)
{
int x, y, xant=-1, yant, mlstant, mrstant, cminasant=0, ttrans, tant=0;
long tst, tact;
char str[] ="xxxxx: 0000",
blk[] ="ллллллллллл";
 
Khoi_dong_mouse();
time(&tst);
while (!kbhit()) {
if (!ti.sqclosed && !mouse.mouse_trang_thai) { /* All mines discovered */
settextjustify(LEFT_TEXT, CENTER_TEXT);
setcolor(BLACK);
outtextxy(0, ti.maxy/2-10, blk);
sprintf(str,"Mines: 0");
setcolor(LIGHTRED);
outtextxy(0, ti.maxy/2-10, str);
settextjustify(LEFT_TEXT, CENTER_TEXT);
setcolor(BLACK);
outtextxy(0, ti.maxy/2+10, blk);
sprintf(str," Time: %4d",ttrans);
setcolor(LIGHTGREEN);
outtextxy(0, ti.maxy/2+10, str);
for (x=ti.dong_max-1; x>=0; x--)
for (y=ti.cot_max-1; y>=0; y--)
if (DEFINE_Trang_thai(x,y)==MINE) {
DEFINE_Mark(x,y)=1;
Set_square(ti,x,y,1);
}
break;
}
if (cminasant != ti.so_mine) { /* Update Mines: */
cminasant=ti.so_mine;
settextjustify(LEFT_TEXT, CENTER_TEXT);
setcolor(BLACK);
outtextxy(0, ti.maxy/2-10, blk);
sprintf(str,"Mines: %4d",ti.so_mine);
setcolor(LIGHTRED);
outtextxy(0, ti.maxy/2-10, str);
}
if (tant != (ttrans=(int)(time(&tact)-tst))) { /* Update Time: */
tant=ttrans;
settextjustify(LEFT_TEXT, CENTER_TEXT);
setcolor(BLACK);
outtextxy(0, ti.maxy/2+10, blk);
sprintf(str," Time: %4d",ttrans);
setcolor(LIGHTRED);
outtextxy(0, ti.maxy/2+10, str);
}
Trang_thai_mouse(mouse);
mouse.mouse_trang_thai&=3;
x=(mouse.mouse_x-ti.toa_do_x_tren)/dx;
y=(mouse.mouse_y-ti.toa_do_y_tren)/dx;
if (xant == -1) {
xant=x;
yant=y;
}
if (x!=xant || y!=yant) { /* Position change */
if (DEFINE_Press(xant,yant) && !DEFINE_Open(xant,yant)) {
DEFINE_Press(xant,yant)=NO;
Set_square(ti,xant,yant,1);
}
xant=x;
yant=y;
}
if (!mouse.mouse_trang_thai)
mlstant=mrstant=0;
if ((mouse.mouse_trang_thai == 2) &&
!DEFINE_Open(x,y) &&
mlstant!=mouse.mouse_trang_thai) { /* Right button pressed */
mlstant=mouse.mouse_trang_thai;
Thoat_mouse();
switch (DEFINE_Mark(x,y)=(DEFINE_Mark(x,y)+1) % 3) {
case 1 : ti.so_mine--; break;
case 2 : ti.so_mine++;
}
Set_square(ti,x,y,1);
Khoi_dong_mouse();
}
else if (mouse.mouse_trang_thai==1 && /* Left button pressed */
!DEFINE_Open(x,y) &&
!DEFINE_Press(x,y) && /* And square not pressed */
DEFINE_Mark(x,y)!=1) {
DEFINE_Press(x,y)=YES;
Set_square(ti,x,y,0);
}
else if (!mouse.mouse_trang_thai && /* Left button released */
!DEFINE_Open(x,y) &&
DEFINE_Press(x,y) &&
DEFINE_Mark(x,y)!=1) { /* Open the square */
if (DEFINE_Trang_thai(x,y) == MINE) {
Blow_up(ti);
break;
}
else
Open_square(ti,x,y);
}
else if (mouse.mouse_trang_thai==3 &&
DEFINE_Open(x,y) &&
mrstant!=mouse.mouse_trang_thai) { /* Open near squares */
mrstant=mouse.mouse_trang_thai;
if (Open_near_squares(ti,x,y) == YES) {
Blow_up(ti);
break;
}
}
}
Thoat_mouse();
return (getch());
} /* Do_all */
 
/*----------------------------------------------------------------------*/
 
void Blow_up(Ti ti)
{
int x, y, x_left, y_top, x_right, y_bottom;
 
Thoat_mouse();
for (x=0; x<ti.dong_max; x++) {
for (y=0; y<ti.cot_max; y++) {
if (DEFINE_Trang_thai(x,y) == MINE) {
settextjustify(CENTER_TEXT, CENTER_TEXT);
setcolor(CYAN);
outtextxy(ti.toa_do_x_tren+dx*x+dx/2-1, ti.toa_do_y_tren+dx*y+dx/2, "л");
setcolor(BLACK);
outtextxy(ti.toa_do_x_tren+dx*x+dx/2, ti.toa_do_y_tren+dx*y+dx/2+1, "*");
}
else if (DEFINE_Mark(x,y)==1) {
setcolor(YELLOW);
x_left=ti.toa_do_x_tren+dx*x;
x_right=x_left+dx-1;
y_top=ti.toa_do_y_tren+dx*y;
y_bottom=y_top+dx-1;
line(x_left,y_top,x_right,y_bottom);
line(x_left,y_bottom,x_right,y_top);
}
}
}
} /* Blow_up */
 
/*----------------------------------------------------------------------*/
 
void Open_square(Ti ti,int x, int y)
{
char num[2]="0";
int a, b, c;
 
DEFINE_Open(x,y)=YES;
if ((num[0]=DEFINE_Trang_thai(x,y)) != 0) {
num[0]+='0';
switch(num[0]) {
case '1' : c=LIGHTBLUE; break;
case '2' : c=LIGHTGREEN; break;
case '3' : c=YELLOW; break;
case '4' : c=LIGHTRED; break;
default : c=LIGHTMAGENTA;
}
Thoat_mouse();
setcolor(c);
settextjustify(CENTER_TEXT, CENTER_TEXT);
outtextxy(ti.toa_do_x_tren+dx*x+dx/2, ti.toa_do_y_tren+dx*y+dx/2+1, num);
Khoi_dong_mouse();
}
else { /* Open near squares if the current number is 0 */
a=x-1;
b=y-1;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
b++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
a-=2;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
b++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
}
} /* Open_square */
 
/*----------------------------------------------------------------------*/
 
/*
Open the sorrounded squares. Returns != 0 if I activated a mine
*/
int Open_near_squares(Ti ti,int x, int y)
{
int a, b, suma=0;
 
a=x-1;
b=y-1;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && DEFINE_Mark(a,b)==1)
suma++;
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && DEFINE_Mark(a,b)==1)
suma++;
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && DEFINE_Mark(a,b)==1)
suma++;
b++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && DEFINE_Mark(a,b)==1)
suma++;
a-=2;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && DEFINE_Mark(a,b)==1)
suma++;
b++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && DEFINE_Mark(a,b)==1)
suma++;
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && DEFINE_Mark(a,b)==1)
suma++;
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && DEFINE_Mark(a,b)==1)
suma++;
if (suma == DEFINE_Trang_thai(x,y)) {
suma=0;
a=x-1;
b=y-1;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
suma|=(DEFINE_Trang_thai(a,b)==MINE);
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
suma|=(DEFINE_Trang_thai(a,b)==MINE);
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
suma|=(DEFINE_Trang_thai(a,b)==MINE);
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
b++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
suma|=(DEFINE_Trang_thai(a,b)==MINE);
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
a-=2;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
suma|=(DEFINE_Trang_thai(a,b)==MINE);
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
b++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
suma|=(DEFINE_Trang_thai(a,b)==MINE);
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
suma|=(DEFINE_Trang_thai(a,b)==MINE);
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
a++;
if (a>=0 && b>=0 && a<ti.dong_max && b<ti.cot_max && !DEFINE_Open(a,b) && DEFINE_Mark(a,b)!=1) {
suma|=(DEFINE_Trang_thai(a,b)==MINE);
Set_square(ti,a,b,0);
Open_square(ti,a,b);
}
return (suma);
}
else
return 0;
} /* Open_near_squares */
