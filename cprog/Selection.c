#include "stdio.h"

int main(int argc, char const *argv[])
{
	int l=0,t=0,min=0;
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
		min=i;
		for(int j=i+1;j<l;j++)
		{
			if(arr[min]>arr[j])
				min=j;
		}
			t=arr[min];
			arr[min]=arr[i];
			arr[i]=t;
	}
	printf("%s\n","Sorted array:" );
	for(int i=0;i<l;i++)
		printf("%d  ",arr[i]);
	printf("\n");
	return 0;
}