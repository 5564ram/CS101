#include<stdio.h>
#include<stdlib.h>
struct node
{
  int coeff;
  int power;
  struct node *link;

} *start1,*start2;
int main()
{
    int n,m;
    struct node *p1=(struct node *)malloc(sizeof(struct node));
    printf(" enter no of term in polynomial1:\n");
    scanf("%d",&n);
    createlist(n);
    printf(" enter no of term in polynomial2:\n");
    scanf("%d",&m);
    createlist(m);

}
void createlist(int n)
{
    struct node *ptr=(struct node*)
}


