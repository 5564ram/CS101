#include<stdio.h>
#include<stdlib.h>
int r=-1,f=-1,n;
void insert(int a[],int ele)
{
    if((f==0 && r==n-1)||(f==r+1))
       printf("overflow!!");
       else
       {
           if(f==-1)
           {
               f=r=0;
               a[f]=ele;
               
           }
           else if(r==n-1)
           {
               r=0;
               a[0]=ele;
           }
           else
           {
             ++r;
             a[r]=ele;
           }
           
       }
       
}
void del(int a[])
{
    if(f==-1)
    printf("Underflow!!:\n");
    else
    {
        if(f==0)
        {f=r=-1;}
        else if(f==n-1){f=0;}
        else {++f;}
        
    }
    
}
void display(int a[])
{
  if(f>r)
  {
      for(int i=f; i<n; ++i)
      {
          printf("%d\t",a[i]);
      }
       for(int i=0; i<=r; ++i)
       {
           printf("%d\t",a[i]);
       }
  }
  else
  {
      for(int i=f; i<=r; ++i)
      {
          printf("%d\t",a[i]);
      }
  }
  
}

int main()
{
    int k,ele;
    char ch;
    printf("Enter the no of the term of the q:\n");
    scanf("%d",&n);
    int a[n];
    int term;
    printf("Enter the term\n");
    scanf("%d",&term);
    printf("Enter the element of the q:\n");

    for(int i=0; i<term; ++i)
    {
      scanf("%d",&a[term]);

    }
    if(term>0)
    {
        f=0;
        r=term-1;
    }
   do
    {
        printf("Enter 1:insert\nenter 2:delete\nEnter 3:Display\n");
        scanf("%d",&k);
        switch(k)
        {
            case 1: printf("Enter the element to insert:\n");
                    scanf("%d",&ele);
                    insert(a,ele);
                    break;
            case 2: printf("you want to delete:\n");
                    del(a);
                    break;
            case 3: printf("The display element is:\n");
                    display(a);
                    break;
            default: printf("you want to exit:\n" );
                     exit(0);
        }
        printf("enter y for continue more:\n");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');

    return 0;
}
