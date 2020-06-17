#include <stdio.h>
int search(int arr[],int l,int key)
{
	int lb=0,ub=l-1,mid,index=-1;
	while(lb<=ub)
	{
		//printf("UB=%d\tLB=%d\n",ub,lb);
		mid=(lb+ub)/2;
		if(arr[mid]==key)
		{
			index=mid;
			break;
		}
		else if(key<arr[mid])
		{
			ub=mid+1;
		}
		else if(key>arr[mid])
		{
			lb=mid-1;
		}
	}
	return index;
}
void main()
{
	int n,i,j,sk;
	printf("Enter length: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements:(in ascending order)\n");
	for(i=0;i<n;i++)
	{
		scanf(" %d",&a[i]);
	}
	printf("Enter Search item: ");
	scanf("%d",&sk);
	i=search(a,n,sk);
	if(i>=0)
	{
		printf("Search item present at: %d\n",i);
	}
	else
		printf("Search item not present\n");
}




