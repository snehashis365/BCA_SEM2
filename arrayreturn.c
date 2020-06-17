#include <stdio.h>
#include <stdlib.h>
int* p(int arr[],int l)
{
	int *rev=(int*)malloc(sizeof(int)*l);
	int i;
	for(i=l-1;i>=0;i--)
	{
		rev[i]=arr[l-1-i];
	}
	return rev;
}
void main()
{
	int arr[5],i;
	for(i=0;i<5;i++)
		scanf(" %d",&arr[i]);
	int* rev;//=malloc(sizeof(int)*5);
	rev=p(arr,5);
	for(i=0;i<5;i++)
		printf("%d\n",rev[i]);
}

