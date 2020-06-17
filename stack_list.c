#include <stdio.h>
typedef struct node{

    int data;
    struct node *nextNode;

}node;
node *top=NULL;
void main(){

    int ch;
    node *newNode,*p;
    do{
        printf("Press 1 to push\nPress 2 to pop\nPress 3 to display\nPress 0 to exit\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch){

            case 1:
                newNode = (node*)malloc(sizeof(node*));
                printf("Enter data: ");
                scanf("%d",&newNode->data);
                if(top==NULL){
                    top=newNode;
                    newNode->nextNode=NULL;
                }
                else
                {
                    newNode->nextNode=top;
                    top=newNode;
                }
                
                break;
            case 2:
                if(top==NULL){
                    printf("Stack Underflow\n");
                }
                else
                {
                    printf("Popped: %d\n",top->data);
                    top=top->nextNode;   
                }
                break;
            case 3:
                p=top;
                while (p!=NULL)
                {
                    printf("%d\n",p->data);
                    p=p->nextNode;
                }
                break;
            case 0:
                printf("Exiting....\n");
                break;
            default:
                printf("Wrong Choice\n");
        }
    }while(ch!=0);

}