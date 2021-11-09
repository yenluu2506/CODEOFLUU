#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

void Lagrange()
{
    int n,i,j;
    float c,x[10],y[10],p,L;
    printf("Nhap n =");
	scanf("%d",&n);
	printf("Nhap c =");
	scanf("%f",&c);
	for(i=0;i<n;i++){
		printf("Nhap x[%d],y[%d]",i,i);
		scanf("%f%f",&x[i],&y[i]);
	}
	p=0;
	for(i=0;i<n;i++){
		L=1;
		for(j=0;j<n;j++){
			if(i!=j){
				L=L*(c-x[j])/(x[i]-x[j]);
			}
		}
		p=p+y[i]*L;
		printf("L=%f \n",L);
	}
	printf("p(%.2f)=%f",c,p);
}

void NewtonTrenLuoiDeu(){
	float x[20],fx[20][20],xvalue,h,p,temp,ans;
    int n,i,j,fact;
    printf("\n Nhap gia tri muon tinh gan dung: ");
    scanf("%f",&xvalue);
    printf("\n Nhap n : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\n Nhap gia tri cua x: ");
        scanf("%f",&x[i]);
        printf("\n Nhap gia tri cua f(x): ");
        scanf("%f",&fx[i][0]);
    }

    h=x[1]-x[0];
    p=(xvalue-x[0])/h;

    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            fx[j][i]=fx[j+1][i-1]-fx[j][i-1];
        }
    }

    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n-i;j++)
        {
            printf("%f ",fx[i][j]);
        }
    }

    ans=fx[0][0];
    for(i=1;i<n;i++){
        temp=p;
        for(j=1;j<i;j++){
            temp=temp*(p-j);
        }

        fact=1;
        for(j=1;j<=i;j++){
            fact=fact*j;
        }
        ans=ans+((temp/fact)*fx[0][i]);
    }
    printf("\n f(x) = %f",ans);
}

void Nhap( int, double** mat );
void Tinh_Jacobi( int, double** mat ,float,int);
double dotProd( int num, double* v1, double* v2 );
int checkFlag( int num, int flags[] );

void Nhap( int numEntree, double** mat ){
    int i, j;
    printf("\n\t\t\t\t\t\tTHEO HANG\n");
    for( i = 0 ; i < numEntree ; i++ ){
        mat[i] = (double*) malloc( (numEntree+1)*sizeof(double) );

        puts("");
        for( j = 0 ; j < numEntree+1 ; j++ ){
            printf("Nhap he so cua hpt tuyen tinh[%d][%d] : ", i, j);
            if( scanf("%lf", &mat[i][j]) != 1 ){
                --j;
                puts("Loi.Xin vui long nhap lai");
            }
            while( getchar() != '\n' ) ;
        }
    }
}

void Tinh_Jacobi( int numEntree, double** mat ,float EPS,int Max_Iter)
{
    int* flag;
    int i, j, counter = 0;
    double* res;
    double* var = (double*) malloc( numEntree*sizeof(double) );
    res = (double*) malloc( numEntree*sizeof(double) );
    flag = (int*) malloc( numEntree*sizeof(int) );

    for(i = 0 ; i < numEntree ; i++ )
        var[i] = res[i] = flag[i] = 0;
    printf( "*******************************************************\n");
    do
    {
        counter++;
        for(i = 0 ; i < numEntree ; i++ ){
			var[i] = res[i];
		}
        printf("\n So lan lap : %d \n", counter);
        for(i = 0 ; i < numEntree ; i++ ) /* Le calcul */
        {
            res[i] = mat[i][numEntree];
            for(j = 0 ; j < numEntree ; j++ )
                res[i] = res[i] - mat[i][j]*var[j] ;
				res[i] = res[i] + mat[i][i]*var[i] ;
				res[i] = res[i] / mat[i][i] ;
				printf("%c = %f\n", 'a'+i, res[i]);
            if( fabs(res[i] - var[i]) < EPS )
                flag[i]++;
		}
    }while( !checkFlag( numEntree, flag ) && counter<Max_Iter);
printf("*********************************\n");
    printf( "Ket qua cua lan lap thu %d la: \n", counter);
    for( i = 0 ; i < numEntree ; i++){
        var[i] = dotProd( numEntree, mat[i], res );
	}
    printf("\nKet qua la:\n");
    for( i = 0 ; i < numEntree ; i++){
        printf("%c = %+f\n", 'a'+i, res[i]);
        free(mat[i]);
    }
    free( mat );
    free( flag );
    free( res );
    free( var );
}
int checkFlag( int num, int flags[] ){
    int i;
    for( i=0; i<num; ++ i)
        if( flags[i] == 0 ) return 0;
    return 1;
}
double dotProd( int num, double* v1, double* v2 ){
    int i;
    double somme =0;
    for( i=0; i<num; ++i ) somme += v1[i]*v2[i];
    return somme;
}
double f(double x){
  return 1/(2*x+2);
}

