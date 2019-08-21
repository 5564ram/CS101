#include<stdio.h>
void insertionsort(int a[],int n)
{
    int k;
    for(int i=0; i<n; ++i)
    {
         k=a[i];
        for(int j=i-1; j>=0 && k<a[j];--j)
        a[j+1]=a[j];
        a[j+1]=k;
    }
    printf("The sorted array is:\n");
    for(int i=0; i<n; ++i)
       printf("%d\t",a[i]);
}

int main()
{
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; ++i)
    {
        printf("Enter the element %d:",i+1);
        scanf("%d",&a[i]);

    }
    insertionsort(a,n);
    return 0;
}