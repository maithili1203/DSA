#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int lengs(char a[]);
void main()
{
    char str[100][100];
    int i;
    int L;
    int j;
    int b[100];
    for(i=0;i<10;i++)
    {
        gets(str[i]);

    }
    void compare(char str[])
    {
    for(i=0;i<10;i++)
    {
        b[i]=lengs(str[i]);
    }
    L=b[0];
    for(i=1;i<10;i++)
    {
        if(b[i]>L)
        {
            L=b[i];
            j=i;
        }
    }
    }
    printf(" The longest line is: ");
    puts(str[j]);
    return;
}
int lengs(char a[100])
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}
