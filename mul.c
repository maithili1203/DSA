#include<stdio.h>
#include<stdlib.h>
void read(int n,int m,int(*a)[10]);
void mul(int p,int q,int (*b)[10]);

main()
{

    int n,m,p,q ,i,j,k,c[20][20],a[20][20],b[20][20];

    printf("Enter Rows and Columns\n");
    scanf("%d%d",&m,&n);
    printf("Enter Rows and Columns\n");
    scanf("%d%d",&p,&q);
   if (n=p)
   {
       void read(m,n,a);
       void mul(m,n,c);
   }
   else
   {
       printf("invalid mtrix");
   }
   void read(int m,int n,int (*a)[][10],int(*b)[][10])
   {
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",(*a(i+1)+j));

        }
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",(*b(i+1)+j));

}
}
   }
 void mul( int m,n,k,int(*c)[][10])
{
for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)

        {
        c[20][20]=0;
        }
        for(k=0;k<n;k++)
        {
        c[20][20]=c[20][20]+a[20][20]*b[20][20];
        }
            printf("%d\t",c[j][i]);

        }
        printf("\n");
    }
}



