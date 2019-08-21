#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,j=0,small,temp,count;
    scanf("%d",&n);
    int a[n+(2*10^5)];
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int b[m];
    for(int i=0; i<m; ++i)
    {
        scanf("%d",&b[i]);
    }
    
    for(int i=0; i<m; ++i)
    {
        for(int k=0; k<n; ++k)
        {
            if(b[i]<a[k])
            {
            count=k;
            break;
            }
        }
        for(int j=n+1; j<count; --j)
        {
            a[j]=a[j-1];
        }
        a[count]=b[i];
        printf("%d",j);
    }
  return 0;

}

