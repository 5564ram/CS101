

#include "stdio.h"

int main(int argc, char const *argv[])
{
	int r=0,c=0,i=0,j=0,n=0;
	printf("%s\n","Enter dimension of matrix:");
	scanf("%d x %d",&r,&c);
	printf("%s\n","Enter elements of matrix(row-wise):" );
	int s[r][c];
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			scanf("%d",&s[i][j]);
			if(s[i][j]!=0)
				n++;
		}
	printf("%s\n%d\t%d\t%d\n","Three-tuple representation:",r,c,n);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		if(s[i][j]!=0)
			printf("%d\t%d\t%d\n",i,j,s[i][j]);
	return 0;
}
