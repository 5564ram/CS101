#include "stdio.h"

int main(int argc, char const *argv[])
{
	int l=0,t=0;
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
		for(int j=0;j<l-i-1;j++)
		{
			if(arr[j+1]<arr[j])
			{
				t=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=t;
			}
		}
	}
	printf("%s\n","Sorted array:" );
	for(int i=0;i<l;i++)
		printf("%d  ",arr[i]);
	printf("\n");
	return 0;
}