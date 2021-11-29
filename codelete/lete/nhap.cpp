// void Dormitory::capnhat(){
//     int i=1, Luachon, n;
//     int found = 0;
//     string msv;
//         inmenu1();
//          while (i)
//     {
//         cout << "\n \n   Nhap lua chon: ";
//         cin >> Luachon;
//         Person *p;
//         switch (Luachon)
//         {
//         case 1:  
// 		  {
//             system("cls");
//         	// inkhung();
//         	inmenu1();
//             for(int i=0; i<n; i++){
//                 strcpy(msv, p[i].getId())
//                 if(strstr(strupr(msv), strupr(getId()))){
//                     found = 1;
//                     cout << "Cap nhat thong tin co ma sinh vien "<< getId() << ": ";
//                     capnhatSV(p[i]);
//                     break;
//                 }
//             }
//             if(found == 0){
//                 cout << "Sinh vien co ma id "<< getId() << " khong ton tai !!"<< endl;
//             }
            
//             break;
//         }
//         case 2:
//         {   
//             system("cls");
//         	// inkhung();
//             inmenu1();
//         	// cout<<"\n\n\n Nhap so luong ban quan ly: ";
//             // int b= numberManage(n);
//             // for(int i=0; i<b; i++){
//             //     cout << "Quan li thu " <<i+1<<":";
//             //     p = new Manage[n];
//             //     p->Nhap(i);
//             //     p->selection(false);
//             //     list_person.push_back(p);
//             // }
// 			// break;
            
//         }
//         case 3:
//         {
//             i--;
//             break;
//         }
//         default:
//         {
//             cout << "Lua chon khong hop le!!!" << endl;
//             break;
//         }
//         }
//     }
// }

// void Dormitory::xuatcapnhat(){   
//     system("cls");
// 	// inkhung();
//     for (int i = 0; i < list_person.size(); i++){
//     	cout << "xuat sinh vien thu "<< i+1<<":";
//         if (list_person[i]->selection() == true)
//             list_person[i]->Xuat(i);
        
//     }
//     for (int i = 0; i < list_person.size(); i++){
// 		cout << "xuat quan ly thu "<< i+1<<":";
// 		if (list_person[i]->selection() == false)
//             list_person[i]->Xuat(i);
        
//     }
// }