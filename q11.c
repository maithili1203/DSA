
#include <stdio.h>
#include <stdlib.h>
struct node {
	int info;
	struct node* link;
};

void display(struct node *start)
{
	struct node* temp;
if (start == NULL)
		printf("\nList is empty\n");
  else {
		temp = start;
		while (temp != NULL) {
			printf("%d\n", temp->info);
			temp=temp->link;
		}
	}
}
struct node *insert(struct node *start)
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	scanf("%d", &data);
	temp->info = data;
  temp->link = start;
	start = temp;
	return start;

}
struct node *insert1(struct node *start,int data)
{

	struct node* temp;
	temp = malloc(sizeof(struct node));
	temp->info = data;
  temp->link = start;
	start = temp;
	return start;

}

int main()
{
    struct node* start1 = NULL;
    struct node* start2 = NULL;
    struct node* start3 = NULL;
    int n,i;
    printf("  enter no. of elements: ");
    scanf("%d",&n);
    printf(" enter %d elements \n",n);
    for(i=0;i<n;i++)
    {
        start1=insert(start1);
    }
    struct node* temp;
    if (start1 == NULL)
		printf("\nList is empty\n");
  else
    {
		temp = start1;
		while (temp != NULL) {
			if(temp->info>0)
            {
                start2=insert1(start2,temp->info);
            }
            else
            {
                start3=insert1(start3,temp->info);
            }
			temp=temp->link;
		}
	}
  printf("list of +ve no.s\n");
  display(start2);
  printf("list of -ve no.s\n");
  display(start3);


}
