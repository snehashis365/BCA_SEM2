#include <stdio.h>
void generate2()
{
    char symbol[] = {'$','#','!','@'};
    int i,j;
    for(i=3;i>=0;i--)
    {
        for(j=0;j<i;j++)
            printf("   ");
        for(j=i;j<4;j++)
            printf("%c  ",symbol[j]);
        for(j=2;j-i>=0;j--)
            printf("%c  ",symbol[j]);
        printf("\n");
    }
    printf("\n");
}

void generate1()
{
    int ascii = 65;
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%c ",ascii);
        }
        if(i%2==0)
            ascii-=31;
        else
            ascii+=33;
        printf("\n");
        
    }
}
void main()
{
    int i,j;
    int ascii = 65;
    for(i=1;i<5;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%c ",ascii);
        }
        if(i%2==0)
            ascii-=31;
        else
            ascii+=33;
        printf("\n");
    }
}