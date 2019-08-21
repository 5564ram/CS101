#include<stdio.h>
int fibo(int n)
{
    if(n==1)
    return 1;
    else if(n==2)
    return 1;
    else
    {
      return(fibo(n-1)+fibo(n-2));

    }
    
}
int main()
{
    int a,k;
    printf("Enter the element of series:\n");
    scanf("%d",&a);
    for(int i=1; i<=a; ++i)
    {
     k=fibo(i);
     printf("%d\t",k);
    }
    return 0;

}
