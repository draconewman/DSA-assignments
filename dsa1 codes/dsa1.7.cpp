#include <stdio.h>
#include <stdlib.h>

int main()
{
	int P[7] = {1009,1013,1019,1021,1031,1033,1039};
	int Ri[7];
	long long int L[7] = {26500,15724,23281,5705,3902,31322,4567};
	
	for (int i = 0; i<7; i++)
	{
		Ri[i] = (L[i])%(P[i]);
	}
	
	printf("R[i] = ");
	for (int i = 0; i<7; i++)
	{
		printf("\t%d",Ri[i]);
	}
	return 0;
}
