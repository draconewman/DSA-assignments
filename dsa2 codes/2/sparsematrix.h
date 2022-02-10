#include <stdio.h>
//formal parameter consists of int * adress of matrix and t is number of terms in it
//it takes input of the row column and the corresponding value of the sparse matrix
void getdata(int *a,int t)
{
    int j;
    for(j=0;j<t;j++)
    {
        printf("Enter row number\n"); scanf("%d",a+(3*j));
        printf("Enter column number\n");scanf("%d",a+(3*j)+1);
        printf("Enter value\n");scanf("%d",a+(3*j)+2);
    }
}
//formal parameter consists of int * adress of matrix and t is number of terms in it
//it displays the row column and the corresponding value stored
void display(int *a,int t)
{
    int j;
    for(j=0;j<t;j++)
    {
        printf("%d\t%d\t%d\n",*(a+(3*j)),*(a+(3*j)+1),*(a+(3*j)+2));
    }
}
//the function has formal parameters of type int * which are adress of two matrices
//r1 and r2 are no of rows of mat1 and mat2
//c1 and c2 are no of columns of mat1 and mat2
//t1 and t2 are number of terms in the mat1 and mat2
//adds two matrices mat1 and mat2
void add(int *a,int r1,int c1,int *b,int t1,int t2)
{
    int j1=0,j2=0,j=0;
    int ans[t1+t2][3],cnt=0;
    for(j=1;j<=r1;j++)
    {
        while((*(a+(j1*3))==j)&&((*(b+(j2*3))==j))&&(j1<t1)&&(j2<t2))
        {
            if((*(a+(j1*3)+1))<(*(b+(j2*3)+1)))
                {
                    ans[cnt][0]=j;ans[cnt][1]=(*(a+(j1*3)+1));ans[cnt][2]=(*(a+(j1*3)+2));j1++;cnt++;continue;
                }
           else if((*(a+(j1*3)+1))>(*(b+(j2*3)+1)))
                {
                    ans[cnt][0]=j;ans[cnt][1]=(*(b+(j2*3)+1));ans[cnt][2]=(*(b+(j2*3)+2));j2++;cnt++;continue;
                }
           else if((*(a+(j1*3)+1))==(*(b+(j2*3)+1)))
                {
                    ans[cnt][0]=j;ans[cnt][1]=(*(a+(j1*3)+1));ans[cnt][2]=(*(a+(j1*3)+2))+(*(b+(j2*3)+2));j1++;j2++;cnt++;continue;
                }
        }
        while((*(a+(j1*3))==j)&&(j1<t1))
        {
            ans[cnt][0]=j;ans[cnt][1]=(*(a+(j1*3)+1));ans[cnt][2]=(*(a+(j1*3)+2));j1++;cnt++;
        }
        while(((*(b+(j2*3))==j))&&(j2<t2))
        {
            ans[cnt][0]=j;ans[cnt][1]=(*(b+(j2*3)+1));ans[cnt][2]=(*(b+(j2*3)+2));j2++;cnt++;
        }
    }
     printf("The addition is a %d*%d matrix:\nRow\tColumn\tvalue\n",r1,c1);
    display(ans[0],cnt);
}
//the function has formal parameters of type int * which are adress of two matrices
//r1 and r2 are no of rows of mat1 and mat2
//c1 and c2 are no of columns of mat1 and mat2
//t1 and t2 are number of terms in the mat1 and mat2
//Multiplies two matrices mat1 mat2
void mult(int *a,int r1,int c1,int t1,int *b,int r2,int c2,int t2)
{
    int j,j1=0,j2=0,c,ans[1000][3],cnt=0;
    for(j=1;j<=r1;j++)
    {
        int l;int r;
        l=j1;r=-1;
        while((*(a+(j1*3))==j)&&(j1<t1))
        {
           r=j1;j1++;
        }
        if(r==-1)
            continue;
        for(c=1;c<=c2;c++)
        {
            int k=l,sum=0;j2=0;ans[cnt][2]=0;
            while((k<=r)&&(j2<t2))
            {
                if((*(b+(j2*3)+1))!=c)
                {j2++;continue;}
                else if((*(b+(j2*3)))<(*(a+(k*3)+1)))
                {
                    j2++;continue;
                }
                else if((*(b+(j2*3)))>(*(a+(k*3)+1)))
                {
                    k++;continue;
                }
                else if((*(b+(j2*3)))==(*(a+(k*3)+1)))
                {
                   sum+=((*(a+(k*3)+2))*(*(2+b+(j2*3))));j2++;k++;
                }
            }
            if(sum!=0)
            {
                ans[cnt][0]=j;ans[cnt][1]=c;ans[cnt][2]=sum;cnt++;
            }

        }
    }
    printf("Multiplication gives %d*%d matrix\nRow\tColumn\tValue\n",r1,c2);
    display(ans[0],cnt);
}
//finds the transpose of a given sparse matrix
void transpose()
{
    printf("Enter no of rows\n");
    int row;scanf("%d",&row);
    printf("Enter no of columns\n");
    int col;scanf("%d",&col);
    printf("Enter number of elements in your matrix:\n");
    int tot;scanf("%d",&tot);
    int a[tot][3],ans[tot][3];
    getdata(a[0],tot);
    int j,k,cnt=0;
    for(j=1;j<=col;j++)
    {
        for(k=0;k<tot;k++)
        {
            if(a[k][1]==j)
            {
                ans[cnt][0]=a[k][1];ans[cnt][1]=a[k][0];ans[cnt][2]=a[k][2];cnt++;
            }
        }
    }
    printf("The transpose is a %d*%d matrix:\nRow\tColumn\tvalue\n",col,row);
    display(ans[0],tot);
}
