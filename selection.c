#include <stdio.h>
int *sort(int arr[],int l)
{
	int i,j,min,temp;
	for(i=0;i<l;i++)
	{
		min=i;
		for(j=i+1;j<l;j++)
		{
			if(arr[min]>arr[j])
				min=j;
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
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

				

