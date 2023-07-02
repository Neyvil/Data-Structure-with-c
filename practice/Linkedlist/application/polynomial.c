#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coeff;
    int power;
    struct node *next;
} ns;
ns *createnode(int x, int pow)
{
    ns *term = (ns *)malloc(sizeof(ns));
    term->coeff = x;
    term->power = pow;
    term->next = NULL;
    return term;
}
ns *addterm(ns *poly, int x, int pow)
{
    ns *newterm = createnode(x, pow);
    ns *ptr = poly;
    if (poly == NULL)
    {
        poly = newterm;
        return poly;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newterm;
    return poly;
}
ns *addpolynomial(ns *poly1, ns *poly2)
{
    ns *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->power != poly2->power && (poly1->power > poly2->power))
        {
            result=addterm(result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        }
        else if (poly1->power != poly2->power && (poly1->power < poly2->power))
        {
            result=addterm(result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }
        else
        {
            int sumcoeff = poly1->coeff + poly2->coeff;
            result=addterm(result, sumcoeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
}
void display(ns *result)
{
    ns *ptr = result;
    while (ptr != NULL)
    {
        printf("%dx^%d ", ptr->coeff, ptr->power);
        ptr = ptr->next;
    }
}
int main()
{
    ns *poly1 = NULL;
    poly1 = addterm(poly1, 4, 5);
    poly1 = addterm(poly1, 6, 4);
    poly1 = addterm(poly1, 9, 3);
    poly1 = addterm(poly1, 2, 2);

    ns *poly2 = NULL;
    poly2 = addterm(poly2, 8, 5);
    poly2 = addterm(poly2, 2, 4);
    poly2 = addterm(poly2, 4, 3);
    poly2 = addterm(poly2, 1, 2);

    ns *result = addpolynomial(poly1, poly2);
    printf("Resulted polynomial:");
    display(result);
    return 0;
}