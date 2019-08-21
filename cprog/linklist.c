#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*start;
void trav( )
{
    struct node *q;
    q=start;
    while(q->link!=NULL)
    {
        printf("DATA=%d\n",q->data);
        q=q->link;
    }
    printf("DATA=%d\n",q->data);
}
void createlist(int n)
{
    int i,item;
   
    
    for(i=1; i<=n; ++i)

    {   struct node *ptr= (struct node *)malloc(sizeof(struct node));
        printf("Enter data %d:",i);
        scanf("%d",&item);
         struct node *p= (struct node *)malloc(sizeof(struct node));
         p->data=item;
         p->link=NULL;
        if(i==1)
        {
            start=p;
            p->link=NULL;
        }
        else 
        {   ptr=start;
        while(ptr->link!=NULL)
             ptr=ptr->link;
             ptr->link=p;
        

        }

    }
}
/*void insert(int item)
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->link=start;
    start=new;

}

void insert1(int item)
{
    struct node *new,*ptr;
    new=(struct node*)malloc(sizeof(struct node));
    ptr=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    ptr=start;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=new;
    
}*/
/*void insert2(int pos,int item)
{ 
    int i;
    struct node *p,*ptr;
    p=(struct node*)malloc(sizeof(struct node));
    ptr=(struct node*)malloc(sizeof(struct node));
    p->data=item;
    p->link=NULL;
    ptr=start;
    for(i=1; i<pos; ++i)
    {
        ptr=ptr->link;
      
    }
    p->link=ptr->link;
    ptr->link=p;
}*/
/*void delete()
{
    start=start->link;
}*/
/*void del_last()
{
    int k=0,i;
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
     
    ptr=start;
    while((ptr->link->link)!=NULL)
    {
        
    ++k;
    ptr=ptr->link;
    }
    ptr->link=NULL;
    


}*/
void del_pos(int,int);

int main()
{
    start=NULL;
    int n,item,pos;
   
    printf("no of node to insert:\n");
    scanf("%d",&n);
    createlist(n);
     //printf("enter element to insert:\n");
    //scanf("%d",&item);
    //insert(item);
    //insert1(item);
    printf("Enter pos to delete:\n");
    scanf("%d",&pos);
    //insert2(pos,item);
    //delete();
    //del_last();
    del_pos(pos,n );
    trav();
    return 0;
}
void del_pos(int pos,int n)
{
    int i;
    struct node *ptr,*pre;
    ptr=(struct node *)malloc(sizeof(struct node));
    pre=(struct node *)malloc(sizeof(struct node));
    ptr=start;
    if(start==NULL)
    printf("No nade!:");
    else if(pos==1)
    start=start->link;
    else if(pos==n)
    {
        while(ptr->link->link!=NULL)
        ptr=ptr->link;
        ptr->link=NULL;
    }
    else
    {
        for(i=1; i<pos-1; ++i)
        ptr=ptr->link;
        pre=ptr->link;
        ptr->link=pre->link;
    }

}

