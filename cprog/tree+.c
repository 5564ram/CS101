#include "stdio.h"
#include <unistd.h>
#include "stdlib.h"

struct node
{
	int info;
	struct node *lptr;
	struct node *rptr;
};

struct node *root;


int n=0;

void create(int[]);
void printInorder(struct node *);
void printPostorder(struct node *);
void printPreorder(struct node *);
void del(int);

int main(int argc, char const *argv[])
{
	printf("%s\n","1st line - no. of elements to be inserted(n)\nn lines follow providing elements for the tree:" );
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	root=(struct node*)(malloc(sizeof(struct node)));
	root->lptr=NULL;
	root->rptr=NULL;
	create(arr);
    while(1)
    {
        int choice=0;
        printf("Enter\n1 To print In-order traversal\n2 To print Pre-order traversal\n3 To print Post-order traversal\n4 To delete a node");
        scanf("%d",&choice);
        switch(choice)
        { 
            
            case 1:printInorder(root);
	               printf("\n");break;
            case 2:printPreorder(root);
          	       printf("\n");break;
            case 3:printPostorder(root);
	               printf("\n");break;
            case 4:printf("Enter element to be deleted:");
                   int x=0;
                   scanf("%d",&x);
                   del(x);break;
            default:exit(1);
        }
    }
	return 0;
}

void create(int a[])
{
	root->info=a[0];
	for(int i=1;i<n;i++)
	{
		int x=a[i];
		struct node *ptr;
		ptr=(struct node*)(malloc(sizeof(struct node)));
		ptr->info=x;

		struct node *t;
		t=root;

		while(1)
		{
			if(x<(t->info))
			{
				if(t->lptr==NULL)
				{
					t->lptr=ptr;
					break;
				}	
				else
					t=t->lptr;
			}
			else if(x>(t->info))
			{
				if(t->rptr==NULL)
				{
					t->rptr=ptr;
					break;
				}	
				else
					t=t->rptr;
			}
		}
	}
}

void printInorder(struct node *p ) 
{ 
     if (p == NULL) 
          return; 
  
     printInorder(p->lptr); 
  
     
     printf("%d ", p->info);   
  
     
     printInorder(p->rptr); 
} 

void printPreorder(struct node *p ) 
{ 
     if (p == NULL) 
          return; 
  
	printf("%d ", p->info);

     printInorder(p->lptr);    
     
     printInorder(p->rptr); 
} 

void printPostorder(struct node *p ) 
{ 
     if (p == NULL) 
          return; 
  
     printInorder(p->lptr);    
  
     printInorder(p->rptr); 

      printf("%d ", p->info);
} 

void del(int x)
{
    struct node *par;
    struct node *suc;
    struct node *sucpar;
    struct node *loc;
    loc=root;
    while(loc->info!=x)
    {
    	par=loc;
        if(x>loc->info)
            loc=loc->rptr;
        else if(x<loc->info)
            loc=loc->lptr;
    }
    if(loc->lptr!=NULL && loc->rptr==NULL)
    {
    	if(par->rptr==loc)
    		par->rptr=loc->lptr;
    	else
    		par->lptr=loc->lptr;
    }
    else if (loc->lptr==NULL && loc->rptr!=NULL)
    {
    	if(par->rptr==loc)
    		par->rptr=loc->rptr;
    	else
    		par->lptr=loc->rptr;
    }
    else if(loc->lptr==NULL && loc->rptr==NULL)
    {
    	if(par->rptr==loc)
    		par->rptr=NULL;
    	else
    		par->lptr=NULL;
    }
    else
    {
    	suc=loc->rptr;
    	sucpar=suc;
    	while(suc->lptr!=NULL)
    	{
    		sucpar=suc;
    		suc=suc->lptr;
    	}
 		loc->info=suc->info;
 		sucpar->lptr=suc->rptr;
    }
}

