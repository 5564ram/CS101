#include<stdio.h>
void selectionsort(int a[],int n)
{ int min,temp;
    for(int i=0; i<n; ++i)
    {
         min=i;
        for(int j=i+1; j<n; ++j)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        
    }
    printf("The sorted matrix is:\n");
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
    selectionsort(a,n);
    return 0;
}