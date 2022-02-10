#include <stdio.h>
#include <stdlib.h>

int r=1; //index for function fibo
void fibo(int a,int b,long long int lla,long long int llb) //implement function fibo with large and small integers
{
    if(llb!=b) 
        return;
        r++;
    fibo(b,a+b,llb,lla+llb); //recursion
}

int main()
{

    int a=1,b=1,t=2,n;
	long long int lla=1,llb=1;
	printf("Enter number:\n");
	scanf("%d",&n);
    while(llb==b)
    {
        int x;
		long long int llx;
		llx=llb; //fibonacci steps for iteration
		x=b;
        llb=lla+llb;
        lla=llx;
        b=a+b;
        a=x;
        t++;
        if((t==n)&&(llb==b)) //checking for overflow condition
        {
            printf("%dth fibonacci number is %d\n",n,b);
        }
    }
    if(t<=n)
    {
        printf("%dth fibonacci number can not be determined correctly\n",n);
    }
    printf("iterative-> %d\n",t); //print ans iteratively
    fibo(0,1,0,1);
    printf("recursive-> %d\n",r); //print ans recursively
    return 0;
}
