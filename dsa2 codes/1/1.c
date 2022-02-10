#include <stdio.h>
#include <stdlib.h>
#include "poly.h"
int main()
{
    while(1)
    {
        int u=0;
        printf("(1)Enter polynomial\n(2)add\n(3)Multiply\n(4)multiply by constant\n(5)checking zero polynomial\n(6)find degree\n(7)exit\n");
        int choice;scanf("%d",&choice);
        switch(choice)
        {
        case(1):
            {
                getpolynomial(); break;
            }
        case(2):
            {
                printf("Enter number of two polynomials you want to add\n");
                int p,q; scanf("%d %d",&p,&q);
                addition(p,q); break;
            }
        case(3):
            {
                 printf("Enter number of two polynomials you want to multiply\n");
                int p,q; scanf("%d %d",&p,&q);
                multiply(p,q); break;
            }
        case(4):
            {
                printf("Enter number of polynomial you want to multiply\n");
                int p,q; scanf("%d",&p); printf("Enter the constant\n");
                scanf("%d",&q);
                cmultiply(p,q); break;
            }
        case(5):
            {
                printf("Enter number of polynomial you want to check\n"); int p; scanf("%d",&p); check(p); break;
            }
        case(6):
            {
                printf("Enter number of polynomial you want to check its degree\n"); int p; scanf("%d",&p); degree(p); break;
            }
        case(7):
            {
                u++; break;
            }
        }
        if(u==1)
            break;
    }
    return 0;
}
