#include <stdio.h>
int fact(int n)
{
	if(n>0)
		return n*fact(n-1);
	else
		return 1;
}
void main()
{
	int num;
	printf("Enter num: ");
	scanf("%d",&num);
	printf("Factorial is: %d\n",fact(num));
}

