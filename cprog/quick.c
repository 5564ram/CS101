#include "stdio.h"
void quick(int[],int,int);
int partition(int[],int,int);
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
	quick(arr,0,l-1);
	printf("%s\n","Sorted array:" );
	for(int i=0;i<l;i++)
		printf("%d  ",arr[i]);
	printf("\n");
	return 0;
}

void quick(int arr[],int low,int up)
{
	int pivloc;
	if(low>=up)
		return ;
	pivloc=partition(arr,low,up);
	quick(arr,low,pivloc-1);
	quick(arr,pivloc+1,up);
}

int partition(int arr[],int low,int up)
{
	int temp,i,j,pivot,t=0;
	i=low;
	j=up;
	pivot=arr[low];
	while(i<=j)
	{
		while(arr[i]<=arr[pivot] && i<up)
			i++;
		while(arr[j]>pivot)
			j--;
		if(i<j)
		{
			t=arr[j];
			arr[j]=arr[i];
			arr[i]=t;
			i++;
			j--;
		}
		else
			i++;
	}
	arr[low]=arr[j];
	arr[j]=pivot;
	return j;
}