#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Sach{
	   char Ten[30];
	   char Tacgia[30];
	   int Nam;
};

typedef struct Sach Sach;
void Nhap(int &n, Sach *&A)
     {
     	   printf("Nhap bao nhieu cuon sach? : ");
     	   scanf("%d",&n);
     	   A = (Sach*)calloc(n,sizeof(Sach));
     	
     	for(int i = 0 ; i < n ; i++)
     	   {
     	   	int nam;
     	   	fflush(stdin);
     	    printf("\n-Nhap cuon %d",i+1);
			printf("\n Ten sach: ");
			gets((A+i)->Ten);
			printf(" Tac gia: ");
			gets((A+i)->Tacgia);
			printf(" Nam xuat ban: ");
			scanf("%d",&nam); fflush(stdin);
			(A+i)->Nam = nam;	
		   }
	 }
	 
void Xuat(int n, Sach *a)
     {
     	printf("%20s%30s%30s\n","Ten sach","Tac gia","Nam xuat ban");
     	printf("\n");
     	for(int i = 0 ; i < n ; i++)
     	   {
     	    printf("%20s%30s%30d\n",(a+i)->Ten,(a+i)->Tacgia,(a+i)->Nam);
		   }
	 }
	 
int DemSach(int n, Sach *a,char *ten) // dem sach theo tac gia
    {
    	
    	int dem = 0;
    
    	for(int i = 0 ; i < n ; i++)
    	   {
    	   	 if(strcmp(ten,(a+i)->Tacgia) == 0)
    	   	    dem++;
		   }
		return dem;
	}
	
void swap(Sach *x,Sach *y)
    {
    	Sach temp = *x;
    	*x = *y;
    	*y = temp;
	}
void sapxeptheonam(Sach *a,int n) 
     {
     	for (int i = 0 ; i < n-1 ; i++)
     	for (int j = i + 1 ; j < n; j++)
     	    {
     	    	if((a+i)->Nam > (a+j)->Nam)
     	    	  swap((a+i),(a+j));
			}
	 }

int demsonam(Sach *a,int n) // dem co bao nhieu nam
    {
    	int dem = 1;
    	int t = a->Nam;
    	
        for (int i = 1 ; i < n ; i ++)
          {
          	if(t != (a+i)->Nam)
          	  {
          	  	dem++;
          	  	t = (a+i)->Nam;
			  }
		  }
		return dem;
	}

int demsachtheonam(Sach *a,int n,int nam) 
    {
    	int dem = 0;
    	
    	for(int i = 0; i < n ; i++)
    	   {
    	   	if (nam == (a+i)->Nam)
    	   	   dem++;
		   }
		return dem;
	}
void  Thongke(int n, Sach *a)
       {
       	 int *mangnam; // mang chua cac nam
       	 sapxeptheonam(a,n); // sap xep mang theo nam
       	 int k = demsonam(a,n), t, j = 0, dem = 0; 
       	 mangnam = (int*)malloc(k*sizeof(int));
       	 
       	 // chay vong lap, lay nam nhap vao mang nam
       	 
       	 *mangnam = a->Nam;
       	 t = a->Nam;
       	 for (int i = 1 ; i < n ; i++)
       	     {
       	      	if( t != (a+i)->Nam)
       	      	   {
       	      	   	j++;
       	      	   	*(mangnam+j) = (a+i)->Nam;
       	      	   	t = (a+i)->Nam;
				   }
			 }
		
		   
		int *mangdem; // mag dem so cuon cua moi nam
		mangdem = (int*)malloc(k*sizeof(int));
		//chay vong lap, dem so cuon cua moi nam, sau do luu vao mang dem
		for(int i = 0 ; i < k ; i++)
		   {
		   	*(mangdem+i) = demsachtheonam(a,n,*(mangnam+i));
		   }
		
		printf("\n\tTHONG KE\n");
		for(int i = 0 ; i < k ; i++)
		   {
		   	printf("%d. %d : %d cuon\n",i+1,*(mangnam+i),*(mangdem+i));
		   }
	   }
int Menu()
    {
    	int x;
    	printf("1. Nhap n cuon sach\n2. Xuat n cuon sach\n3. Dem theo tac gia\n4. Thong ke\n5. Thoat ");
    	printf("- BAN MUON?: ");
    	 scanf("%d",&x);
    	return x;
	}
int main()
    {
    	int k = 0,x,n;
    	Sach *a;
    	while(1)
    	      { printf("\n");
    	      	x = Menu();
    	      	switch(x)
    	      	      {
    	      	      	case 1 : 
    	      	      	    {
							 nhap: 
							 Nhap(n,a);
							 k = 1;
							 } break;
    	      	      	case 2:
    	      	      		  {
    	      	      		    if( k == 0)
    	      	      		      {
    	      	      		        printf("\n Ban chua nhap sach. Vui long nhap!!!\n");
    	      	      		        goto nhap;
								  }
								if(k == 1)
								  {
								  	printf("\t\t\tNHUNG SACH VUA NHAP\n");
								  	Xuat(n,a);
								  }
							  } break;
					    case 3:
    	      	      		  {
    	      	      		  	if( k == 0)
    	      	      		      {
    	      	      		        printf("\n Ban chua nhap sach. Vui long nhap!!!\n");
    	      	      		        goto nhap;
								  }
								if(k == 1)
								  {     char *ten;
								  		ten = (char*)malloc(30*sizeof(char));
    	                                printf("-Ten tac gia can dem sach: ");
    	                                fflush(stdin);
    	                                gets(ten);
                                    int dem = DemSach(n,a,ten);
                                    printf("\nTAC GIA '%s' CO %d CUON SACH !!! ",ten,dem);
							      }
								} break;
					    case 4:
    	      	      		  {
    	      	      		  	if( k == 0)
    	      	      		      {
    	      	      		        printf("\n Ban chua nhap sach. Vui long nhap!!!\n");
    	      	      		        goto nhap;
								  }
								if(k == 1)
								  {
								  	Thongke(n,a);
							      }
							  }  break;
						case 5:
    	      	      		  {
    	      	      		  	exit(1);
							  } break;
					    default : printf("\n BAN NHAP SAI, VUI LONG NHAP LAI(1,2,3,4,5)!!!");
					  }
			  }
    	return 0;
	}
