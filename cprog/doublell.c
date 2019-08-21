  #include "stdio.h"                                                              
  #include "stdlib.h"                                                             
  void insert(int,int);                                                           
  void delete(int); 
  void showList();                                                              
  void createList(int);                                                           
  struct node                                                                     
  {                                                                               
       int info;                                                                   
      struct node *prev;                                                          
      struct node *next;                                                          
  };                                                                              
  struct node *start;                                                             
  struct node *ptr;    
  int n=0;//denotes length of linked-list                                                          
  void main()                                                                          
  {     
  		int choice =0,pos,data;                                                 
 		ptr=(struct node*)(malloc(sizeof(struct node)));                                                                     
      printf("Enter the no. of node you want to create:" );
 		scanf("%d",&n);
 		createList(n);
 		while(1){
 		printf("\n\nEnter \n1 To showList\n2 To insert a new node\n3 To delete a node\n");
 		scanf("%d",&choice);
 		switch(choice)
 		{
 			case 1:showList();break;
 			case 2:pos=0,data=0;
 					printf("Enter position:");
 					scanf("%d",&pos);
 					printf("Enter data:");
 					scanf("%d",&data);
 					insert(pos,data);
 					break;
 			case 3:pos=0;
 				printf("Enter position:");
 				scanf("%d",&pos);
 				delete(pos);
 				break;
 			default:exit(0);
 		}}
 	}
 	void createList(int x)
 	{
 		int i=1,data=0;
 		for( ;i<=x;i++)
 		{
 			struct node *p;
 			p=(struct node*)(malloc(sizeof(struct node)));
 			printf("Enter data:");
 			scanf("%d",&data);
 			if(i==1)
 			{
 				start=p;
 				start->info=data;
 				start->prev=NULL;
 				ptr=p;
 			}
 			else if(i==x)
 			{
 				ptr->next=p;
 				p->next=NULL;
 				p->prev=ptr;
 				p->info=data;
 			}
 			else 
 			{
 				p->info=data;
 				p->prev=ptr;
 				ptr->next=p;
 				ptr=p;
 			}

 		}
 	}
 	void showList()
 	{
 		ptr=start;
 		while(ptr!=NULL)
 		{
 			printf("%d ",(ptr->info));
 			ptr=ptr->next;
 		}
 	}
 	void insert(int idx,int d)
 	{
 		struct node *p;
 		int i=0;
 		p=(struct node*)(malloc(sizeof(struct node)));
 		p->info=d;
 		if(idx==0)
 		{
 			p->next=start;
 			p->prev=NULL;
 			start->prev=p;
 			start=p;
 		}
 		else if(idx==(n+1))
 		{
 			ptr=start;
 			while((ptr->next)!=NULL)
 			{
 				ptr=ptr->next;
 			}
 			p->prev=ptr;
 			ptr->next=p;
 			p->next=NULL;
        }
        else
        {
        	struct node *temp;
        	for(i=1;i<=idx;i++)
        	{
        		if(i==1)
        			ptr=start;
        		else
        			ptr=ptr->next;
        	}
        	temp=ptr->prev;
        	p->next=ptr;
        	ptr->prev=p;
        	p->prev=ptr->prev;
        	temp->next=p;
        }

 		n++;
 	}
 	void delete(int idx)
 	{
 		if(idx==1)
 		{
 			struct node *temp;
 			temp=start->next;
 			temp->prev=NULL;
 			start=temp;
 		}
 		else if(idx==n)
 		{
 			ptr=start;
 			while((ptr->next)!=NULL)
 			{
 				ptr=ptr->next;
 			}
 			struct node *temp;
 			temp=ptr->prev;
 			ptr=NULL;
 			temp->next=NULL;
 		}
 		else
 		{
 			int i;
 			struct node *temp;
        	for(i=1;i<=idx;i++)
        	{
        		if(i==1)
        			ptr=start;
        		else
        			ptr=ptr->next;
        	}
        	temp=ptr->prev;
        	temp->next=ptr->next;
        	(ptr->next)->prev=temp;
 		}
 	}