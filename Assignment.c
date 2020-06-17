/*
                               BCAN293 Assignment

                             Name: Snehashis Sarkar
                          University Roll: 29901219012
                                Date: 19-04-2020

*/

//                            Stack Implementation

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





//                            Queue Implementation

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

//                            Infix to Postfix

#include <stdio.h>
#include <string.h>
int top = -1;
void push(char data, char stack[], int size)
{
    if (top == size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top] = data;
    }
}
char pop(char stack[])
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '~';
    }
    else
    {
        return stack[top--];
    }
}

void display(char stack[])
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int getWeight(char op)
{
    int weight = 0;
    if (op == '+' || op == '-')
        return weight;
    else
        weight++;
    if (op == '/' || op == '*')
        return weight;
    else
        weight++;
    if (op == '^')
        return weight;
    else
        weight++;
    if (op == '(' || op == ')')
        return weight;
    else
        return -1;
}

int getType(char op)
{
    if (op == '+' || op == '-' || op == '/' || op == '*' || op == '^' || op == '(')
        return 0;
    else if (op == ')')
        return 1;
    else
        return 2;
}

void toPostFix(char *infix, char *postfix)
{
    int size, i, type, pType = 0, iPost = 0;
    char stack[128], stk, scan;
    infix[strlen(infix)] = ')';
    size = strlen(infix);
    push('(', stack, 128);
    printf("\nConverting...\n");
    for (i = 0; i < size; i++)
    {
        scan = infix[i];
        type = getType(scan);
        switch (type)
        {
        case 0:
            while (getWeight(stack[top]) > getWeight(scan) && stack[top] != '(' && stack[top] != ')')
            {
                stk = pop(stack);
                if (stk != '~')
                    postfix[iPost++] = stk;
                else
                {
                    printf("\nError!!\nMetaData:\ntype=%d\nscan=%c\nstk=%c\n", type, scan, stk);
                    break;
                }
            }
            push(scan, stack, 128);
            break;
        case 1:
            while (stack[top] != '(')
            {
                stk = pop(stack);
                if (stk != '~')
                    postfix[iPost++] = stk;
                else
                {
                    printf("\nError!!\nMetaData:\ntype=%d\nscan=%c\nstk=%c\n", type, scan, stk);
                    break;
                }
            }
            top--;
            break;
        case 2:
            postfix[iPost++] = scan;
            break;
        default:
            printf("\nElement Type Error\n");
            break;
        }
        pType = type;
    }
}

//Driver Method
void main()
{
    char infix[128];
    printf("Enter expression: ");
    scanf("%[^\n]", infix);
    //Dynamically Allocate memory to point to postfix expression otherwise it will core dump
    char *postfix = (char *)malloc(sizeof(char *));
    //Use string function to allocate size by infix size
    //char postfix[strlen(infix)];
    toPostFix(infix, postfix);
    printf("\nPostFix = %s\n", postfix);
}

/*
Output:

Enter expression: (A+B)-(C/D)

Converting...

PostFix = AB+CD/-
*/




















//                            Postfix Evaluation

#include <stdio.h>
#include <string.h>
int top = -1;
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
 
int main()
{
        char e[20];
        int n1,n2,n3,num,index=0;
        printf("Enter the expression : ");
        scanf("%s",e);
        int stack[20];
        printf("Evaluating......\n");
        while(e[index] != NULL)
        {
                if(isdigit(e[index]))
                {
                        num = e[index] - 48;
                        push(num,stack,20);
                }
                else
                {
                        n1 = pop(stack);
                        n2 = pop(stack);
                        switch(e[index])
                        {
                                case '+':
                                {
                                        n3 = n1 + n2;
                    break;
                                }
                                case '-':
                                {
                                        n3 = n2 - n1;
                                        break;
                                }
                                case '*':
                                {
                                        n3 = n1 * n2;
                                        break;
                                }
                                case '/':
                                {
                                        n3 = n2 / n1;
                                        break;
                                }
                        }
                        push(n3,stack,20);
                }
                index++;
        }
        printf("\nThe result of expression %s  =  %d\n\n",e,pop(stack));
 
}

/*
Output:

Enter the expression : 54*82/-9+ 
Evaluating......

The result of expression 54*82/-9+  =  25

*/