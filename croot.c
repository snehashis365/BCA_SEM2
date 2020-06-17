#include <stdio.h>
double getCubeRoot(float num)
{
	if(num<0)
	{
		printf("Cube root not possible for negative number!!\nGetting cube root for absolute value...\n");
		return getCubeRoot(-num);
	}
	float increment=0.000001;
	double i;
	for(i=i;(i*i*i)<=num;i++);
	i--;
	if((i*i*i)==num)
		return i;
	else
	{
		for(;(i*i*i)<=num;i+=increment);
		return i;
	}
}
void main()
{
	printf("Enter number: ");
	float n;
	scanf("%f",&n);
	printf("Cube Root: %f\n",getCubeRoot(n));
}

