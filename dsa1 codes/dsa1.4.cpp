#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    f=fopen("Random Integers","w+");  //File containing random integers 
    int j=1;
    while(j!=100000)  //Condition: until 1,00,000
    {
        int x;
		x=rand();  //Random number generator
		printf("%d\n",x);
        if(x<=100000)
        {
            j++;
            fprintf(f,"%d\n",x);  //Storing them in file
        }
    }
    return 0;
}
