#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>

struct ToaDo{
 int _x;
 int _y;

 ToaDo(int x, int y);
};

ToaDo::ToaDo(int x, int y){
 this->_x = x;
 this->_y = y;
}

using namespace std;

#define YMAX 50
#define XMAX 50
//Row 0 = column 0 = 10
#define X0 10
#define Y0 10
#define CHAR 219
#define BOOM 100

void resizeConsole(int width, int height);
void textcolor(int x);
void gotoxy(int x, int y);
void XoaManHinh();

void setScreen();
void init2D(int** arr, int c, int r);

void randBoom(int** arr, int c, int r);
void setCell(int** arr, int c, int r);
int countBoom(int** arr, int x, int y, int col, int row);
void creatMapBoom(int **arr, int numCol, int numRow);

inline void playGame(ToaDo * pnt, ToaDo * pntArr, int numCol, int numRow, int** arr, int* boomNotRemoved, int* realBomNotRemoved);
void covertCoordToArr(ToaDo * pnt, const ToaDo * pntArr);
void movePointer(ToaDo * pnt, ToaDo * pntArr, int numCol, int numRow);
void updateBoomRemove(const int* bomNotRemoved);

void printArr(int** Arr, int* numCol, int* numRow){
 for(int i = 0; i < *numCol ; i++){
  for(int j = 0; j < *numRow ; j++){
   if(Arr[i][j] == -1) cout << "* ";
   else cout << Arr[i][j] << " ";
  }
  cout << endl;
 }
}

int main(){
 
    int bomNotRemoved = BOOM;
    int realBomNotRemoved = BOOM;
   
 int numCol = XMAX - X0 + 10;
 int numRow = YMAX - Y0 + 10;
 int **arr = new int*[numCol];

 for (int i = 0; i < numCol; i++){
  arr[i] = new int[numRow];
 }

 numCol -= 16;
 numRow -= 16;

 creatMapBoom(arr, numCol, numRow);
 ToaDo pnt(X0 + 3, Y0 + 3);
 ToaDo pntArr(0, 0);
 resizeConsole(600, 800);
 setScreen();
 //printArr(arr, &numCol, &numRow);

    updateBoomRemove(&bomNotRemoved);
 gotoxy(pnt._x, pnt._y);
 playGame(&pnt, &pntArr, numCol, numRow, arr, &bomNotRemoved, &realBomNotRemoved);


 _getch();
 return 0;
}

// Hàm thay d?i kích c? c?a khung cmd.
void resizeConsole(int width, int height)
{
 HWND console = GetConsoleWindow();
 RECT r;
 GetWindowRect(console, &r);
 MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
 HANDLE mau;
 mau = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(mau, x);
}

