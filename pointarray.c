//Program 64: Substring using function
#include <stdio.h>
#include <string.h>
void substr(char *str,int a,int b,char *sub)
{
	int i,index=0;
	for(i=a;i<b;i++)
	{
		sub[index++]=str[i];
	}
	sub[index]=NULL;
}
void main()
{
	char str[100];
	printf("Enter string: ");
	gets(str);
	int a,b;
	printf("Enter starting index: ");
	scanf("%d",&a);
	printf("Enter ending index: ");
	scanf("%d",&b);
	char sub[b-a+1];
	substr(str,a,b,sub);
	puts(sub);
}
/*

Output:

Enter string: Hello world
Enter starting index: 6
Enter ending index: 11
world

*/





