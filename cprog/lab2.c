#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct poly
{
    int coef;
    int pow;
    struct poly* next;
};
void menu()
{
printf("    POLYNOMIAL ADDITION PROGRAM    \n");
}
void create_poly(struct poly ** p) 
{
    int flag;
    int coeff, pow;
    struct poly * temp;
    temp = (struct poly *) malloc(sizeof(struct poly));
    *p = temp;
    do {
        printf("\nEnter Coeff:");
        scanf("%d", &coeff);
        temp->coef = coeff;
        printf("\nEnter Pow:");
        scanf("%d", &pow);
        temp->pow = pow;
        temp->next = NULL;
        printf("\n enter Y=1 for more element: \n");
        scanf("%d", &flag);
        if(flag==1) {
            temp->next = (struct poly *) malloc(sizeof(struct poly));
            temp = temp->next;
            temp->next = NULL;
        }
    } while (flag==1);
}
void display_poly(struct poly *p) 
{
    printf("\nThe polynomial expression is:\n");
    struct poly * temp;
    temp = (struct poly *) malloc(sizeof(struct poly));
    temp=p;
    while(temp != NULL)
     {
        printf("%dx^%d", temp->coef, temp->pow);
        temp = temp->next;
        if(temp != NULL)
            printf(" + ");
    }
}
void add_poly(struct poly **res, struct poly *poly1, struct poly *poly2)
{
    struct poly * temp;
    temp = (struct poly *) malloc(sizeof(struct poly));
    temp->next=NULL;
    *res = temp;
    while(poly1 && poly2)
     {
        if (poly1->pow > poly2->pow) 
        {
            temp->pow = poly1->pow;
            temp->coef = poly1->coef;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) 
        {
            temp->pow = poly2->pow;
            temp->coef = poly2->coef;
            poly2 = poly2->next;
        }
        else {
            temp->pow = poly1->pow;
            temp->coef = poly1->coef + poly2->coef;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if(poly1 && poly2) {
            temp->next = (struct poly *) malloc(sizeof(struct poly));
            temp = temp->next;
            temp->next = NULL;
        }
    }
    while(poly1 || poly2) 
    {   
        temp->next = (struct poly *) malloc(sizeof(struct poly));
        temp = temp->next;
        temp->next = NULL;
        if(poly1) 
        {
            temp->pow = poly1->pow;
            temp->coef = poly1->coef;
            poly1 = poly1->next;
        }
        if(poly2) 
        {
            temp->pow = poly2->pow;
            temp->coef = poly2->coef;
            poly2 = poly2->next;
        }
    }

}
int main()
{
    struct poly* p1, * p2, * res;
    int choice;
    menu();
    printf("\nCreate polynomial 1.\n");
    create_poly(&p1);
    printf("\nPolynomial 1:\n");
    display_poly(p1);
    printf("\nCreate polynomial 2.\n");
    create_poly(&p2);
    printf("\nPolynomial 2:\n");
    display_poly(p2);
    do{
        printf("\nEnter 1 for addition.\n");
        
        printf("Enter 2 to exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {
                    printf("\nLets add the two polynomials:\n");
                    add_poly(&res, p1, p2);
                    printf("\n\n");
                    display_poly(p1);
                    display_poly(p2);
                    display_poly(res);
                    break;
                }
             case 2:
                {
                    printf("Exiting!");
                    exit(0);
                }
            default:
                printf("Enter choice again!");
        }

    }while(choice!=2);
    return 0;
}



