#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000

int main()
{
    int a[SIZE];
    int j,i,temp;
    float totaltime;
    clock_t starttime,endtime;
    FILE *fp,*fp1,*fp2;
    fp=fopen("abc.txt","w");
    fp1=fopen("xyz.txt","w");
    fp2=fopen("log.txt","w");
    int lower,upper,n;
    printf(" enter the lower and upper range:\n ");
    scanf("%d%d",&lower,&upper);
    printf(" enter how many numbers: ");
    scanf("%d",&n);
    srand(time(0));
    printf(" random no.s are:\n");
    if(fp==NULL)
    {
        printf("file not opened");
        exit(0);
    }

    for(int i=0;i<n;i++)
    {
        a[i]=(rand()%(upper-lower+1))+lower;
        printf("%d\t",a[i]);
        fprintf(fp,"%d\t",a[i]);
    }
    printf("\n");
    fclose(fp);
    if(fp1==NULL)
    {
        printf("file not opened");
        exit(0);
    }
    if(fp2==NULL)
    {
        printf("file not opened");
        exit(0);
    }
    starttime=clock();

    for(i=1;i<n;i++)
    {
        for(j=0;j<(n-i);j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    endtime=clock();
    totaltime=(float)(endtime-starttime);
    printf(" total time for bubble sort is: %f",totaltime);
    fprintf(fp2,"value of numbers x:%d,total time: %f",n,totaltime);

    printf(" sorted numbers are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
        fprintf(fp1,"%d\t",a[i]);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
