//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

#include <iostream>
using namespace std;

void inputArray(int *A, int &n){
    for(int i=0; i<n; i++){
        cout << "Nhap phan tu thu " << i+1<< " : ";
        cin >> *(A+i);
    }
}
void printArray(int *A, int n){
    for(int i=0;i<n;i++)
        cout << *(A+i)<< " ";  
}
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}


void BubbleSort(int *A, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(*(A+i)>*(A+j+1)){
                swap (*(A+i), *(A+j+1));
            }
        }
    }
}
void insertSort(int *A, int n){
    for(int i=1; i<n; i++){
        int x = *(A+i);
        int j = i-1;
        while (j>=0 && *(A+j)>x){
            *(A+j+1) = *(A+j);
            j--;
        }
        *(A+j+1) = x;
    }
}

void selectionSort(int *A, int n){
    for(int i=0; i<n-1; i++){
        int minV = *(A+i), pMin = i;
        for(int j = i+1; j<n; j++){
            if(minV > *(A+j)){
                minV = *(A+j);
                pMin = j;
            }
            if(i!=pMin){
                swap(*(A+i), *(A+pMin));
            }
        }
    } 
}

void QuickSort(int *A, int left, int right){
    int x = *(A+left + right)/2;
    int i = left, j=right;
    do{
        while (*(A+i)<x) i++;
        while (*(A+j)>x) j--;
        if(i<=j){
            swap(*(A+i), *(A+j));
            i++;
            j--;
        }
    } while (i<j);
    
    if(left<j){
        QuickSort(A, left, j);
    }

    if(right>i){
        QuickSort(A, i, right);
    }
}

//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

int binarySearch(int *A, int n, int key){
    int left = 0, right = n-1, mid;
    while(left<=right){
        mid = (left+right)/2;
        if(*(A+mid)==key)
            return mid;
        if(*(A+mid)<key)
            left = mid +1;
        else
            right = mid -1;
    }
    return -1;
}

int linearSearch(int *A, int n, int key){
    for(int i=0; i<n; i++){
        if(*(A+i)==key)
            return i;
    }
    return -1;
}

//Ho va Ten: Bui Thi Yen Luu
//MSSV: 6151071011
//Ngay sinh: 25/06/2002
//Email: 6151071011@st.utc2.edu.vn

int main()
{
	cout << "Nhap so luong phan tu: ";
	int n;
	cin >> n;
	int *A = new int[n];
    int left, right;
    int key;
    inputArray(A, n);
    cout<< "Mang da nhap la: ";
    printArray(A, n);
    cout<< endl;
    cout<< "Bubble Sort: ";
    BubbleSort(A, n);
    printArray(A,n);
    cout<< endl;
    cout << "Insert Sort: ";
    insertSort(A, n);
    printArray(A, n);
    cout<< endl;
    cout<< "Selection Sort: ";
    selectionSort(A, n);
    printArray(A, n);
    cout << endl;
    cout << "Quick Sort: ";
    QuickSort(A, left, right);
    printArray(A, n);
    cout << endl;
    cout << "Nhap gia tri can tim kiem: ";
    cin >> key;
    int v = binarySearch(A, n, key);
    cout << "Binary Search: " << v << endl;
    int t = linearSearch(A, n, key);
    cout << "Linear Search: " << t << endl;
	delete[] A;

	return 0;
}
