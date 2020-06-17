#include <stdio.h>
void main()
{
    printf("Enter Array size:\nRow = ");
    int m,n,count=0;
    scanf("%d",&m);
    printf("Column = ");
    scanf("%d",&n);
    int arr[m][n];
    printf("Enter Sparse matrix elements:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            
            if(arr[i][j]!=0)
                count++;
        }
    }
    int k=0,sp[3][count];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                sp[0][k] = i;
                sp[1][k] = j;
                sp[2][k] = arr[i][j];
                k++;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<count;j++)
        {
            printf("%d ",sp[i][j]);
        }
        printf("\n");
    }
}