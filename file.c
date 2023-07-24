#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,n,b,h,gk;
    char strd[100];
    char strs[100];
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


    printf(" enter pattern to search: ");
    scanf("%s",strd);
    printf(" enter patter to rewrite: ");
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
               b=lengs(strd);
               if(m<b)
               {
                   for(h=0;h<b-m;h++)
                   {

                       str[i][g+1]=' ';

                   }
               }
           }
        }
    }
    puts(str[i]);
    }
        }}}
        }

    }
    printf("%s",str[i]);
    fclose(fp);


}
