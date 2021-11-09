#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
int count;
char n[30];
count=0;
// code design by SEO ANH

t:printf("Hay nhap vao Password:");
scanf("%s",n);
count=count+1;

if(strcmp(n,"m24fdn")!=0&& count<3)
{
    printf("Sai pass !!!  Hay nhap lai   ( ban con %d lan nhap tiep)\n",3-count);
    goto t;
}
if((count==3)&&strcmp(n,"m24fdn")!=0)
{
    printf("Qua 3 lan nhap sai.Exit\n");
}
else printf("Dung pass\n");
getch();

}
