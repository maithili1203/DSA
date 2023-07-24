#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    char str[100][100];
    char strd[100];
    char strs[100];
    int i,j,b,n,m,h,g;
    FILE*fp;
    fp=fopen("inp.txt","r");
    printf(" enter the value of n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        gets(str[i]);
    }
    printf(" enter word to search: ");
    scanf("%s",strd);
    printf(" enter word to replace: ");
    scanf("%s",strs);

    i=0;
    for(i=0;i<n;i++)
    {
        j=0;
        b=0;


    while(str[i][j]!='\0')
    {
        if(str[i][j]!=strd[b])
        {
            j++;
        }
        else
        {
            j++;
            b++;
           while(strd[b]!='\0')
           {
               if(str[i][j]!=strd[b])
               {
                   j++;
                   b=0;
                   break;
               }
               else
               {
                   j++;
                   b++;
               }
           }
           if(strd[b]=='\0')
           {
               for(int n=0,m=0;strs[m]!='\0';b--,m++)
               {
                   n++;
                   int g=j-b;
                   str[i][g]=strs[m];

               }

           }
        }
    }
    puts(str[i]);
    }
    fclose(fp);
}
