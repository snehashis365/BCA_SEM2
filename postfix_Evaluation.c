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