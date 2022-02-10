#ifndef POLY_H_INCLUDED
#define POLY_H_INCLUDED
static int p=0,index=0;
int boundary[1000][2];
int polynomial[30500][2];
int mult[2000000];
//takes input of a polynomial in the array polynomial[30500][2] and marks the starting and ending positions in the array boundary[1000][2]
//it places a sentinel -1 in front of every polynomial to distinguish them from each other
void getpolynomial()
{
    printf("Enter required polynomial%d:\n",p+1); int u=0;
    boundary[p][0]=index; polynomial[index][0]=-1; polynomial[index++][1]=-1;
    while(1)
    {
    printf("(1)if more terms are there\n(2)polynomial finished\n");
    int i; scanf("%d",&i);
    switch(i)
    {
    case(1):
        {
            printf("Enter coefficient and exponents:\n");
            scanf("%d %d",&polynomial[index][0],&polynomial[index][1]);
            index++; break;
        }
    case(2):
        {
            boundary[p++][1]=index-1; u++; break;
        }
    }
    if(u==1)
        break;
    }
    return;
}
//It has two integer formal parameters representing the number of polynomials, accordingly they exist in the polynomial[30500][2] array
//it outputs the sum of two polynomials,ith and jth one, if they exist.
void addition(int i,int j)
{
    if(i>p)
    {
        printf("polynomial(%d) doesn't exist\n",i); return;
    }
    if(j>p)
    {
        printf("polynomial(%d) doesn't exist\n",j); return;
    }
    int f1,f2,l1,l2;
    f1=boundary[i-1][0]; f2=boundary[j-1][0]; l1=boundary[i-1][1]; l2=boundary[j-1][1];
    f1++; f2++;
    int k,l;
    k=f1; l=f2;

    while((k<=l1)&&(l<=l2))
    {
        if(polynomial[k][1]<polynomial[l][1])
        {
            printf("+(%dx^%d)",polynomial[l][0],polynomial[l][1]); l++; continue;
        }
        if(polynomial[k][1]==polynomial[l][1])
        {
            printf("+(%dx^%d)",polynomial[l][0]+polynomial[k][0],polynomial[l][1]); l++; k++; continue;
        }
        if(polynomial[k][1]>polynomial[l][1])
        {
            printf("+(%dx^%d)",polynomial[k][0],polynomial[k][1]); k++;
        }
    }
    while(k<=l1)
    {
        printf("+(%dx^%d)",polynomial[l][0],polynomial[k][1]); k++;
    }
    while(l<=l2)
    {
        printf("+(%dx^%d)",polynomial[l][0],polynomial[l][1]); l++;
    }
    printf("\n");
}
//It has two integer formal parameters representing the number of polynomials, accordingly they exist in the polynomial[30500][2] array
//it outputs the multiplication of ith and jth polynomials if they exist.
void multiply(int i,int j)
{
    if(i>p)
    {
        printf("polynomial(%d) doesn't exist\n",i); return;
    }
    if(j>p)
    {
        printf("polynomial(%d) doesn't exist\n",j); return;
    }
    int f1,f2,l1,l2;
    f1=boundary[i-1][0]; f2=boundary[j-1][0]; l1=boundary[i-1][1]; l2=boundary[j-1][1];
    f1++; f2++;
    int k,l;
    k=f1; l=f2;
    for(j=0; j<2000000; j++) mult[j]=0;
    for( ; k<=l1; k++)
    {
        for(l=f2; l<=l2; l++)
            mult[polynomial[l][1]+polynomial[k][1]]+=(polynomial[l][0]*polynomial[k][0]);
    }
    for(j=0; j<2000000; j++)
    {
        if(mult[j]==0) continue;
        else
            printf("+(%dx^%d)",mult[j],j);
    }
    printf("\n");
}
//It has one integer formal parameter 'i' representing the number of polynomial, accordingly they exist in the polynomial[30500][2] array
//the second formal parameter 'j' is the integer which we need to multiply with the given polynomial
//it outputs a polynomial multiplying coefficients of ith polynomial with the given integer j, if exist.
void cmultiply(int i,int j)
{
     if(i>p)
    {
        printf("polynomial(%d) doesn't exist\n",i); return;
    }
    int f1,l1;
    f1=boundary[i-1][0]; l1=boundary[i-1][1];
    f1++;
    while(f1<=l1)
    {
        printf("+(%dx^%d)",j*polynomial[f1][0],polynomial[f1][1]); f1++;
    }
    printf("\n");
}
//It has one integer formal parameter 'i' representing the number of polynomial, accordingly it exist in the polynomial[30500][2] array
//it checks whether the ith polynomial is zero or not
void check(int i)
{
     if(i>p)
    {
        printf("polynomial(%d) does't exist\n",i); return;
    }
    int f1,l1;
    f1=boundary[i-1][0]; l1=boundary[i-1][1];
    if(f1==l1)
        printf("polynomial(%d) is Zero polynomial\n",i);
    else
        printf("polynomial(%d) is not a Zero polynomial\n",i);
}
//It has one integer formal parameter 'i' representing the number of polynomial, accordingly it exist in the polynomial[30500][2] array
//it outputs degree of the ith polynomial
void degree(int i)
{
     if(i>p)
    {
        printf("polynomial(%d) doesn't exist\n",i); return;
    }
    int f1,l1;
    f1=boundary[i-1][0]; l1=boundary[i-1][1];
    if(f1==l1)
    {
        printf("polynomial(%d) is Zero polynomial and has degree 0\n",i);
    }
    else
        printf("polynomial(%d) has degree %d\n",i,polynomial[f1+1][1]);
}
#endif 
