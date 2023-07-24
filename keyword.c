#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,k;
    char strd[100];
    char strf[100];

    FILE *fp;
    char str[100];
    printf("\nenter the key that has to be replaced\n");
     scanf("%s",strd);
    printf("\nenter the replace key\n");
    scanf("%s",strf);
    fp=fopen("inp.txt","r");
    {
        if(fp=NULL)
        {
            printf("file cannot be read");
        }
        else
        {   fscanf(fp,"inp.txt","r");
            for(str[i]=0;str[i]!='\0';i++)
            {
                 if(str[i]==strd[j])

                 {
                      strd[i]=strf[k];
                 }
            }
        }

    }
    printf("%s",str[i]);
    fclose(fp);


}
