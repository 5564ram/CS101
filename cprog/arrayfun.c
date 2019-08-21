#include <stdio.h>
int SimpleArraySum(int x[], int n) 
{
  int i, sum = 0;
  
  for (i = 0; i < n; ++i) 
  {
    sum += x[i];
  }
  return sum;
}
int main() 
{
  int y = 0;
  int n,i;
  printf("Enter n:\n");
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n; ++i)
   {
    scanf("%d", &a[i]);
    printf("\n");

  }
  y = SimpleArraySum(a, n);
  printf("\n");
  printf("%d",y);
}
