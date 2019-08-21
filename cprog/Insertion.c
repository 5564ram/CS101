#include "stdio.h"

int main(int argc, char const *argv[])
{
	int l=0,t=0,k=0,j=0;
	printf("%s\n","Enter size of the array:");
	scanf("%d",&l);
	int arr[l];
	printf("%s\n","Enter elements of array:" );
	for(int i=0;i<l;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<l;i++)
	{
		k=arr[i];
		for(j=i-1;j>=0 && k<arr[j];j--)
			arr[j+1]=arr[j];
		arr[j+1]=k;
	}
	printf("%s\n","Sorted array:" );
	for(int i=0;i<l;i++)
		printf("%d  ",arr[i]);
	printf("\n");
	return 0;
}