void Simpson()
{
    int n,i;
  double a,b,h,x,sum=0,tp;
  printf("\nNhap n : ");
  scanf("%d",&n);
  printf("\nNhap a : ");
  scanf("%lf",&a);
  printf("\nNhap b : ");
  scanf("%lf",&b);
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    if(i%2==0){
      sum=sum+2*f(x);
    }
    else{
      sum=sum+4*f(x);
    }
  }
  tp=(h/3)*(f(a)+f(b)+sum);
  printf("\nGia tri cua tich phan gan dung la : %lf\n",tp);
}

void HinhThang()
{
   int n,i;
  double a,b,h,x,sum=0,tp;
  printf("\nNhap n : ");
  scanf("%d",&n);
  printf("\nNhap a : ");
  scanf("%lf",&a);
  printf("\nNhap b: ");
  scanf("%lf",&b);
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }
  tp=(h/2)*(f(a)+f(b)+2*sum);
  printf("\nGia tri tich phan gan dung la : %lf\n",tp);
}

void Gauss(){
			float a[10][10], x[10], tiso;
			int i,j,k,n;
			
			printf("\n\t\t\t\tGIAI HE PHUONG TRINH TUYEN TINH BANG PHUONG PHAP GAUSS\n");
			printf("Nhap so an cua he phuong trinh tuyen tinh: ");
			scanf("%d", &n);
		
			for(i=1;i<=n;i++){
				for(j=1;j<=n+1;j++){
					printf("a[%d][%d] = ",i,j);
					scanf("%f", &a[i][j]);
				}
			}
		
			for(i=1;i<=n-1;i++){
				if(a[i][i] == 0.0){
					   printf("Loi");
					   exit(0);
				}
				for(j=i+1;j<=n;j++){
				tiso = a[j][i]/a[i][i]; 
					for(k=1;k<=n+1;k++){
						a[j][k] = a[j][k] - tiso*a[i][k];
					}
				}
			}
			 
			x[n] = a[n][n+1]/a[n][n];
			for(i=n-1;i>=1;i--){
				x[i] = a[i][n+1];
				for(j=i+1;j<=n;j++){
				  	x[i] = x[i] - a[i][j]*x[j];
				}
				x[i] = x[i]/a[i][i];
			}
			
			printf("\nHe phuong trinh tuyen tinh co nghiem la:\n");
			for(i=1;i<=n;i++){
				printf("x[%d] = %0.4f\n",i, x[i]);
			}
}
void nhap( float d[],int n){
	int i;
	for (i=0;i<=n;i++){
		printf("d[%d]=",i);
		scanf("%f",&d[i]);
	}
}
float f(float d[],int n, float c ){
	int i; 
	float p=d[0];
	for(i=1;i<=n;i++)
		p=p*c+d[i];
	return p;
}
void chiadoi(){
	float x,d[10],a,b,c,e;char q;
	int i,n; 
		printf("nhap bac da thuc n\n");
		scanf("%d",&n); 
		printf("nhap cac he so\n");
		nhap(d,n);
	while(1){
		printf("\n nhap khoang nghiem a va b\n"); 
		scanf("%f%f",&a,&b);
		if (f(d,n,a)*f(d,n,b)>0) 
		continue;
	do
	{
		c=(a+b)/2; 
		e=f(d,n,c);
		printf("\n%9.3f%9.3f%9.3f\n",a,b,e);
		if(e*f(d,n,a)>0)
			a=c;
		else 
			b=c;
	}
	while(fabs(e)>=0.001);
		printf("\n nghiem cua chuong trinh la:%.3f",c);
		}
}

void daycung(){
	float x,d[10],a,b,t1,t2; 
	char q;
	int i,n; 
		printf("nhap bac da thuc n\n");
		scanf("%d",&n); 
		printf("nhap cac he so\n");
		nhap(d,n);
	while(1){
		printf("\n nhap khoang nghiem a va b\n"); 
		scanf("%f%f",&a,&b);
		if (f(d,n,a)*f(d,n,b)>0){
			printf("\n a b khong phaikhoang ngiem\n");
			continue;
		}
	do
	{ 
		printf("\n%9.3f%9.3f%9.3f%9.3f",a,b,x,f(d,n,x));
		x=a-((b-a)*f(d,n,a))/(f(d,n,b)-f(d,n,a));
		if(f(d,n,x)*f(d,n,a)>0) 
			a=x;
		else 
			b=x;
	}
	while(fabs(f(d,n,x))>=0.001); 
		printf("\nngiem cua phuong trinh la %.3f",x); 
		printf("\ntiep tuc k?(c/k)");
		q=getch();
		if(q=='k') 
		break;
	}
}

// tiep tuyen va phuong phap lap 
#define eps 0.0001
 
float tinh_ham(float x)
{
    return x * x * x + x - 5; // tinh bai khac thi thay ham so 
}
 
float tinh_dao_ham(float x)
{
    return 3 * x * x + 1; // thay dao ham theo ham so da thay 
}

