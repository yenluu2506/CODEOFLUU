#include <iostream>
using namespace std;

class Media {
    protected:
        string Ten;
        long GiaBan;
    public:
        Media();
        Media(string Ten, long GiaBan);
        void Nhap();
        void Xuat();
};

class Book : public Media {
    private:
        int SoTrang;
        string TacGia;
    public:
        Book();
        void _Nhap();
        void _Xuat();
};

class Video : public Media {
    private:
        int gio, phut, giay;
    public:
        Video();
        void _Nhap();
        void _Xuat();
};

//Media
Media::Media() {
    this->Ten = "";
    this->GiaBan = 0;
}
Media::Media(string Ten, long GiaBan) {
    this->Ten = Ten;
    this->GiaBan = GiaBan;
}

void Media::Nhap() {
    cout << "\tNhap ten: ";
    cin.ignore();
    getline(cin, Ten);
    cout << "\tNhap gia ban: ";
    cin >> GiaBan;
}

void Media::Xuat() {
    cout << "\tTen: " << Ten << endl;
    cout << "\tGia ban: " << GiaBan << endl;
}

//Book
Book::Book() {
    SoTrang = 0;
    TacGia = "";
}

void Book::_Nhap() {
    Media::Nhap();
    cout << "\tNhap so trang: ";
    cin >> SoTrang;
    cout << "\tNhap tac gia: ";
    cin.ignore();
    getline(cin, TacGia);
}

void Book::_Xuat() {
    Media::Xuat();
    cout << "\tSo trang: " << SoTrang << endl;
    cout << "\tTac gia: " << TacGia << endl;
}

//Video
Video::Video() {
    this->gio = this->phut = this->giay = 0;
}

void Video::_Nhap() {
    Media::Nhap();
    cout << "\tNhap thoi gian chay: ";
    cin >> gio >> phut >> giay;
}

void Video::_Xuat() {
    Media::Xuat();
    cout << "\tThoi gian chay: " << gio << "h" << phut << "p" << giay << "s" << endl;
}

int main() {
    int n, m;
    cout << "Nhap so luong sach: ";
    cin >> n;
    Book *b = new Book[n];
    for(int i=0; i<n; i++) {
        cout << "Nhap thong tin sach " << i+1 << ": " << endl;
        b[i]._Nhap();
    }
    cout << "\n**     Thong tin sach     **" << endl;
    for(int i=0; i<n; i++) {    
        cout << "Thong tin sach " << i+1 << ": " << endl;
        b[i]._Xuat();
    }
    cout << "\n-----------------------------------\n\n";
    cout << "Nhap so luong video: ";
    cin >> m;
    Video *v = new Video[m];
    for(int i=0; i<m; i++){
        cout <<"Nhap thong tin video " << i+1 << ": " << endl;
        v[i]._Nhap();
    }
    cout << "\n**     Thong tin video     **" << endl;
    for(int i=0; i<m; i++) {
        cout << "Thong tin video " << i+1 << ": " << endl;
        v[i]._Xuat();
    }
}
