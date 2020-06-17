#include <stdio.h>
int front=-1,rear=-1;
void insert(int data,int arr[],int size){
    if(rear==size-1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        arr[++rear]=data;
    }
    if(front==-1)
    {
        front++;
    }
    
}
int delete(int arr[]){
    if(front==-1){
        printf("Queue Underflow\n");
        return -999;
    }
    else if(front==rear)
    {
         int data=arr[front];
         front=-1;
         rear=-1;
         return data;
    }
    
    else{
        return arr[front++];
    }
}

void display(int arr[]){
    int i;
    for(i=front;i<=rear;i++){
        printf("%d\n",arr[i]);
    }
}

void main(){
    int size,ch,data;
    printf("Enter size: ");
    scanf("%d",&size);
    int arr[size];
    do{
        printf("Press 1 to insert\nPress 2 to delete\nPress 3 to display\nPress 0 to exit\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch){

            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                insert(data,arr,size);
                break;
            case 2:
                data = delete(arr);
                if(data!=-999)
                    printf("Deleted: %d\n",data);
                break;
            case 3:
                display(arr);
                break;
            case 0:
                printf("Exiting....\n");
                break;
            default:
                printf("Wrong Choice\n");
        }
    }while(ch!=0);
}

/*
Output:

Enter size: 5
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 24
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 32
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 12
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 99
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 4
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 74
Queue overflow
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:3
24
32
12
99
4
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:2
Deleted: 24
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:2
Deleted: 32
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:2
Deleted: 12
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:2
Deleted: 99
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:2
Deleted: 4
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:2
Queue Underflow
Press 1 to insert
Press 2 to delete
Press 3 to display
Press 0 to exit
Enter Choice:0
Exiting....

*/