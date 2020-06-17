#include <stdio.h>
int *sort(int arr[],int l)
{
	int i,j,key;
	for(i=1;i<l;i++)
	{
		 key=arr[i];
		j=i-1;
		while(j>=0 && key<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	return arr;
}
void main()
{
	int n,i,j;
	printf("Enter length: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf(" %d",&a[i]);
	}
	int *sorted=sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d\n",sorted[i]);
	}
}

