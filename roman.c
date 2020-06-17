#include <stdio.h>
#include <math.h>
int val[]={1,5,10,50,100,500,1000};
char roman[]={'I','V','X','L','C','D','M'};
int dp=0;
void getRoman(int n)
{
	int i=0;
	int cnum=(n%10)*(int)pow(10,dp++);
	if(cnum>0)
	{
		while(cnum>val[i+1])
			i++;
		int l=(i%2==0)?0:1;
		if(cnum==val[i])
		{
			getRoman(n/10);
			printf("%c",roman[i]);
		}
		else if(cnum<(val[i+1]-val[i-l]))
		{
			getRoman(n/10);
			int count=0;
			while(cnum>0)
			{
				count++;
				cnum-=val[i-l];
				if(count*val[i-l]==val[i])
				{
					printf("%c",roman[i]);
					count=0;
				}
			}
			while(count>0)
			{
				printf("%c",roman[i-l]);
				count--;
			}
		}
		else
		{
			getRoman(n/10);
			printf("%c%c",roman[i-l],roman[i+1]);
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



