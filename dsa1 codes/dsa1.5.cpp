#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *f;
	f=fopen("Million strings","w");
	int j,k,l,m,p,count=0;
	char c='A';
	for(j=0;j<26;j++)
	{
		for(k=0;k<26;k++)
		{
			for(l=0;l<26&&(count<100000);l++)
			{
				int p=0;
				putc(c+l,f);
				putc(c+k,f);
				putc(c+m,f);
				putc(c+j,f);
				for(p=0;p<6;p++)
				{
					putc(c+(count+p)%26,f);
				}
				count++;
				fprintf(f,"\n");
			}
		}
		
	}
	fclose(f);
	return 0;
}
