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