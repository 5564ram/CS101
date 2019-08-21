

#include "stdio.h"
#define MAX_VAL 32,767
int main(int argc, char const *argv[])
{
	int m=0;
	scanf("%d",&m);
	int Q[m][m];
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
		scanf("%d",&Q[i][j]);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(Q[i][j]==0)
				Q[i][j]=MAX_VAL;
		}
	}
	for(int k=0;k<m;k++)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m;j++)
			{
				Q[i][j]=Q[i][j]<(Q[i][k]+Q[k][j])?Q[i][j]:(Q[i][k]+Q[k][j]);
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",Q[i][j]);
		}
		printf("\n");
	}
	return 0;
}
