void ghiFile(struct SinhVien* ds, int slsv) {
	getchar();
	char fName[26];
	printf("Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "a");
	int i;
	for(i = 0; i < slsv; i++) {
		struct SinhVien sv = ds[i];
		fprintf(fOut, "%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
		sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.tuoi, sv.gioiTinh,
		sv.diem.toan, sv.diem.van, sv.diem.anh, sv.diem.tbc);
	}
	fclose(fOut);
}

void docFile(struct SinhVien* ds, int* slsv) {
	FILE* fOut = fopen("SV.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct SinhVien sv;
			fscanf(fOut, "%10d %10s %20[^\n] %10s %10d %10s %10f %10f %10f %10f\n",
			&sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, &sv.tuoi, sv.gioiTinh,
			&sv.diem.toan, &sv.diem.van, &sv.diem.anh, &sv.diem.tbc);
			
			ds[i++] = sv;
			if(feof(fOut)) { // thoat chuong trinh
				break;
			}
		}
	}
	
	fclose(fOut);
	*slsv = i;
}

for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
