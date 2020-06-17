#include <stdio.h>
#include <stdlib.h>
void main(int count, char *argv[])
{
    if(count<3)
    {
        printf("\nError!!\nMust include atleast 2 arguments\n");
    }
    else
    {
        int i,sum = 0;
        for(i=0;i<count;i++)
            sum+= atoi(argv[i]);
        printf("\nSum is: %d\n",sum);
    }
    
}