#include <stdio.h>
#include <string.h>
typedef struct transaction
{
	char type[10];
	int amount;
	int balance;
}stmnt;
void main()
{
	printf("Enter number\n");
	int n;
	scanf("%d",&n);
	stmnt list[10];
	int i;
	for(i=0;i<n;i++)
	{

		scanf("%s",&list[i].type);
		scanf("%d",&list[i].amount);
		scanf("%d",&list[i].balance);
	}
	printf("%10s%10s%10s\n\n","Type","Amount","Balance");
	for(i=0;i<n;i++)
	{
		printf("%10s",list[i].type);
		printf("%10d",list[i].amount);
		printf("%10d\n",list[i].balance);
	}

}

