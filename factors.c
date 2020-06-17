#include <stdio.h>
void getFactors(int num)
{
	int i;
	for(i=2;i<=num/2;i++)
	{
		if(num%i==0)
			printf("%d ",i);
	}
	printf("\n");
}
int isFactor(int num,int i)
{
	if(num%i==0)
		return 1;
	else
		return 0;
}
void main()
{
	int n,f;
	printf("Enter number to get it's factors :");
	scanf("%d",&n);
	getFactors(n);
	printf("Enter number for whom the following entered number is to be checked as a factor of :\n");
	scanf("%d %d",&n,&f);
	if(isFactor(n,f))
		printf("True\n");
	else
		printf("False\n");
}

