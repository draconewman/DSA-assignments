#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    if(a<b)return(b);
    return(a);
}
void maxfilter(int *b,int w,int size)
{
    int j;
    for(j=0;j<size;j++)
    {
        int k,m=-100000000;
        for(k=j;k<j+w;k++)
        {
            m=max(m,b[k]);
        }
        printf("%d ",m);
    }
    printf("\n");
    return;
}
int min(int a,int b)
{
    if(a>b)return(b);
    return(a);
}
void minfilter(int *b,int w,int size)
{
    int j;
    for(j=0;j<size;j++)
    {
        int k,m=100000000;
        for(k=j;k<j+w;k++)
        {
            m=min(m,b[k]);
        }
        printf("%d ",m);
    }
    printf("\n");
    return;
}

int median(int *b,int left,int right,int w)
{
   int s[w];
   int j,k,t;
   for(j=left;j<=right;j++)
    s[j-left]=b[j];
    for(j=0;j<w;j++)
    {
        for(k=j+1;k<w;k++)
        {
            if(s[j]>s[k])
            {
                t=s[j];
                s[j]=s[k];
                s[k]=t;
            }
        }
    }
return(s[w/2]);
}
void medianfilter(int *b,int w,int size)
{
    int j;
    for(j=0;j<size;j++)
    {
      int m,k;
        for(k=j;k<j+w;k++)
        {
            m=median(b,j,j+w-1,w);
        }
        printf("%d ",m);
    }
    printf("\n");
    return;
}
int main()
{

    printf("Enter the number of elements in the array\n");
    int n,j;scanf("%d",&n);
    int a[n];
    printf("Enter elements:\n");
    for(j=0;j<n;j++)
        scanf("%d",(a+j));
    while(1)
    {
        printf("(1)Continue to get the facilities of the filters\n(0)Exit\n");int c;
        scanf("%d",&c);
        if(c==0)
            return(0);
        printf("Enter window size\n");
        int w,x;scanf("%d",&w);
        x=w/2;
        int b[n+(2*x)];
        for(j=0;j<x;j++)
            b[j]=0;
        for(;j<(n+x);j++)
            b[j]=a[j-x];
        for(;j<n+(2*x);j++)
            b[j]=0;
            while(1)
            {
                printf("(1)Max filter\n(2)Min filter\n(3)Median filter\n(4)change window size\nEnter choice:\n");
                int i,u=0;scanf("%d",&i);
                switch(i)
                {
                case(1):
                    {
                        maxfilter(b,w,n);break;
                    }
                case(2):
                    {
                        minfilter(b,w,n);break;
                    }
                case(3):
                    {
                        medianfilter(b,w,n);break;
                    }
                case(4):
                    {
                        u++;break;
                    }
                }
                if(u==1)break;
            }
    }
    return 0;
}
