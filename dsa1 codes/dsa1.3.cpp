#include <stdio.h>
#include <string.h>

void ls_i()				//Linear search for integers
{
	int array[100], search, c, n;
	  printf("Enter number of elements for array\n");
	  scanf("%d", &n);
	
	  printf("Enter %d integer(s)\n", n);
	
	  for (c = 0; c < n; c++)
	    scanf("%d", &array[c]);
	
	  printf("Enter a number to search\n");
	  scanf("%d", &search);
	
	  for (c = 0; c < n; c++){
	    if (array[c] == search)    
	    {
	      printf("%d is present at location %d.\n", search, c+1);
	      break;
	    }
	  }
	  if (c == n)
	    printf("%d isn't present in the array.\n", search);
}

void ls_f()				//Linear search for floating point numbers
{
	float array[100], search;
	int c, n;
	  printf("Enter number of elements for array\n");
	  scanf("%d", &n);
	
	  printf("Enter %d floating point number(s)\n", n);
	
	  for (c = 0; c < n; c++)
	    scanf("%f", &array[c]);
	
	  printf("Enter a number to search\n");
	  scanf("%f", &search);
	
	  for (c = 0; c < n; c++)
	  {
	    if (array[c] == search)    
	    {
	      printf("%f is present at location %d.\n", search, c+1);
	      break;
	    }
	  }
	  if (c == n)
	    printf("%f isn't present in the array.\n", search);
}

void bs_i()				//Binary search for integers 
{
	int c, first, last, middle, n, search, array[100];
	  printf("Enter number of elements\n");
	  scanf("%d", &n);
	
	  printf("Enter %d integers in ascending order\n", n);
	
	  for (c = 0; c < n; c++)
	    scanf("%d", &array[c]);
	
	  printf("Enter value to find\n");
	  scanf("%d", &search);
	
	  first = 0;
	  last = n - 1;
	  middle = (first+last)/2;
	
	  while (first <= last) {
	    if (array[middle] < search)
	      first = middle + 1;
	    else if (array[middle] == search) {
	      printf("%d found at location %d.\n", search, middle+1);
	      break;
	    }
	    else
	      last = middle - 1;
	
	    middle = (first + last)/2;
	  }
	  if (first > last)
	    printf("Not found! %d isn't present in the list.\n", search);
}

void bs_f()				// Binary search for floating point numbers
{
	int c, n, first, last, middle;
	float search, array[100]; 
	  printf("Enter number of elements\n");
	  scanf("%d", &n);
	
	  printf("Enter %d integers in ascending order\n", n);
	
	  for (c = 0; c < n; c++)
	    scanf("%f", &array[c]);
	
	  printf("Enter value to find\n");
	  scanf("%f", &search);
	
	  first = 0;
	  last = n - 1;
	  middle = (first+last)/2;
	
	  while (first <= last) {
	    if (array[middle] < search)
	      first = middle + 1;
	    else if (array[middle] == search) {
	      printf("%f found at location %d.\n", search, middle+1);
	      break;
	    }
	    else
	      last = middle - 1;
	
	    middle = (first + last)/2;
	  }
	  if (first > last)
	    printf("Not found! %f isn't present in the list.\n", search);
}

void ls_w()				//Linear search for characters
{
	char array[100], search;
    int c, n; 
	  printf("Enter number of elements for array\n");
	  scanf("%d", &n);
	
	  printf("Enter %d character(s)\n", n);
	  	scanf("%s", array);
	  

	  printf("Enter a character to search\n");
	  scanf("%s", search);
	
    
    for (c = 0; c<n; c++) { 
        if (array[c] == search) { 
      	 printf("%s is present at location %d.\n", search, c);
	     break; 
	   }    
       if (c == n)
	    printf("%s isn't present in the array.\n", search);
    } 
}

void bs_w()			//Binary search for characters
{
   char array[100], search;
   int first, last, middle,c,n; 
   printf("Enter number of elements for array\n");
	  scanf("%d", &n);
	
	  printf("Enter %d character(s) in ascending order\n", n);
	  	scanf("%s", array);
	  

	  printf("Enter a character to search\n");
	  scanf("%s",search);
   
   first = 0; 
   last = n-1; 
   while (first <= last) { 
      middle = first + (last - first) / 2; 
      while (first <= last) {
	    if (array[middle] < search)
	      first = middle + 1;
	    else if (array[middle] == search) {
	      printf("%s found at location %d.\n", search, middle+1);
	      break;
	    }
	    else
	      last = middle - 1;
	
	    middle = (first + last)/2;
	  }
	  if (first > last)
	    printf("Not found! %s isn't present in the list.\n", search);
    }
}

int main()
{
	
	int s;
	while(1)
	{
		printf("\n");
		printf("Enter\n");
		printf("(0)Exit\n(1)Linear search\n(2)Binary search\n");
		scanf("%d",&s);
		switch(s){  //switch case for menu driven program
			case 0: return 0;
			case 1:{
					int s1;
					printf("\n");
					printf("Enter\n");
					printf("(3)For integers\n(4)For floating point numbers\n(5)For characters\n");
					scanf("%d",&s1);
					switch(s1){ //switch case for linear search 
						case 3:{
								ls_i(); 
				            	break;
							}
						case 4:{
								ls_f(); 
				            	break;
							}
						case 5:{
								ls_w(); 
				            	break;
							}
					}
					break;
				}
			case 2:{
					int s2;
					printf("\n");
					printf("Enter\n");
					printf("(6)For integers\n(7)For floating point numbers\n(8)For characters\n");
					scanf("%d",&s2);
					switch(s2){  //switch case for binary search
						case 6:{
								bs_i(); 
				            	break;
							}
						case 7:{
								bs_f(); 
				            	break;
							}
						case 8:{
								bs_w(); 
				            	break;
							}
					}
					break;
				}
			default: printf("Wrong input!!");
					 return 1;
		}
	}
return 0;	
}
