#include<stdio.h>
#include<stdlib.h>
struct node
{
    int pow;
    int coe;
    struct node *link;
};
void create(struct node **p)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    int c,po,flag;
    *p=temp;
    do
    {
        printf("Enter coeff:\n");
        scanf("%d",&c);
        temp->coe=c;
        printf("Enter power:\n");
        scanf("%d",&po);
        temp->pow=po;
        temp->link=NULL;
        printf("Enter 1 if you want to add more term:\n");
        scanf("%d",&flag);
        if(flag==1)
        {
            temp->link=(struct node *)malloc(sizeof(struct node));
            temp=temp->link;
            temp->link=NULL;
        }


    }while(flag==1);

}
void show(struct node *p)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=p;
    while(temp!=NULL)
    {
        printf("%dx^%d",temp->coe,temp->pow);
        temp=temp->link;
    }
    if(temp!=NULL)
    printf("+");
    printf("\n");
}
void additive(struct node **res,struct node *p1,struct node *p2)
{
     
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    
    temp->link=NULL;
    
    //struct node* p3=(struct node *)malloc(sizeof(struct node));
    //p3->link=NULL;
    //p3->coe=0;
    //p3->pow=0;
    *res=temp;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->pow>p2->pow)
        {
            temp->pow=p1->pow;
            temp->coe=p1->coe;
            p1=p1->link;
        }
        else if(p2->pow>p1->pow)
        {
            temp->pow=p2->pow;
            temp->coe=p2->coe;
            p2=p2->link;
        }
        else 
        {
            temp->pow=(p1->pow);
            temp->coe=p1->coe+p2->coe;
            p1=p1->link;
            p2=p2->link;

        }
       //p3->coe=temp->coe;
       //p3->pow=temp->pow;
       //p3->link=temp;
        

       if(p1!=NULL&&p2!=NULL)
        {
            struct node*temp=(struct node *)malloc(sizeof(struct node)); 
            temp=temp->link;
            temp->link=NULL;

        }
    }
   
    while(p1!=NULL||p2!=NULL)
    {
        temp->link=(struct node *)malloc(sizeof(struct node));
        temp=temp->link;
        temp->link=NULL;
        
     if(p1!=NULL) 
        {
            temp->pow = p1->pow;
            temp->coe = p1->coe;
            p1 = p1->link;
        }
      else if(p2!=NULL) 
        {
            temp->pow = p2->pow;
            temp->coe = p2->coe;
            p2 = p2->link;
        }
      // p3->coe=temp->coe;
       //p3->pow=temp->pow;
       //p3->link=temp;
    }

    

    
}

int main()
{
    struct node *p1, *p2, *res;
    printf("Create polynomial 1:\n");
    create(&p1);
    show(p1);
    printf("create polynomial 2:\n");
    create(&p2);
    show(p2);
    printf("Additive polynomial is:\n");
    additive(&res,p1,p2);
    
    show(res);
    return 0;

}
