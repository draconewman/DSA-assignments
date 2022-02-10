#include <stdio.h>
#include <stdlib.h>
//b is the array where the transformed matrix is going to be stored and m is the matrix to be transformed
//w is the size of the matrix that is to be multiplied
//n is size of m
//transforms m into a matrix b with a coating of 0s of width w/2
void transform(int *b,int *m,int w,int n)
{
    int j,k;
    for(j=0;j<n+(2*(w/2));j++)
    {
        for(k=0;k<n+(2*(w/2));k++)
        {
            *(b+j*((n+(2*(w/2))))+k)=0;
        }
    }
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
            *(b+(j+w/2)*(n+(2*(w/2)))+k+w/2)=*(((m+j*n))+k);
        }
    }
}
//b is the transformed matrix and m is the matrix to be multiplied
//w is the size of the matrix m
//n is size of original matrix
void mult(int *b,int *m,int w,int n)
{
    int j,k,l,ans[n][n],a;
    for(j=w/2;j<n+(w/2);j++)
    {
        for(k=w/2;k<n+(w/2);k++)
        {
            a=0;
            for(l=0;l<w;l++)
            {
                a+=*(b+(j*(n+(2*(w/2))))+(k-(w/2)+l))*(*(m+(l*(w)+(w/2))));
            }
            ans[j-(w/2)][k-(w/2)]=a;
        }
    }
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
        printf("%d\t",ans[j][k]);
        }
        printf("\n");
    }
}

int main()
{   int n;
    printf("Enter size of the square matrix:\n");
    scanf("%d",&n);
    printf("Enter elements of the %d*%d square matrix:\n",n,n);
    int m[n][n];
    printf("Do you want to input the large matrix?(Y/N)\n");
    char choice;
    scanf(" %c",&choice);
    if(choice=='N')
    {
    FILE *f;
    f=fopen("random numbers","rb");
    int j,k;
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
            fscanf(f,"%d",&m[j][k]);
        }
    }
    fclose(f);
    }
    else if(choice=='Y')
    {
       int j,k;
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                printf("Enter element at position(%d,%d):\n",j+1,k+1);
                scanf("%d",&m[j][k]);
            }
        }
    }
    while(1)
    {
        printf("Enter 0 to break and 1 to continue\n");
        int ter;scanf("%d",&ter);
        if(ter==0)break;
        printf("Enter size of the square matrix:\n");
        int w,j,k;scanf("%d",&w);
        printf("Enter elements of the %d*%d square matrix:\n",w,w);
        int s[w][w],b[n+(2*(w/2))][n+(2*(w/2))];
        for(j=0;j<w;j++)
        {
            for(k=0;k<w;k++)
            {
                printf("Enter element at position(%d,%d):\n",j+1,k+1);
                scanf("%d",&s[j][k]);
            }
        }
        transform(b[0],m[0],w,n);
        for(j=0;j<n+(2*(w/2));j++)
        {
            for(k=0;k<n+(2*(w/2));k++)
            {
                printf("%d ",b[j][k]);
            }
            printf("\n");
        }
        mult(b[0],s[0],w,n);
    }
    return 0;
}
