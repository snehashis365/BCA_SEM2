#include <stdio.h>
#include <string.h>
float operate(int x,char op,int y)
{
	float res;
	switch(ch)
	{
		case '/':
			{
				res=(float)x/y;
				break;
			}
		case '%':
			{
				res=(float)x%y;
				break;
			}
		case '*':
			{
				res=(float)x*y;
				break;
			}
		case '+':
			{
				res=(float)x+y;
				break;
			}
		case '-':
			{
				res=(float)x-y;
				break;
			}
	}
	return res;
}

float subExp(char exp[])
{
	int i;float val=0;;
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(')
			val+=
void main()
{
	char exp[50];
	printf("Enter Expression: \n");
	gets(exp);
	char operand[]={'+','-','*','/','%'};

