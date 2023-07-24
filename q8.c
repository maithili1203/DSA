#define STACKSIZE 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int l,u,N,num,i;

    FILE *fp;
    printf("\nenter range lower and upper:");
    scanf("%d%d",&l,&u);
    printf("\nenter count:");
    scanf("%d",&N);
    fp=fopen("inp.txt","w");
    if(fp==NULL)
    {
        printf("\nerror");
        exit(0);
    }
    srand(time(0));
    printf("\nThe random numbers are: ");
    for(i=0;i<N;i++)
    {
        num=(rand() % (u-l+1))+l;
        printf("\n%d",num);
        fprintf(fp,"%d\t",num);
    }
    printf("\n\nNumbers have been printed in file successfully\n");
    fclose(fp);
}
