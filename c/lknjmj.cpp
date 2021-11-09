int docFile(SV a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout << "Chuan bi doc file: "; puts(fileName);
    // doc thong tin sinh vien
    while (fscanf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", &a[i].id, &a[i].ten, 
            &a[i].gioiTinh, &a[i].tuoi, &a[i].diemToan, &a[i].diemLy, &a[i].diemHoa, 
            &a[i].diemTB, &a[i].hocluc) != EOF) {
       i++;
       cout << " Doc ban ghi thu: " << i << endl;
    }
    cout << " So luong sinh vien co san trong file la: " << i << endl;
    cout << endl;
    fclose (fp);
    // tra ve so luong sinh vien duoc doc tu file
    return i;
}
 
void ghiFile(SV a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%30s%5s%5d%10f%10f%10f%10f%10s\n", a[i].id, a[i].ten,a[i].gioiTinh, 
            a[i].tuoi, a[i].diemToan, a[i].diemLy, a[i].diemHoa, a[i].diemTB, a[i].hocluc);
    }
    fclose (fp);
}
