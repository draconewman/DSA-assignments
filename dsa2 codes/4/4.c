#include <stdio.h>
#include <stdlib.h>
#include "set.h"
int main()
{
    //array of 100 different sets
    struct SET l[100];
    int cnt=0;
    while(1)
    {
        printf("(1)create a set\n(2)display the set\n(3)insert an element\n(4)find intersection of two sets\n(5)delete element at ith position\n(6)search in the list by a specific value\n(7)sort the list\n(8)find the length of the list\n(9)union of two sets\n(10)EXIT\nEnter your choice:\n");
        int i;
        scanf("%d",&i);
        switch(i)
            {
                case(1):
                {
                    if(cnt>=100)
                    {
                        printf("No more sets can be formed\n");
                    }
                    Set(&l[cnt]);
                    get_values(&l[cnt++]);break;
                }
                case(2):
                {
                    int i;printf("Enter the index of the set");scanf("%d",&i);
                    if(i>=cnt)
                    {
                        printf("The set doesn't exist\n");break;
                    }
                    read(&l[i]);break;
                }
                case(3):
                {
                   int i;printf("Enter the index of the set");scanf("%d",&i);
                    if(i>=cnt)
                    {
                        printf("The set doesn't exist\n");break;
                    }
                    get_values(&l[i]);break;
                }
                case(4):
                {
                    int i;printf("Enter the index of the set");scanf("%d",&i);
                     int j;printf("Enter the index of the set");scanf("%d",&j);
                     if(i>=cnt)
                    {
                        printf("The set doesn't exist\n");break;
                    }
                    if(j>=cnt)
                    {
                        printf("The set doesn't exist\n");break;
                    }
                    disjoint(&l[i],&l[j]);break;
                }
                case(5):
                {
                     int i;printf("Enter the index of the set");scanf("%d",&i);
                    if(i>=cnt)
                    {
                        printf("The set doesn't exist\n");break;
                    }
                    int value;printf("Enter the value\n");scanf("%d",&value);
                    del(&l[i],value);break;
                }
                case(6):
                {
                     int i;printf("Enter the index of the set");scanf("%d",&i);
                    if(i>=cnt)
                    {
                        printf("The set doesn't exist\n");break;
                    }
                    int value;printf("Enter the value\n");scanf("%d",&value);
                    find_by_value(&l[i],value);break;
                }
                case(7):
                {
                    int i;printf("Enter the index of the set");scanf("%d",&i);
                    if(i>=cnt)
                    {
                        printf("The set doesn't exist\n");break;
                    }
                    Sort(&l[i]);break;
                }
                case(8):
                {
                    int i;printf("Enter the index of the set");scanf("%d",&i);
                    if(i>=cnt)
                    {
                        printf("The set doesn't exist\n");break;
                    }
                    find_length(&l[i]);break;
                }
                case(9):
                {
                    int i;printf("Enter the index of the set");scanf("%d",&i);
                     int j;printf("Enter the index of the set");scanf("%d",&j);
                     if(i>=cnt)
                    {
                        printf("The set doesn't exist\n");break;
                    }
                    if(j>=cnt)
                    {
                        printf("The set doesn't exist\n");break;
                    }
                    Union(&l[i],&l[j]);break;
                }
                case(10):
                    {
                        return(0);
                    }
            }
    }
    return 0;
}

