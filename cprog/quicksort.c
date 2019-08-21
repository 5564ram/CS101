#include<stdio.h>
int partition(int a[] ,int ,int );
void quicksort(int a[],int low,int up)
{
    int n=up;
    int pl;
    if(low >= up)
    return;
    else
    
    pl=partition(a,low,up);
    quicksort(a,low,pl-1);
    quicksort(a,pl+1,up);
    
   
}
int partition(int a[],int low, int up)
{
    
    int temp,i,j,pivot;
    pivot=a[low];
    i=low+1;
    j=up;
    while(i<=j)
    {
        while(a[i]<pivot && i<up)
        ++i;
        while(a[j]>pivot)
        --j;
        if(i<j)
        {
            temp=a[i];a[i]=a[j];a[j]=temp;
            i++;
            j--;
        }
        else
        {
            i++;
        }
        
    }
    a[low]=a[j];
    a[j]=pivot;
    return j;
}
int main()
{
    int n,j=0;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; ++i)
    {
        printf("Enter the element %d:",i+1);
        scanf("%d",&a[i]);

    }
    quicksort(a,j,n-1);
    for(int i=0; i<n; ++i)
    printf("%d\t",a[i]);
    return 0;
}