// Hàm d?ch chuy?n con tr? d?n t?a d? x, y.
void gotoxy(int x, int y)
{
 HANDLE hConsoleOutput;
 COORD Cursor_an_Pos = { x - 1, y - 1 };
 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn h?nh.
void XoaManHinh()
{
 HANDLE hOut;
 COORD Position;
 hOut = GetStdHandle(STD_OUTPUT_HANDLE);
 Position.X = 0;
 Position.Y = 0;
 SetConsoleCursorPosition(hOut, Position);
}

void setScreen(){
 resizeConsole(800, 600);
 for (int i = X0; i <= XMAX; i++){
  textcolor(14);
  gotoxy(i, Y0);
  cout << char(CHAR);
  gotoxy(i, YMAX);
  cout << char(CHAR);
 }

 for (int i = Y0; i <= YMAX; i++){
  textcolor(14);
  gotoxy(X0, i);
  cout << char(CHAR);
  gotoxy(XMAX, i);
  cout << char(CHAR);
 }

 for (int i = X0 + 3; i <= XMAX - 3; i++){
  for (int j = Y0 + 3; j <= YMAX - 3; j++){
   if (i % 2 == 0){
    if (j % 2 == 0){
     textcolor(8);
     gotoxy(i, j);
     cout << char(CHAR);
    }
    else{
     textcolor(5);
     gotoxy(i, j);
     cout << char(CHAR);
    }
   }
   else{
    if (j % 2 == 0){
     textcolor(5);
     gotoxy(i, j);
     cout << char(CHAR);
    }
    else{
     textcolor(8);
     gotoxy(i, j);
     cout << char(CHAR);
    }
   }
  }
 }

 textcolor(7);
}

void init2D(int** arr, int c, int r){
 for (int i = 0; i < c; i++){
  for (int j = 0; j < r; j++){
   arr[i][j] = 0;
  }
 }
}

void randBoom(int** arr, int c, int r){
 int boom = BOOM;
 int x, y;
 while (boom){
  do{
   x = rand() % c;
   y = rand() % r;
  } while (arr[x][y] != 0);
  arr[x][y] = -1; // Number -1 represent "boom" .
  boom--;
 }
}

void setCell(int** arr, int c, int r){
 for (int i = 0; i < c; i++){
  for (int j = 0; j < r; j++){
   if (arr[i][j] != -1){
    arr[i][j] = countBoom(arr, i, j, c, r);
   }
  }
 }
}

int countBoom(int** arr, int x, int y, int col, int row){
 int numBoom = 0;
 for (int i = -1; i <= 1; i++){
  for (int j = -1; j <= 1; j++){
   if ((i != 0 || j != 0) && 0 <= x + i && x + i < col && 0 <= y + j && y + j < row){
    if (arr[x + i][y + j] == -1){
     numBoom++;
    }
   }
  }
 }
 return numBoom;
}

void creatMapBoom(int **arr, int numCol, int numRow){
 init2D(arr, numCol, numRow);
 srand(time(NULL));
 randBoom(arr, numCol, numRow);
 setCell(arr, numCol, numRow);
}

 void movePointer(ToaDo * pnt, ToaDo * pntArr, int numCol, int numRow){
 
  if (GetAsyncKeyState(VK_LEFT)){
   if (pntArr->_y > 0){
    --(pntArr->_y);
    covertCoordToArr(pnt, pntArr);
    gotoxy(pnt->_x, pnt->_y);
   }
  }
  if (GetAsyncKeyState(VK_RIGHT)){
   if (pntArr->_y < numCol){
    ++(pntArr->_y);
    covertCoordToArr(pnt, pntArr);
    gotoxy(pnt->_x, pnt->_y);
   }
  }
  if (GetAsyncKeyState(VK_UP)){
   if (pntArr->_x > 0){
    --pntArr->_x;
    covertCoordToArr(pnt, pntArr);
    gotoxy(pnt->_x, pnt->_y);
   }
  }
  if (GetAsyncKeyState(VK_DOWN)){
   if (pntArr->_x < numRow){
    pntArr->_x++;
    covertCoordToArr(pnt, pntArr);
    gotoxy(pnt->_x, pnt->_y);
   }
  }
  
  Sleep(100);
}

void areaOpen(int** arr, const ToaDo* pnt, const ToaDo* pntArr, int numCol, int numRow);

void updateBoomRemove(const int* boomNotRemoved);

 void actionPointer(ToaDo * pnt, ToaDo * pntArr, int numCol, int numRow, int** arr
                         , int* bomNotRemoved, int* realBomNotRemoved){
  if (GetAsyncKeyState(VK_SPACE)){
   if (arr[pntArr->_x][pntArr->_y] == -1){
    cout << "*";
    gotoxy(65, 18);
    textcolor(14);
    cout << "Thua roi .";
    cin.ignore(1);
    exit(0);
   }
   else{
    if (/*arr[pntArr->_x][pntArr->_y] != 0 &&*/ arr[pntArr->_x][pntArr->_y] != 13){
      if(arr[pntArr->_x][pntArr->_y] == 0){
       gotoxy(pnt->_x, pnt->_y);
       cout << " ";
       arr[pntArr->_x][pntArr->_y] = 13;
       areaOpen(arr, pnt, pntArr, numCol, numRow);
       gotoxy(pnt->_x, pnt->_y);
      }
    }
    if(arr[pntArr->_x][pntArr->_y] != 0 && arr[pntArr->_x][pntArr->_y] != 15 // 15 is removed boom
           && arr[pntArr->_x][pntArr->_y] != 13){ // 13 is opened cell
       gotoxy(pnt->_x, pnt->_y);
        cout << arr[pntArr->_x][pntArr->_y];
        areaOpen(arr, pnt, pntArr, numCol, numRow);
        gotoxy(pnt->_x, pnt->_y);
      }
   }
  }
 
  if(GetAsyncKeyState(VK_BACK)){
   if(arr[pntArr->_x][pntArr->_y] != 13 && arr[pntArr->_x][pntArr->_y] != 15){
    if(arr[pntArr->_x][pntArr->_y] == -1){
     --(*realBomNotRemoved);
     //gotoxy(1, 1);
     //textcolor(12);
     //cout << "tt " << (*realBomNotRemoved);
     //Win
     if((*realBomNotRemoved) == 0){
           gotoxy(65, 18);
           textcolor(14);
           cout << "Thang ^^ .";
           cin.ignore(1);
           exit(0);
     }
    }
    gotoxy(pnt->_x, pnt->_y);
    textcolor(12);
    cout << char(CHAR);
    arr[pntArr->_x][pntArr->_y] = 15; // Removed Boom
    (*bomNotRemoved)--;
    updateBoomRemove(bomNotRemoved);
    gotoxy(pnt->_x, pnt->_y);
    textcolor(7);
   }
   //if()
  }

  Sleep(100);
 }

void covertCoordToArr(ToaDo * pnt, const ToaDo * pntArr){
 pnt->_x = X0 + 3 + pntArr->_y;
 pnt->_y = Y0 + 3 + pntArr->_x;
}

inline void playGame(ToaDo * pnt, ToaDo * pntArr, int numCol, int numRow, int** arr, int* boomNotRemoved, int* realBomNotRemoved){
 while (1){
  movePointer(pnt, pntArr, numCol, numRow);
  actionPointer(pnt, pntArr, numCol, numRow, arr, boomNotRemoved, realBomNotRemoved);

 }
  
}

void areaOpen(int** arr,const ToaDo* pnt,const ToaDo* pntArr, int numCol, int numRow){
 for(int i = -2; i <= 2; i++){
  for(int j = -2; j <= 2; j++){
   if(0 <= pntArr->_x + i && pntArr->_x + i < numCol &&
                     0 <= pntArr->_y + j && pntArr->_y + j < numRow){
                      if(arr[pntArr->_x + i][pntArr->_y + j] != 13 && arr[pntArr->_x + i][pntArr->_y + j] != 15
           && arr[pntArr->_x + i][pntArr->_y + j] != -1){
                       gotoxy(pnt->_x + j, pnt->_y + i);
                        if(arr[pntArr->_x + i][pntArr->_y + j] == 0) cout << " ";
                        else{
                         cout << (arr[pntArr->_x + i][pntArr->_y + j]);
         }
                        arr[pntArr->_x + i][pntArr->_y + j] = 13;
          }
    
   }
  }
 }
}

void updateBoomRemove(const int* boomNotRemoved){
 gotoxy(20, 5);
 cout << "BOOM : " << *boomNotRemoved;
}
