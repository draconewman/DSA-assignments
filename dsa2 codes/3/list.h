//defining a list as a structure of int array consisting of maximum 200000 elements;
struct LIST
{int length,arr[200000];};
//formal parameter is pointer to
void Set(struct LIST *l)
{
    l->length=0;l->arr[0]=-1;
}
//formal parameters take struct LIST pointer
//take input of a list
void get_values(struct LIST *l)
{
    int j=0;
    while(l->arr[j]!=-1)
    {
        j++;
    }
    printf("Enter value:\n");
    scanf("%d",&(l->arr[j]));
    l->length++;
    l->arr[++j]=-1;
}
//formal parameter take struct LIST pointer and
//print and returns the length of the list
int find_length(struct LIST *l)
{
    printf("%d\n",l->length);
    return(l->length);
}
//formal parameters take struct LIST pointer
//prints the list from front
void read_from_front(struct LIST *l)
{
    if(l->length==0)
    {
        printf("List is empty\n");return;
    }
    int j=0;
    while(l->arr[j]!=-1)
    {
        printf("%d ",l->arr[j]);j++;
    }
    printf("\n");
}
//formal parameters take struct LIST pointer
void read_from_end(struct LIST *l)
{
    if(l->length==0)
    {
        printf("List is empty\n");return;
    }
    int j=(l->length)-1;
    while(j>=0)
    {
        printf("%d ",l->arr[j]);j--;
    }
    printf("\n");
}
//formal parameters take struct LIST pointer and the index of element to be retrived
//print and returns ith element
//if such index does not exist it returns -1
int retrieve(struct LIST *l,int index)
{
    if(l->length==0)
    {
        printf("List is empty\n");return(0);
    }
    if(index>(l->length)-1)
    {
        printf("Such index does not exist\n");return(-1);
    }
    printf("%dth element of the list is:%d\n",index,l->arr[index]);
    return(l->arr[index]);
}
//formal parameters take struct LIST pointer and the index of element to be deleteded
//if such index does not exist the function stop executing and returns to the calling function
//deletes the element at position index
//and append the entire list after the position index-1
void del(struct LIST *l,int index)
{
    int j=index;
    if(index>(l->length)-1)
    {
        printf("Such index does not exist\n");return;
    }
    printf("%dth element of the list is:%d\n",index,l->arr[index]);
    j++;
    while(l->arr[j]!=-1)
    {
        l->arr[j-1]=l->arr[j];j++;
    }
    l->arr[j-1]=-1;
    l->length--;
}
//formal parameters take struct LIST pointer and the value of the element to be found
//if such value does not exist the function returns -1
//else returns the index of the array where value is found
int find_by_value(struct LIST *l,int value)
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
            printf("value %d exist at position %d\n",value,j);return(j);
        }
        j++;
    }
    printf("Such value does not exist\n");
    return(-1);
}
//formal parameters take struct LIST pointer to be sorted
void Sort(struct LIST *l)
{
    if(l->length==0)
    {
        printf("List is empty\n");return;
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
    printf("The list is sorted in increasing order:\n");
    for(j=0;j<l->length;j++)
    {
        printf("%d ",l->arr[j]);
    }
    printf("\n");
}
