#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int length(char[]);
void main()
{
    char str[10][10];
    int i,j,b,L;
    int a[10];
    for(i=0;i<10;i++)
    {
        gets(str[i]);
    }
    b=length(str[0]);
    L=b;
    for (i=0;i<10;i++)
    {
        b=length(str[i]);
        if(L<b)
        {
            L=b;
            j=i;
        }
    }
    printf(" The longest line is: ");
    puts(str[i]);
    return;

}
int length(char a[100])
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}
