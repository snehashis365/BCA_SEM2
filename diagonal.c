#include <stdio.h>
void main(){
    int n,i,j,count=0;
    printf("Enter size: ");
    scanf("%d",&n);
    int arr[n][n];
    printf("Enter elements:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    i=0;
    while(1){
        if(i<n){
            i=count;
            j=0;
        }
        else{
            i = n-1;
            j=count-i;
        }
        while(j<count+j){
            printf("%d ",arr[i][j]);
            i--;
            j++;
        }
        printf("\n");
        if(i==n-1 && j == n-1)
            break;
        count++;       
    }
}