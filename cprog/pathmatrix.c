#include "stdio.h"
int main(int argc, char const *argv[])
{
	int m=0;
	scanf("%d",&m);
	int a[m][m],p[m][m],res[m][m],r[m][m];
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
		scanf("%d",&p[i][j]);
	for(int c=1;c<=m;c++)
	{
		if(c==1)
		{
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<m;j++)
				{
					r[i][j]=p[i][j];
					a[i][j]=p[i][j];
					res[i][j]=0;
				}
			}
			continue;
		}
		for(int k=0;k<m;k++)
		{
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<m;j++)
				{
					res[i][j]+=a[i][k]*p[k][j];
				}
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m;j++)
			{
				r[i][j]+=res[i][j];
				a[i][j]=res[i][j];
				res[i][j]=0;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d ",r[i][j] );
		printf("%s\n","" );
	}
	return 0;
}