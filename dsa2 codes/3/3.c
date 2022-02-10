#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main()
{
    struct LIST l;
    Set(&l);
    while(1)
    {
        printf("(1)insert a value to the end of a list\n(2)read the list from end\n(3)read the list from front\n(4)retrieve ith element\n(5)delete element at ith position\n(6)search in the list by a specific value\n(7)sort the list\n(8)find the length of the list\n(9)EXIT\nEnter your choice:\n");
        int i;
        scanf("%d",&i);
        switch(i)
            {
                case(1):
                {
                    get_values(&l);break;
                }
                case(2):
                {
                    read_from_end(&l);break;
                }
                case(3):
                {
                    read_from_front(&l);break;
                }
                case(4):
                {
                    int index;printf("Enter the index\n");scanf("%d",&index);
                        retrieve(&l,index);break;
                }
                case(5):
                {
                    int index;printf("Enter the index\n");scanf("%d",&index);
                    del(&l,index);break;
                }
                case(6):
                {
                    int value;printf("Enter the value\n");scanf("%d",&value);
                    find_by_value(&l,value);break;
                }
                case(7):
                {
                    Sort(&l);break;
                }
                case(8):
                {
                    find_length(&l);break;
                }
                case(9):
                    {
                        return(0);
                    }
            }
    }
    return 0;
}
