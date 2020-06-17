#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
void main()
{
	int i=10;
	char command[50];
	strcpy(command,"echo -n .");
	system("echo -n Please wait");
	for(;i>0;)
	{
		system(command);
		//printf("..");
		i--;
		sleep(1);
		system("echo -n -e '\b'");
	}
	system("echo");
}

	