void tieptuyen(){
	float x, y = 0;
    printf("\nNhap x = ");
    scanf("%f", &x);
     
    do {
        y = x;
        float t = tinh_ham(y) / tinh_dao_ham(y);
        x = y - t;
        printf("\n%.3f\t%.3f", x, t);
    }
    while (fabs(x - y) > eps);
     
    printf("\n\nNghiem cua pt la: %f", y);
    return ;
}

float tinh_ham1(float x)
{
    return pow(x + 1, 1.0 / 3);
}

void lap(){
	float x, y;
    printf("\nNhap x: ");
    scanf("%f", &x);
    do {
        y = x;
        x = tinh_ham1(x);
        printf("\n%.3f\t%.3f", x, y);
    }
    while (fabs(x - y) > eps);
     
    printf("\n\nNghiem gan dung cua pt la: %f", x);
    return ;
}
int main(){
	printf("\t\t\t\t\tMENU CHUONG TRINH BAI THUC HANH\n");
	printf("BAI THUC HANH 1\n");
	printf("\t1.Noi Suy Ham So Theo Lagrange\n");
	printf("\t2.Noi Suy Ham So Theo Newton Tren Luoi Deu\n");
	printf("\t3.Noi Suy Ham So Theo Newton Tren Luoi Khong Deu\n");
	printf("BAI THUC HANH 2\n");
	printf("\t4.Tich Phan Gan Dung Bang Simpson\n");
	printf("\t5.Tich Phan Gan Dung Bang Hinh Thang\n");
	printf("\t6.Giai He PTTT Phuong Phap Gauss\n");
	printf("\t7.Giai He PTTT Phuong Phap Jacobi\n");
	printf("BAI THUC HANH 3\n");
	printf("\t8.Tim Nghiem Gan Dung Phuong Phap Chia Doi\n");
	printf("\t9.Tim Nghiem Gan Dung Phuong Phap Day Cung\n");
	printf("\t10.Tim Nghiem Gan Dung Phuong Phap Tiep Tuyen\n");
	printf("\t11.Tim Nghiem Gan Dung Phuong Phap Lap Newton\n");
	printf("\t0.Thoat Chuong Trinh\n");
	printf("NHAP LUA CHON CUA BAN: ");
	int chon;
	scanf("%d", &chon);
	
	switch(chon){
		case 0:
			break;
		case 1:
			Lagrange();
			system("cls");
		break;	
		case 2:
			NewtonTrenLuoiDeu();
			system("cls");
		break;	
		case 3:{
			int n,i,j;
		    float x[100],f[100],a,sum=0,mult;
		    printf("Nhap n ");
		   	scanf("%d",&n);
		    
		    for(i=0;i<n;i++){
		    	printf("Nhap x[%d] ",i); 
		    	scanf("%f",&x[i]);
		    	printf("Nhap f[%d] ",i); 
		    	scanf("%f",&f[i]);
		    }
		    printf("\nNhap gia tri muon tinh gan dung  ");
		    scanf("%f",&a);
		
		    for(j=0;j<n-1;j++)
		    {
		        for(i=n-1;i>j;i--)
		            f[i]=(f[i]-f[i-1])/(x[i]-x[i-j-1]);
		    }
		    for(i=n-1;i>=0;i--)
		    {
		        mult=1;
		        for(j=0;j<i;j++)
		            mult*=(a-x[j]);
		            
		        mult*=f[j];
		        sum+=mult;
		    }
		    printf("Ket qua la :%f",sum);
		}break;
		case 4:
			Simpson();
			system("cls");
		break;	
		case 5:
			HinhThang();
			system("cls");
		break;
		case 6:
			Gauss();
			system("cls");
		break;
		case 7:{
			double **mat;
		    int num;
			float EPS;
			int SoLanLap_ToiDa;
		        printf("Nhap so an cua he phuong trinh tuyen tinh: ");
		        scanf("%d", &num);
				printf("\nNhap so lan lap toi da:");
				scanf("%d",&SoLanLap_ToiDa);
				printf("\nNhap do chinh xac cua eps:");
				scanf("%f",&EPS);
				
		        while( getchar() != '\n' ) ;
		        mat = NULL;
		        if(SoLanLap_ToiDa>0 && EPS>=0 && num>0 && (mat = (double**) malloc(num*sizeof(double*))) ){
		            Nhap(num, mat);
					Tinh_Jacobi(num,mat,EPS,SoLanLap_ToiDa);
		        }else{
					puts("\nLoi");
		            if( mat != NULL ) free( mat );
		        }
		}break;
		case 8:
			chiadoi();
			system("cls");
		break;
		case 9:
			daycung();
			system("cls");
		break;
		case 10:
			tieptuyen();
			system("cls");
		break;	
		case 11:
			lap();
			system("cls");
		break;
		default:
			printf("Xin Vui Long Nhap Lai Lua Chon Khac.........");
		}
}