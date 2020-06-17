#include <stdio.h>
typedef struct node{

    int data;
    struct node *nextNode;

}node;
node *front=NULL,*rear=NULL;
void main(){

    int ch;
    node *newNode,*p;
    do{
        printf("Press 1 to insert\nPress 2 to delete\nPress 3 to display\nPress 0 to exit\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch){

            case 1:
                newNode = (node*)malloc(sizeof(node*));
                printf("Enter data: ");
                scanf("%d",&newNode->data);
                if(front==NULL){
                    front=newNode;
                    rear=newNode;
                    rear->nextNode=front;
                }
                else
                {
                    newNode->nextNode=front;
                    rear->nextNode=newNode;
                    rear=newNode;
                }
                
                break;
            case 2:
                if(front==NULL){
                    printf("Queue Underflow\n");
                }
                else if (front->nextNode==front)
                {
                    printf("Deleted: %d\n",front->data);
                    front=NULL;
                    rear=NULL;
                }
                else
                {
                    printf("Deleted: %d\n",front->data);
                    front=front->nextNode;
                    rear->nextNode=front;
                }
                break;
            case 3:
                p=front;
                if(p==NULL)
                    printf("Empty List\n");
                else
                {
                    while (p->nextNode!=front)
                    {
                        printf("%d\n",p->data);
                        p=p->nextNode;
                    }
                    printf("%d\n",p->data);
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