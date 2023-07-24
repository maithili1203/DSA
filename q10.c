#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node* link;
};
struct node* start = NULL;
void traverse()
{
	struct node* temp;


	if (start == NULL)
		printf("\nList is empty\n");

	else {
		temp = start;
		while (temp != NULL) {
			printf("Data = %d\n", temp->info);
			temp = temp->link;
		}
	}
}
void insertAtFront()
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);
	temp->info = data;


	temp->link = start;
	start = temp;
}

struct node *insert1(struct node *start,int data)
{

	struct node* temp;
	temp = malloc(sizeof(struct node));
	temp->info = data;
  temp->link = start;
	start = temp;
	return start;



void llposnum()
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


}}
int main()
{
	int choice;
	while (1) {

		printf("\n\t1 To see list\n");
		printf("\t2 For insertion at"
			" starting\n");
      printf("\t3 llposnum\n");
		printf("\t4 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
        case 3:
            llposnum();
            break;
		case 4:
			exit(1);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}
