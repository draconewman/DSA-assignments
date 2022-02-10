#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int main()
{
    while(1)
    {
        printf("(1)concatenate two strings\n(2)Length of string\n(3)compare two strings\n(4)Exit\n");
        int i,u=0;scanf("%d",&i);
        switch(i)
            {
            case(1):
                {
                    conc();break;
                }
            case(2):
                {
                    len();break;
                }
            case(3):
                {
                    cpr();break;
                }
            case(4):
                {
                   u++;break;
                }
            }
            if(u==1)break;
    }
    return 0;
}
