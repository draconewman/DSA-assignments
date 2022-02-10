#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
	char s[100],mins[100],maxs[100];
	int min=1000,max=0;
    f=fopen("nameroll.txt","r"); //File containing every classmates' names according to roll number 
    if(f==NULL)
    {
        printf("SORRY!");return(0);
    }
    do
    {
        fgets(s,100,f);printf("%s",s);
        int j=0,count=0;
        while(s[j]!='\0')
        {
            if((s[j]>=65)&&(s[j]<=122))
            {
                count++;j++;continue;
            }
            j++;
        }
        if(min>count)  //searching the name with least number of characters
        {int j=0, k=0;
	         while(s[j]!='\0')
	         {
	            if(((s[j]>=65)&&(s[j]<=122))||(s[j]==' '))
	            {
	                mins[k++]=s[j];
					j++;
					continue;
	            }
	            else
	            j++;
	         }
			 mins[k++]='\0';
	         min=count;
	        }
        if(max<count)  //searching the name with highest number of characters
        {int j=0, k=0;
	        while(s[j]!='\0')
	        {
	            if(((s[j]>=65)&&(s[j]<=122))||(s[j]==' '))
	            {
	                maxs[k++]=s[j];
					j++;
					continue;
	            }
	            else
	            j++;
	        }
			 maxs[k++]='\0';
	         max=count;
        }
    }while(!feof(f));  //End file
    printf("\n%s has the largest name with %d characters\n",maxs,max);
    printf("%s has the smallest name with %d characters\n",mins,min);
    return 0;
}
