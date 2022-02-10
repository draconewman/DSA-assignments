//defining a list as a structure of int array consisting of maximum 200000 elements;
struct SET
{int length,arr[2000];};
void Sort(struct SET* l);
//formal parameter is pointer to
void Set(struct SET *l)
{
    l->length=0;l->arr[0]=-1;
}
//formal parameters take struct LIST pointer
//take input of a list
void get_values(struct SET *l)
{
    int j=0,x;printf("Enter value:\n");
    scanf("%d",&x);
    while(l->arr[j]!=-1)
    {
        if(l->arr[j]==x)
        {
            printf("This element already exist\n");return;
        }
        j++;
    }
    l->arr[j]=x;
    l->length++;
    l->arr[++j]=-1;
}
//formal parameter take struct LIST pointer and
//print and returns the length of the list
int find_length(struct SET *l)
{
    printf("%d\n",l->length);
    return(l->length);
}
//formal parameters take struct LIST pointer
//prints the list from front
void read(struct SET *l)
{
    if(l->length==0)
    {
        printf("This is a NULL set\n");return;
    }
    int j=0;
    while(l->arr[j]!=-1)
    {
        printf("%d ",l->arr[j]);j++;
    }
    printf("\n");
}
//formal parameters take struct LIST pointer and the index of element to be deleteded
//if such index does not exist the function stop executing and returns to the calling function
//deletes the element at position index
//and append the entire list after the position index-1
void del(struct SET *l,int value)
{
    int j;
    for(j=0;j<l->length;j++)
    {
        if(l->arr[j]==value)
        {
            while(l->arr[j]!=-1)
            {
                l->arr[j-1]=l->arr[j];j++;
            }
            l->arr[j-1]=-1;
            l->length--;
            return;
        }
    }
    printf("Element %d does not exist in this set\n",value);
}
//formal parameters take struct LIST pointer and the value of the element to be found
//if such value does not exist the function returns -1
//else returns the index of the array where value is found
int find_by_value(struct SET *l,int value)
{
    if(l->length==0)
    {
        printf("List is empty\n");return(-1);
    }
    int j=0;
    while(l->arr[j]!=-1)
    {
        if(value==l->arr[j])
        {
            printf("value %d exist at position %d in the set\n",value,j);return(j);
        }
        j++;
    }
    printf("Such value does not exist\n");
    return(-1);
}
// formal arguments are two pointers to the structure SET(struct SET *l1,struct SET *l2)
//It displays the intersection of two sets l1 and l2
void disjoint(struct SET *l1,struct SET *l2)
{
    int d=0;
    Sort(l1);Sort(l2);
    int j=0,k=0,a[20000];
    while((l1->arr[j]!=-1)&&(l2->arr[k]!=-1))
    {
        if((l1->arr[j])<(l2->arr[k]))
        {
            j++;
        }
        else if((l1->arr[j])>(l2->arr[k]))
        {
            k++;
        }
        else if((l1->arr[j])==(l2->arr[k]))
        {
            printf("!\n");
            a[d++]=l1->arr[j];j++;k++;
        }
    }
    printf("The intersection contains %d distinct elements:",d);
    for(j=0;j<d;j++)
        printf("%d ",a[j]);
    printf("\n");
}
// formal arguments are two pointers to the structure SET(struct SET *l1,struct SET *l2)
//It displays the union of two sets l1 and l2
void Union(struct SET *l1,struct SET *l2)
{
    int d=0;
    Sort(l1);Sort(l2);
    int j=0,k=0,a[20000];
    while((l1->arr[j]!=-1)&&(l2->arr[k]!=-1))
    {
        if((l1->arr[j])<(l2->arr[k]))
        {
            a[d++]=l1->arr[j];j++;
        }
        else if((l1->arr[j])>(l2->arr[k]))
        {
            a[d++]=l2->arr[k];k++;
        }
        else if((l1->arr[j])==(l2->arr[k]))
        {
            a[d++]=l1->arr[j];j++;k++;
        }
    }
    while((l1->arr[j]!=-1))
        a[d++]=l1->arr[j++];
     while((l2->arr[k]!=-1))
        a[d++]=l2->arr[k++];
    printf("The union contains %d distinct elements:",d);
    for(j=0;j<d;j++)
        printf("%d ",a[j]);
    printf("\n");
}
//formal parameters take struct LIST pointer to be sorted
void Sort(struct SET* l)
{
    if(l->length==0)
    {
        printf("This is NULL set\n");return;
    }
    int j,k,t;
    for(j=0;j<((l->length)-1);j++)
    {
        for(k=j+1;k<(l->length);k++)
        {
            if(l->arr[j]>l->arr[k])
            {
                t=l->arr[j];
                l->arr[j]=l->arr[k];
                l->arr[k]=t;
            }
        }
    }
    printf("The set is sorted in increasing order:\n");
    for(j=0;j<l->length;j++)
    {
        printf("%d ",l->arr[j]);
    }
    printf("\n");
}

