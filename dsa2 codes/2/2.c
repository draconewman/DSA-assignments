#include <stdio.h>
#include <stdlib.h>
#include "sparsematrix.h"
int main()
{
    while(1)
    {
        int i;printf("(1)Add two matrices\n(2)Get transpose of a matrices\n(3)Multiply two matrices\n(4)Exit\n");scanf("%d",&i);
        switch(i)
            {
            case(1):
                {
                    //Input of matrix 1
                    printf("Enter no of rows\n");
                    int row1;scanf("%d",&row1);
                    printf("Enter no of columns\n");
                    int col1;scanf("%d",&col1);
                    printf("Enter number of elements in your matrix:\n");
                    int tot1;scanf("%d",&tot1);
                    int a[tot1][3];
                    getdata(a[0],tot1);
                    //Inputr of matrix 2
                    printf("Enter no of rows\n");
                    int row2;scanf("%d",&row2);
                    printf("Enter no of columns\n");
                    int col2;scanf("%d",&col2);
                    printf("Enter number of elements in your matrix:\n");
                    int tot2;scanf("%d",&tot2);
                    int b[tot2][3];
                    getdata(b[0],tot2);
                   // add two matrices
                   if((row1!=row2)||(col1!=col2))
                   {
                       printf("Addition is invalid\n");break;
                   }
                    add(a[0],row1,col1,b[0],tot1,tot2);
                    break;
                }
            case(2):
                {
                    transpose();
                    break;
                }
            case(3):
                {
                    //Input of matrix 1
                    printf("Enter no of rows\n");
                    int row1;scanf("%d",&row1);
                    printf("Enter no of columns\n");
                    int col1;scanf("%d",&col1);
                    printf("Enter number of elements in your matrix:\n");
                    int tot1;scanf("%d",&tot1);
                    int a[tot1][3];
                    getdata(a[0],tot1);
                    //Inputr of matrix 2
                    printf("Enter no of rows\n");
                    int row2;scanf("%d",&row2);
                    printf("Enter no of columns\n");
                    int col2;scanf("%d",&col2);
                    printf("Enter number of elements in your matrix:\n");
                    int tot2;scanf("%d",&tot2);
                    int b[tot2][3];
                    getdata(b[0],tot2);
                    //Multiplying two matrices
                    if((row2!=col1))
                    {
                       printf("Multiplication is invalid\n");break;
                    }
                    mult(a[0],row1,col1,tot1,b[0],row2,col2,tot2);
                    break;
                }
            case(4):
                {
                    return(0);
                }
            }
    }
}

