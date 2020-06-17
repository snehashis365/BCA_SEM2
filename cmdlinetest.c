#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int stringToInt(char *str)
{
    int len,temp,num=0.0;
    len = strlen(str);
    temp = len - 1;
    while(temp>=0)
    {
        num+= (int)pow(10,temp)*((str[len-temp-1])-48);
        temp--;
    }
    return num;
}

float stringToFloat(char *str)
{
    int len,temp,flag = 0,i=0;
    float num=0.0;
    len = strlen(str);
    while(str[i]!='.')
        i++;
    printf("%d\n",i);
    temp = i-1;
    i=0;
    while(i<len)
    {
        printf("%f\n",num);
        if(str[i]=='.')
        {
            flag = 1;
            temp=1;
            i++;

        }
        if(flag)
        {
            num+= pow(10,-temp)*((str[i])-48);
            temp++;
        }
        else
        {
            num+= pow(10,temp)*((str[i])-48);
            temp--;
        }       
        i++;
    }
    return num;
}

void main(int argc,char *argv[])
{
    char *test = "956.23";
    printf("Test = %f\n",stringToFloat(test));
}