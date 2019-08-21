
Conversation opened. 1 read message.

Skip to content
Using IIIT Bhubaneswar Mail with screen readers

3 of 138
Sparse
Inbox
x

Satyabrat Panda
Attachments
12:48 PM (54 minutes ago)
to me


7 Attachments

#include "stdlib.h"
#include "stdio.h"

struct node 
{
	int pow;
	int coeff;
	struct node *next;
};

int i,pi=1,len1,len2,j;

struct node *start;
struct node *start1;
struct node *start2;
struct node *res;
struct node *ptr;
void showList(struct node*);
void createList();
void sortList(struct node*,int);
void addPoly();
void main()
{
	printf("For polynomial 1:\n");
	createList();
	start1=start;
	printf("For polynomial 2:\n");
	createList();
	start2=start;
	struct node *p;
	struct node *p1;
	struct node *p2;
	p1=start1;
	int flag=0;
	while(p1!=NULL)
	{
		p2=start2;
		while(p2!=NULL)
		{
			p=(struct node*)(malloc(sizeof(struct node))); 
			p->coeff=(p1->coeff)*(p2->coeff);
			p->pow=(p1->pow)+(p2->pow);
			if(flag==0)
			{
				res=p;
				ptr=p;
				flag++;
			}
			else
			{
				ptr->next=p;
				ptr=p;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	ptr->next=NULL;
	printf("Polynomial 1:\n");
	showList(start1);
	printf("Polynomial 2:\n");
	showList(start2);
	printf("Resultant Polynomial:\n");
	showList(res);
}

void showList(struct node *t)
{
	while(t!=NULL)
	{
		printf("Coeff: %d\n",(t->coeff));
		printf("Power: %d\n",(t->pow));
		t=t->next;
		printf("\n");
	}
}
		


void createList()
{
	int n=0;
	printf("Enter no. of terms of %d poyl nomial:",pi);
	scanf("%d",&n);
	if(pi==1)
		len1=n;
	else
		len2=n;
	for(i=1;i<=n;i++)
	{
		struct node *p;                                
		printf("Term %d\n\nPower:",i);
		p=(struct node*)(malloc(sizeof(struct node))); 
		scanf("%d",&(p->pow));
		printf("Coeff:");
		scanf("%d",&(p->coeff));
		printf("\n");
		if(i==1)
		{
			start=p;
			ptr=p;
		}
		else
		{
			ptr->next=p;
			if(i==n)
				p->next=NULL;
			else
				ptr=p;
		}
	}
	pi++;
}
polyMul.c
Displaying polyMul.c.s