#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STACKSIZE 100
struct stack
{
    int s[STACKSIZE];
    int top;
};
int stacktop(struct stack stk )
{
    printf("the top value is",stk.s[stk.top]);
}
int full(struct stack stk)
{
    if(stk.top==STACKSIZE-1)
        return 1;
    else
        return 0;
}
int empty(struct stack stk)
{
    if(stk.top==-1)
        return 1;
    else
        return 0;
}
void push(struct stack *ps,int data)
{
    ps->top=ps->top+1;
    ps->s[ps->top]=data;

}
int pop(struct stack *ps)
{
    int data=ps->s[ps->top];
    ps->top=ps->top-1;
    return data;
}
void display(struct stack stk)
{

    for(int i=stk.top;i>=0;i--)
    {
        printf("%d\n",stk.s[i]);

    }
}
int main()
{
    int a[STACKSIZE];
    int i,j;
    FILE *fp1,*fp2,*fp3,*fp4,*fp5;
    fp1=fopen("qbc.txt","w");
    fp2=fopen("stk.txt","a");
    fp3=fopen("push.txt","a");
    fp4=fopen("pop.txt","a");
    fp5=fopen("opration.txt","a");
    if(fp1==NULL)
    {
        printf("file not created");
        exit(0);
    }
    if(fp2==NULL)
    {
        printf("file not created");
        exit(0);
    }
    if(fp3==NULL)
    {
        printf("file not created");
        exit(0);
    }
    if(fp4==NULL)
    {
        printf("file not created");
        exit(0);
    }
    if(fp5==NULL)
    {
        printf("file not created");
        exit(0);
    }
    int low,up,n;
    printf(" enter the lower and upper range:\n ");
    scanf("%d%d",&low,&up);
    printf(" enter the n value: ");
    scanf("%d",&n);
    srand(time(NULL));
    printf(" random no.s are:\n");
    for(int i=0;i<n;i++)
    {
        a[i]=(rand()%(up-low+1))+low;
        printf("%d\t",a[i]);
        fprintf(fp1,"%d\t",a[i]);
    }
    printf("\n");
    fclose(fp1);


    struct stack stk;
    int choice,data;
    stk.top=-1;
    i=0;
    do
    {
        printf("1-> push \t 2-> pop \t 3-> stacktop \t 4-> display \t 5->exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:if(full(stk))
                     printf("\n stack overflow\n");

                   else
                   {
                       push(&stk,a[i]);
                       fprintf(fp3,"%d\n",a[i]);
                       fprintf(fp5,"push of %d\n",a[i]);
                        i++;
                        printf("\n");
                   }
                   break;
           case 2:if(empty(stk))
                     printf("\n stack underflow\n");
                   else
                   {
                       data=pop(&stk);
                       printf("popped data is %d \n",data);

                       fprintf(fp4,"%d\n",data);
                       fprintf(fp5,"pop of %d\n",data);
                       printf("\n");
                   }
                   break;
           case 3:if(empty(stk))
                     printf(" \n stack empty \n");
                  else
                     printf(" \n stack top data is %d \n",stacktop(stk));
                  break;
           case 4:if(empty(stk))
                     printf(" \n stack element empty \n");
                  else
                  {
                     printf(" \n stack elements \n");
                     display(stk);
                  }
                  break;
           case 5:break;
        }
    }while(choice!=5);
    for(int i=stk.top;i>=0;i--)
    {
      fprintf(fp2,"%d\n",stk.s[i]);
    }
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    return 0;
}
