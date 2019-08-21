#include<stdio.h>
void bubblesort(int a[],int n)
{
    int temp;
    for(int k=0; k<n-1; ++k)
    {
        for(int j=k+1; j<n; ++j)
        {
            if(a[k]>a[j])
            {
                temp=a[k];
                a[k]=a[j];
                a[j]=temp;
            }
        }
    }
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
        scanf("%d",&a[i]);

    }
    bubblesort(a,n);
    return 0;
}