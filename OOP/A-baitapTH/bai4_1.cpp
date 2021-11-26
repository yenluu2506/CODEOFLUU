#include <iostream>
#include <string>
using namespace std;

void input(string str[], int &n)
{
    cout<<"Nhap so luong chuoi: ";
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        cout<<"Nhap chuoi "<<i+1<<": "<<endl;
        getline(cin, str[i]);
    }
}
string findMax(string str[], int n)
{
    string max = str[0];
    for(int i=0; i<n; i++)
        if(str[i] > max)
           max = str[i];
    return max;
}
void output(string str[], int n)
{
    string max = findMax(str, n);
    cout<<"Gia tri lon nhat: "<<max<<endl;
}

int main()
{
    int n;
    string str[n];
    input(str, n);
    output(str, n);
    system("pause");
}