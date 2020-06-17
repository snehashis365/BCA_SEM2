#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*char *substr(char *str,int start,int end)
{
	char sub[(end-start)+1];
	int i=0;
	while(sub[i]!=NULL)
	{
		sub[i]=str[i+start];
	}
	return sub;
}*/
char *substr(char *str,int start)
{
	char sub[(strlen(str)-start)+1];
	int i=0;
	while(sub[i]!=NULL)
	{
		sub[i]=str[i+start];
	}
	return sub;
}
void main()
{
	char ch[10];
	gets(ch);
	char *s=substr(ch,2);
	printf("%s\n",s);
}

