#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int info;
    struct node *pre;
    struct node *next;

}*start;


void createlist(int n)
{ 
    int i;
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    for(i=1; i<=n; ++i)
    {   
        int data;
        struct node *p=(struct node *)malloc(sizeof(struct node));
        if(i==1)
        {
            printf("Enter node %d:\n",i);
            scanf("%d",&data);
            p->info=data;

            start=p;
           
            
            start->pre=NULL;
            start->next=NULL;
           
            ptr=start;
        }
        else if(i==n)
        {
            printf("Enter node  %d:\n",i);
            scanf("%d",&data);
            p->info=data;
            ptr->next=p;
            p->pre=ptr;
            p->next=NULL;

        }
        else
        {
            printf("Enter node:%d\n",i);
            scanf("%d",&data);
            p->info=data;
            ptr->next=p;
            p->pre=ptr;
            ptr=p;

        }
    }


}
void display()
{
    struct node *q;
 q=malloc(sizeof(struct node));  
    q=start;
    printf("\n");
    while(q!=NULL)
    {
        printf("%d\n",q->info);
        q=q->next;
    }
    
}
void insert(int pos,int n)
{
    int i,item;
    printf("Enter data:");
    scanf("%d",&item);
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=(struct node *)malloc(sizeof(struct node));
    if(pos==1)
    {
   
   
    p->info=item;
    p->pre=NULL;
    p->next=start;
    start->pre=p;
    start=p;
    ptr=start;
    }
    else if(pos==n+1)
    { 
        ptr=start;
        while(ptr->next!=NULL)
        ptr=ptr->next;
        p->info=item;
        p->next=NULL;
        ptr->next=p;
        p->pre=ptr;
    }
    else
    {
        ptr=start;
        for(i=1; i<pos-1; ++i)
        {
            ptr=ptr->next;
        }
        p->info=item;
        p->pre=ptr;
        
        p->next=ptr->next;
        ptr->next=p;

    }
}
    void delete(int pos,int n)
    {
        int i;
        struct node *q;
        if(pos==1)
        {
            start=start->next;
            start->pre=NULL;
        }
        else if(pos==n)
        {
            q=start;
            while(q->next->next!=NULL)
            {
                q=q->next;
            }
            q->next=NULL;
        }
        else
        {
            
              

        }
        
    }
   




int main()
{
    int n,pos,pos1;
    printf("Enter no of node:\n");
    scanf("%d",&n);
    createlist(n);
    printf("enter pos to insert:\n");
    scanf("%d",&pos);

    insert(pos,n);
    display();
    printf("Enter node to delete:\n");
    scanf("%d",&pos1);
    delete(pos1,n);
    display();
    return 0;
}
