#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lower,upper,N,num,i;
    FILE *fp;
    printf("\enter range lower and upper:");
    scanf("%d%d",&lower,&upper);
    printf("\nenter count:");
    scanf("%d",&N);

    srand(time(0));
    printf("\nThe random numbers are: ");
    for(i=0;i<N;i++)
    {
        num=(rand() % (upper-lower+1))+lower;
        printf("\n%d",num);

    }

fp=fopen("inp.txt","w");
    if(fp==NULL)
    {
        printf("\file cannot be opened");
        exit(0);
    }
    else{
          for(int i=0;i<N;i++)
    {
         fprintf(fp,"%d",num);
    }
     printf("\n\nNumbers are written  in file successfully\n");
    fclose(fp);
}
}
