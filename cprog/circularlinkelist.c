#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;

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
          printf("Enter data:%d",i);
          scanf("%d",&data);
          start=p;
          p->info=data;
          ptr=p;
          ptr->link=NULL;
        }
        else if(i==n)
        {
            printf("Enter data=%d:",i);
            scanf("%d",&data);
            p->info=data;
            ptr->link=p;
            p->link=start;

        }
          else
          {
               printf("Enter data=%d:",i);
               scanf("%d",&data);
              p->info=data;
              ptr->link=p;
              ptr=p;
          }
        
    }
 

}
void display()
{
    struct node *ptr;
    ptr=start;
    while(ptr->link!=start)
    {
        printf("%d\t",ptr->info);
        ptr=ptr->link;
    }
    printf("%d\n",ptr->info);
}
int main()
{
   int n;
   printf("Enter no of node:\n");
   scanf("%d",&n);
   createlist(n);
   display();
   return 0;
}