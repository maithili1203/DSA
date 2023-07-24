#include<stdio.h>
#include<stdlib.h>

struct dequeue
{
    int c;
    struct dequeue *next,*prev;
};

struct dequeue *insertrear(struct dequeue *head)
{
    struct dequeue *nw,*cur;
    nw=malloc(sizeof(struct dequeue));
    if(nw==NULL)
    {
        printf("\nmemory not allocated");
        exit(0);
    }
    nw->next=NULL;
    nw->prev=NULL;
    printf("\nEnter c:");
    scanf("%d",&nw->c);
    if(head==NULL)
    {
        head=nw;
        return(head);
    }
    for(cur=head;cur->next!=NULL;cur=cur->next);
    cur->next=nw;
    nw->prev=cur;
    return(head);
}

struct dequeue *insertfront(struct dequeue *head)
{
    struct dequeue *nw;
    nw=malloc(sizeof(struct dequeue));
    if(nw==NULL)
    {
        printf("\nmemory not allocated");
        exit(0);
    }
    nw->next=NULL;
    nw->prev=NULL;
    printf("\nEnter c:");
    scanf("%d",&nw->c);
    if(head==NULL)
    {
        head=nw;
        return(head);
    }
    nw->next=head;
    head=nw;
    return(head);
}

struct dequeue *deletefront(struct dequeue *head)
{
    struct dequeue *cur;
    cur=head;
    head=head->next;
    free(cur);
    head->prev=NULL;
    return(head);
}

struct dequeue *deleterear(struct dequeue *head)
{
    struct dequeue *cur,*pr;
    cur=head;
   while(cur->next!=NULL)
   {
       pr=cur;
       cur=cur->next;
   }
    free(cur);
    pr->next=NULL;
    return(head);
}

void display(struct dequeue *head)
{
    struct dequeue *cur;
    for(cur=head;cur!=NULL;cur=cur->next)
    {
        printf("%d\t",cur->c);
        printf("%d\n",&cur->c);
    }
}

int main()
{
    struct dequeue *head=NULL;
    int choice,i;


    printf("\n1.insert front  2.insert rear  3.delete front  4.delete rear  5.display  6.exit");
    while(1)
    {
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
    {
        case 1:head=insertfront(head);
        break;

        case 2:head=insertrear(head);
        break;

        case 3:head=deletefront(head);
        break;

        case 4:head=deleterear(head);
        break;

        case 5:display(head);
        break;

        case 6:exit(0);
    }
    }

}
