#include <stdio.h>
void main()
{
  printf("Enter no. of lines:");
  int x=1,i,j,n;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=i;j++)
    {
      printf("%d ",x);
      x=!x;
    }
    printf("\n");
  }
}
