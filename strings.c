#include <stdio.h>
#include <string.h>
void main()
{
	char string1[12]="ABc";
	char string2[12]="ABC";
	int value=strcmp(string1,string2);
	printf("%d \n",value);
}

