#include "stdio.h"
#include "stdlib.h"

void insert(int,int[]);
void del();
void display(int[]);
int f=-1,r=-1,n=0;

void main()
{
	printf("Enter size of Q:\n");
	scanf("%d",&n);
	int arr[n],j=0,c=0,x=0;
	printf("%s\n","Enter the no. of elements you want to fill:");
	scanf("%d",&j);
	printf("%s\n","Enter data:");
	for(int i=0;i<j;i++)
		scanf("%d",&arr[i]);
	if(j>0)
	{
		f=0;
		r=j-1;
	}
	while(1)
	{
		printf("1.To insert \n2.To delete \n3.To display\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("Enter element to be inserted:");
				  scanf("%d",&x);
				  insert(x,arr);
				  break;
			case 2:del();
				  break;
			case 3:display(arr);
				  break;
			default:exit(1);

		}
	}
}

void insert(int x,int a[])
{
	if((r==(n-1) && f==0) || (f==r+1)) 
	{
		printf("Overflow\n");
		exit(0);
	}
	else
	{
		if(f==r==-1)
		{
			f=0;
			r=0;
		}
		else if(r==n-1)
			r=0;
		else
			r++;
		a[r]=x;
	}
}

void del()
{
	if(f==r && f==-1)
	{
		printf("Underflow\n");
		exit(0);
	}
	else
	{
		if(f==r)
		{
			f=-1;
			r=-1;
		}
		else if(f==n-1)
			f=0;
		else
			f++;
	}
}

void display(int a[])
{
	if(f<r)
	{
		for(int i=f;i<=r;i++)
			printf("%d  ",a[i] );
	}
	else
	{
		for(int i=f;i<n;i++)
			printf("%d  ",a[i]);
		for(int i=0;i<=r;i++)
			printf("%d  ",a[i]);
	}
	printf("\n");
}