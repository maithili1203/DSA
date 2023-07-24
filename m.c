#include <stdio.h>
#include <stdlib.h>

struct info
{
    int p;
    char string[10];
};

struct node
{
    struct info job;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void initqueue(struct queue *que)
{
    que->front=que->rear=NULL;
}

int isempty(struct queue *que)
{
    if(que->front==NULL)
        return 1;
    else
        return 0;
}

void insert(struct queue *que,struct info dt)
{
    struct node *nw;
    nw=malloc(sizeof(struct node));
    nw->job=dt;
    nw->next=NULL;
    if(isempty(que))
    {
        que->front=nw;
        que->rear=nw;
    }
    else{
        que->rear->next=nw;
        que->rear=nw;
    }
}

struct info delet(struct queue *que)
{
    struct node *temp;
    struct info dt;
    if(isempty(que))
    {
        dt.p=0;
        return(dt);
    }
    temp=que->front;
    dt=temp->job;
    que->front=temp->next;
    if(que->front==NULL)
    {
        que->rear=NULL;
    }
    free(temp);
    return(dt);
}

int main()
{
    struct info dt,dt1;
    struct queue *ques;
    int i,a,b;
    printf("\nEnter number of priorities:");
    scanf("%d",&a);
    printf("\nEnter number of jobs:");
    scanf("%d",&b);
    ques=malloc(a*sizeof(struct queue));
    for(i=0;i<a;i++)
    {
        initqueue(&ques[i]);
    }
    for(i=0;i<b;i++)
    {
        printf("\nEnter job details:");
        scanf("%s",dt.string);
        printf("\nEnter priority:");
        scanf("%d",&dt.p);
        if(dt.p>=1&&dt.p<=a)
        {
            insert(&ques[dt.p-1],dt);
        }
        else{
            printf("\nInvalid priority:");
        }
    }
    for(i=0;i<a;i++)
    {
        printf("\nQueue %d:",i+1);
        while(!isempty(&ques[i]))
        {
            dt1=delet(&ques[i]);
            printf("%s %d\t",dt1.string,dt1.p);
        }
    }
    free(ques);
    return(0);
}
