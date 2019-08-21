#include "stdio.h"
#include "stdlib.h"

void ins_front(int[]);
void ins_rear(int[]);
void del_front(int[]);

int f=-1,r=-1,n=0;

void ins_front(int a[])
{
	int x=0;
	printf("%s\n","Enter element to be inserted" );
	scanf("%d",&x);
	if((f==0 && r==n) || (f==r+1))
	{
		printf("%s\n","Overflow");
		return;
	}
	else
	{
		if(f==-1)
		{
			f=0;
			r=0;
		}
		else if(f==0)
		{
			f=n-1;
		}
		else
			f--;
		a[f]=x;
	}
}

void del_front(int a[])
{
	if(f==r && f==-1)
	{
		printf("%s\n","Underflow" );
		return;
	}
	else
	{
		if(f==r)
		{
			f=-1;
			r=-1;
		}
		else if(f==n-1)
		{
			f=0;
		}
		else
			f++;
	}
}

void ins_rear(int a[])
{
	int x=0;
	printf("%s\n","Enter element to be inserted" );
	scanf("%d",&x);
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
		printf("1.To insert at rear \n2.To delete from front \n3.To display\n4.To insert at front\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:ins_rear(arr);
				  break;
			case 2:del_front(arr);
				  break;
			case 3:display(arr);
				  break;
			case 4:ins_front(arr);
				   break;
			default:exit(1);

		}
	}
}