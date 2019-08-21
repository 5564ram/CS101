#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *root;
int n=0;
void inorder(struct node *p)
{
    if(p==NULL)
    return ;
    inorder(p->lptr);
    printf("%d\t",p->info);
    inorder(p->rptr);

}
void preorder(struct node *p)
{
    if(p==NULL)
    return ;
    printf("%d\t",p->info);
    preorder(p->lptr);
    preorder(p->rptr);

}
void postorder(struct node *p)
{
    if(p==NULL)
    return ;
    postorder(p->lptr);
    postorder(p->rptr);
    printf("%d\t",p->info);
    

}
void createtree(int a[])
{
    root->info=a[0];
    for(int i=1;i<n; ++i)
    {
    struct node *temp=root;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info=a[i];
    while(1)
    {
        if(a[i]>temp->info)
        {
            if(temp->rptr==NULL)
            {
                temp->rptr=ptr;
                break;
            }
            else
            {
                temp=temp->rptr;
            }
            
        }
        if(a[i]<temp->info)
        {
            if(temp->lptr==NULL)
            {
                temp->lptr=ptr;
                break;
            }
            else
            {
                temp=temp->lptr;
            }
            
        }
    }
    }
    

}


int main()
{
    printf("Element total no to be inserted:\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&a[i]);
    }
    root=(struct node*)malloc(sizeof(struct node));
    root->lptr=NULL;
    root->rptr=NULL;
    createtree(a);
    printf("\n");
    inorder(root);
    printf("\n\n");
    postorder(root);
    printf("\n\n");
    preorder(root);
    printf("\n\n");
    return 0;


}
