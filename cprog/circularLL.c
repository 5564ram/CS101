#include "stdio.h"
#include "string.h"
#include "stdlib.h"
struct node
{
    struct node *next;
    char ch[50];
};
void createList();
void showList();
struct node *start;
struct node *ptr;
int n=0;

void main()
{
    ptr=(struct node*)(malloc(sizeof(struct node)));
    printf("Enter no. of nodes you want to create:");
    scanf("%d",&n);
    createList();
    showList();
}
void createList()
{
        int i=0;
    for( ;i<=n;i++)
    {
      char c[10];

        struct node *p;
        p=(struct node*)(malloc(sizeof(struct node)));

        if(i==0)
            {
                start=p;
                ptr=p;
                strcpy(start->ch,"\0");
				continue;
            }
        else if(i==n)
        {   
               printf("Enter data:");
            scanf("%s",c);			
			strcpy(p->ch,c);
            ptr->next=p;
            p->next=start;
        }
        else
        {
            printf("Enter data:");
            scanf("%s",c);
            strcpy(p->ch,c);
            ptr->next=p;
            ptr=p;

        }
    }
}
void showList()
{

    ptr=start->next;
    while(strcmp(ptr->ch,"\0")!=0)
    {
        printf(" ");
        puts(ptr->ch);
        ptr=ptr->next;
    }
}
void ins_first()
{
	char x[10];
	printf("Enter data:");
	scanf("%s",x);
  	strcpy(start->ch,x);
	struct node *p;
	p=(struct node)(malloc(sizeof(struct node)));
	p->next=start;
	start=p;
	strcpy(start->ch,"\0");
}

	