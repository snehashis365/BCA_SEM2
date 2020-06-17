//Program to convert Arabic number to Roman Number
#include <stdio.h>
#include <string.h>
int val[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
char roman[][2]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int dp=0;
void getRoman(int n)
{
	int i=0;
	while(n>0)
	{
		if(n>=val[i])
		{
			printf("%s",roman[i]);
			n-=val[i];
		}
		else
		{
			i++;
		}
	}
}
void main()
{
	printf("Enter Decimal/Arabic number: ");
	int n;
	scanf("%d",&n);
	getRoman(n);
	printf("\n");
}



