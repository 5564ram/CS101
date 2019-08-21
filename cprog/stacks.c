#include<stdio.h>
#include<stdlib.h>
int top=0,size;
void push(int a[],int item)
{
    if(top==size-1)
    printf("Overflow!!\n");
    else
    {
      a[top]=item;
      top++;

    }
    
}
void pop(int a[])
{
    if(top<=0)
    printf("Underflow!!");
    else
    {
      printf("item=%d ",a[top-1]);
      top--;
    }
    
}
void peep(int a[],int loc)
{
    printf("%d",a[top-loc+1]);
}
void main()
{
    int choice,loc,data;
    printf("Enter size of stacks:\n");
    scanf("%d",&size);
    int a[size];
    printf("Enter the no element to insert in stacks:\n");
    scanf("%d",&top);
    for(int i=0; i<top; ++i)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter 1 for push:\n");
    printf("Enter 2 for pop:\n");
    printf("Enter 3 for peep:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:              printf("Enter element to push:\n");
                            scanf("%d",&data);
                            push(a,data);
                            break;
        case 2:             pop(a);
                            break;
        case 3:             printf("Enter loc to peep:\n");
                           scanf("%d",&loc);
                           peep(a,loc);
                           break;
        dafault:         exit(1);
    }
    for(int i=0; i<top; ++i)
    {
        printf("%d\t",a[i]);
    }
}
