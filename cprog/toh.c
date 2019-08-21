#include<stdio.h>
void toh(int n,char f,char l,char m)
{
    if(n==1)
    {
    printf("move disk 1 from %c to %c:\n",f,l);
    return ;
     }
    toh(n-1,f,m,l);
    printf("move disc %d from %c to %c\n",n,f,l);
    toh(n-1,m,l,f);

}

int main()
{
    int n=2;
   toh(n,'A','C','B');
   return 0;
}
