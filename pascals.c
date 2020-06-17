//Program 65: Print pascals triangle for n rows
#include <stdio.h>
long int fact(int n)
{
  if(n>0)
    return n*fact(n-1);
  else
    return 1;
}
long int nCr(int n,int r)
{
  if(r>0)
    return fact(n)/(fact(r)*fact(n-r));
  else
    return 1;
}
void generate(int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=1;j<=n-i;j++)
      printf("  ");
    for(j=0;j<=i;j++)
      printf("%4ld",nCr(i,j));
    printf("\n");
  }
}
void main()
{
  int n;
  printf("Enter n=");
  scanf("%d",&n);
  generate(n);
}
/* 
Output:

Enter n=10

                       1
                     1   1
                   1   2   1
                 1   3   3   1
               1   4   6   4   1
             1   5  10  10   5   1
           1   6  15  20  15   6   1
         1   7  21  35  35  21   7   1
       1   8  28  56  70  56  28   8   1
     1   9  36  84 126 126  84  36   9   1

*/