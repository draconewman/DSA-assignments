#include <stdio.h>
#include <string.h>
//Converting name into ASCII format
//each digit of the ascii equivalent of each character in the name is stored as a separate character in a character array 
int convert(char name[],char arr[])
{
	int length=strlen(name),count=0,loop,temp;
	for(loop=--length;loop>=0;loop--)
	{
		temp=(int)name[loop];
		for(;temp>0;temp/=10)
			arr[count++]=(char)(48+temp%10);
	}
	arr[count]='\0';//marking the end of the string
	return count;//returning the length of the large integer
}
//Displaying the resulting string of numbers
void display(char arr[])
{
	int length=strlen(arr);
	for(--length;length>=0;--length)
		printf("%c",arr[length]);
	printf("\n");
}
//Cutting the string of numbers into two almost equal parts
//and adding(Algebraically) the two parts into one
void ascii_add(char arr[])
{
	int length=strlen(arr),ind,result,carry=0,half;
	if(length%2==0)
		half=length/2;
	else
		half=(length)/2;
	for(ind=0;ind<half;ind++)
	{
		result=carry+arr[ind]+arr[ind+half]-96;
		if(result>9)//if sum at nth digit is greater than 9
		{
			carry=result/10;//Storing carry at each step
			result=result%10;
		}
		else
			carry=0;
		arr[ind]=(char)(48+result);
	}
	if(length%2==0)//If length of string is even
	{
		if(!carry)
		arr[half]='\0';
		else
		{	
			arr[half]='1';
			arr[half+1]='\0';
		}
	}
	else//if length of string is odd
	{
		result=carry+arr[length-1]-48;
		carry=result/10;
		result%=10;//To store the result of addition of Most Significant Digit
		if(!carry)
		{
			arr[half]=(char)(result+48);
			arr[half+1]='\0';//To terminate the string
		}
		else
		{	
			arr[half]=(char)(result+48);
			arr[half+1]='1';
			arr[half+2]='\0';//To terminate the string
		}
	}
}
int length_divi(int n)//Determining the length of the dividend
{
	int count=0;
	for(;n>0;n/=10,count++);
	return count;
}
int modulus(char nm[],int prime)//Determining number mod prime
{
	int length=strlen(nm),dividend=0,divisor,remainder,indx,count;
	//Long division method is implemented by taking 4 or 5 digits of dividend at each step 
	for(indx=--length;indx>=0;)
	{
		count=length_divi(dividend);
		while(count<4)
		{
			dividend=dividend*10+nm[indx]-48;
			count++;//counting the no. of digits in the dividend
			indx--;
		}
		if(dividend<prime&&indx>=0)
		{
			dividend=dividend*10+nm[indx--]-48;
		}
		dividend=dividend%prime;//computing remainder for each step
	}
	return dividend;	
}
//To display the result of (large integer (mod) prime)
void result(char name[],char surname[],int prime)
{
	int res=modulus(name,prime);
	printf("\nPrime No. : %d",prime);
	printf("\nModified Name Modulus Prime: %d\n",res);
	res=modulus(surname,prime);
	printf("\nModified Surname Modulus Prime: %d\n\n",res);
}
int main()
{
	char name[]="Sayantan",surname[]="Biswas",count,ascii_n[30],ascii_s[30];
	int count_n=convert(name,ascii_n);
	//Displaying the name and surname in character as well as in ASCII format
	printf("\nName in character format: %s\n",name);
	printf("\nName in ASCII format: ");
	display(ascii_n);
	int count_s=convert(surname,ascii_s);
	printf("\nSurname in character format: %s\n",surname);
	printf("\nSurname in ASCII format: ");
	display(ascii_s);

	printf("\nAfter halving and adding,the ASCII format of name changes to: \n");
	ascii_add(ascii_n);
	display(ascii_n);
	printf("\nAfter halving and adding,the ASCII format of surname changes to: \n");
	ascii_add(ascii_s);
	display(ascii_s);
	//Displaying the result of : integer mod prime for 4 different primes
	result(ascii_n,ascii_s,1009);
	result(ascii_n,ascii_s,1013); 	
	result(ascii_n,ascii_s,1019);
	result(ascii_n,ascii_s,1021);
	result(ascii_n,ascii_s,1031);
	result(ascii_n,ascii_s,1033);
	result(ascii_n,ascii_s,1039);
	return 0;
}
