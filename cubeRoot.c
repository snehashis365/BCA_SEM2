#include <stdio.h>
int Pow(int base,int power)
{
	if(power>0)
		return base*Pow(base,power-1);
	else
		return 1;
}
int isFactor(int num,int i)
{
	if(num%i==0)
		return 1;
	else
		return 0;
}
int isPrime(int num)
{
	int flag=1,i;
	for(i=2;i<=num/2;i++)
	{
		if(num%i==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int isPrimeFactor(int num,int f)
{
	if(isFactor(num,f) && isPrime(f))
		return 1;
	else
		return 0;
}
void main()
{
	int count,num,i,root=1,croot=1;
	printf("Enter number: ");
	scanf("%d",&num);
	for(i=2;i<=(num/2);i++)
	{
		count=0;
		int tmp=num;
		while(1)
		{
			if(isPrimeFactor(tmp,i))
			{
				count++;
				tmp/=i;
			}
				
			else
			{
				if(count>=3)
					root*=Pow(i,count/3);
				croot*=Pow(i,count%3);
				break;
			}
		}
		
	}
	printf("Cube root is: %d³√%d\n",root,croot);
}


