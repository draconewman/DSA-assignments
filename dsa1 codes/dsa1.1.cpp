#include <stdio.h>
#include <stdlib.h>
 
long long int b=1;int s=1; //declare large integer and integer variable
int fact(long long int n) //function for factorial
{
    n++;b*=n;s*=n;
    if(b==s) //checking condition for overflowing
    {
        int j;j=fact(n); //recursion
    }
    else
        return(n);
}

int main()
{
    long long int lp=1,n=1;int sp=1,ans;
    do
    {
        sp*=n;lp*=n;n++;
    }while(sp==lp); //checking condition for overflowing
    printf("iterative-> %d\n",n-1); //print iteratively
    ans=fact(1);
    printf("recursive-> %d\n",ans); //print recursively
    return 0;
}
