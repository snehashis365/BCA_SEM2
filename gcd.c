#include <stdio.h>
int GCD(int a,int b)
{
  if(a!=b)
  {
    if(a>b)
      return GCD(a-b,b);
    else
      return GCD(a,b-a);
  }
  else
    return a;
}
void main()
{
  int a,b;
  printf("Enter 2 numbers:\n");
  scanf("%d%d",&a,&b);
  printf("GCD : %d\n",GCD(a,b));
}
