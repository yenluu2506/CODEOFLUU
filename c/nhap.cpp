//sap xep ten theo chu cai
void Sapxep(HS a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		   if(strcmp(a[i].Hoten,a[j].Hoten)<0)
		  {
			HS k=a[i];
            a[i]=a[j];
            a[j]=k;
		  }
		}
	} 
}
void Xuat(HS a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\n%s",a[i].Hoten);
	}
}
