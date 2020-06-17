#include <stdio.h>
int top=-1;
void push(int data,int stack[],int size){
    if(top==size-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top]=data;
    }
}
int pop(int stack[]){
    if(top==-1){
        printf("Stack Underflow\n");
        return -999;
    }
    else{
        return stack[top--];
    }
}

void display(int stack[]){
    int i;
    for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}

void main(){
    int size,ch,data;
    printf("Enter size: ");
    scanf("%d",&size);
    int stack[size];
    do{
        printf("Press 1 to push\nPress 2 to pop\nPress 3 to display\nPress 0 to exit\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch){

            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                push(data,stack,size);
                break;
            case 2:
                data = pop(stack);
                if(data!=-999)
                    printf("Popped: %d\n",data);
                break;
            case 3:
                display(stack);
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
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 51
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 23
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 20
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 4
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 95
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:1
Enter data: 54
Stack overflow
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:3
95
4
20
23
51
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:2
Popped: 95
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:2
Popped: 4
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:2
Popped: 20
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:2
Popped: 23
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:2
Popped: 51
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:2
Stack Underflow
Press 1 to push
Press 2 to pop
Press 3 to display
Press 0 to exit
Enter Choice:0
Exiting....
*/