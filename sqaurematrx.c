
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[10][10];
    int flag=0;
    int i,j;
    int r,c;
    int h;
    printf(" enter row and column");
    scanf("%d%d",&r,&c);
    if(r!=c)
    {
        printf(" not valid");
        exit(0);
    }
    h=r*c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]==a[j][i])
                flag++;
        }
    }
    if(flag==h)
    {
        printf("the matrix is  symmetric");
    }

}
