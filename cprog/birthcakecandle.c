#include <stdio.h>
int birthdaycakecandle(int a[], int n) 
{
  int i, height = 0, k = 0;
  for (i = 0; i < n; ++i)
   {
    scanf("%d", &a[i]);
    printf("\t");
   }
  for (i = 0; i < n; ++i) 
  {
    if (a[i] > height)
      height = a[i];
  }
  for (i = 0; i < n; ++i)
    {
    if (a[i] == height)
      ++k;
    }
  return k;
}
int main() 
 {
  int n, height;
  scanf("%d", &n);
  printf("\n");
  int a[n];
  height = birthdaycakecandle(a, n);
  printf("%d", height);
  return 0;
 }