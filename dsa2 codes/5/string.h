#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
//concatenates one string after another string
void conc()
{
    char a[100],b[100];
    printf("Enter string after which you want to concatenate:\n");scanf("%s",a);
    printf("Enter string you want to concatenate:\n");scanf("%s",b);
    int j=0,k=0;
    while(a[j]!='\0')
        j++;
    while(b[k]!='\0')
    {
        a[j++]=b[k++];
    }
    a[j]='\0';
    printf("Here is your concatenated string:%s\n",a);
}
//calculates the length of a string
void len()
{
    char a[1000];
    printf("Enter string:\n");scanf("%s",a);
    int j=0;
    while(a[j]!='\0')
    {
        j++;
    }
    printf("Length of the string is :%d\n",j);
}
//compare two strings
void cpr()
{
    char a[1000],b[1000];
    printf("Enter string 1:\n");scanf("%s",a);
     printf("Enter string 2:\n");scanf("%s",b);
     int j=0,k=0,ans=0;
     while((a[j]!='\0')&&(b[k]!='\0'))
     {
         if(a[j]==b[k])
         {
             j++;k++;continue;
         }
         else
         {
             ans=(a[k]-b[j]);
             break;
         }
     }
     if((ans==0))
     {
         if((a[j]=='\0')&&(b[k]=='\0'))
         printf("Strings are same\n");
         else
         {
             if(a[j]!='\0')
            printf("String 2 is lexically smaller\n");
            else
            printf("String 1 is lexically smaller\n");

         }
     }
     if(ans<0)
     {
         printf("String 1 is lexically smaller\n");
     }
     if(ans>0)
     {
         printf("String 1 is lexically smaller\n");
     }
     printf("%d\n",ans);
}

#endif 
