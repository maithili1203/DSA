#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getnode(int n)
{
    struct node *nw;
    nw=malloc(sizeof(struct node));
    nw->data=n;
    nw->left=NULL;
    nw->right=NULL;
    return(nw);
}

struct node *insert(struct node *root,int n)
{
    if(root==NULL)
    {
        root=getnode(n);
        return(root);
    }
    else if(n<root->data)
    {
        root->left=insert(root->left,n);
    }
    else{
        root->right=insert(root->right,n);
    }
    return(root);
}

void inorder(struct node *root,FILE *fp1)
{
    if(root==NULL)
        return;

    inorder(root->left,fp1);
    printf("%d\t",root->data);
    fprintf(fp1,"%d ",root->data);
    inorder(root->right,fp1);
}

void preorder(struct node *root,FILE *fp2)
{

    if(root==NULL)
        return;
    printf("%d\t",root->data);
    fprintf(fp2,"%d ",root->data);
    preorder(root->left,fp2);
    preorder(root->right,fp2);
}

void postorder(struct node *root,FILE *fp3)
{

    if(root==NULL)
        return;
    postorder(root->left,fp3);
    postorder(root->right,fp3);
    printf("%d\t",root->data);
    fprintf(fp3,"%d ",root->data);
}

int main()
{
    int l,u,N,num,i;
    struct node *root=NULL;

    FILE *fp,*fp1,*fp2,*fp3;
    printf("\nenter range min and max:");
    scanf("%d%d",&l,&u);
    printf("\nenter numbers:");
    scanf("%d",&N);
    fp=fopen("inp.txt","w");
    if(fp==NULL)
    {
        printf("\nerror");
        exit(0);
    }
     fp1=fopen("inorder.txt","w");
    if(fp1==NULL)
    {
        printf("\nerror");
        exit(0);
    }
      fp2=fopen("preorder.txt","w");
    if(fp2==NULL)
    {
        printf("\nerror");
        exit(0);
    }
      fp3=fopen("postorder.txt","w");
    if(fp3==NULL)
    {
        printf("\nerror");
        exit(0);
    }
    srand(time(0));
    printf("\nThe random numbers are: ");
    for(i=0;i<N;i++)
    {
        num=(rand() % (u-l+1))+l;
        root=insert(root,num);
        printf("\n%d",num);
        fprintf(fp,"%d ",num);
    }

    fclose(fp);
    printf("\nIn order traversal:\n");
    fprintf(fp1,"In order traversal:\n\n");
    inorder(root,fp1);
    printf("\nPre order traversal:\n");
    fprintf(fp2,"Pre order traversal:\n\n");
    preorder(root,fp2);
    printf("\nPost order traversal:\n");
    fprintf(fp3,"Post order traversal:\n\n");
    postorder(root,fp3);
}
