#include <stdio.h>
typedef struct node
{
    int data;
    struct node *nextNode;    

}node;
node *newNode,*p,*p2,*top=NULL;
int listSize()
{
    int count=0;
    node *point = top;
    if(top!=NULL)
    {
        do
        {
            count++;
            point = point->nextNode;
        }while (point!=top);
    }
    return count; 
}
void createNode(int value)
{
    printf("\n\nCreating Node.....\n");
    int i,sCh,pos;
    if(listSize()==0)//Eliminating useless choices
        sCh = 1;
    else
    {
        printf("\nPress 1 to add from begin\nPress 2 to add from any position\nPress 3 to add from end\n\nEnter choice: ");
        scanf("%d",&sCh);
    }
    switch (sCh){
        case 1:
            newNode = (node*)malloc(sizeof(node*));
            newNode->data = value;
            newNode->nextNode = NULL;
            top = newNode;
            newNode->nextNode = top;
            break;
        
        case 2:
            printf("\nEnter position: ");
            scanf("%d",&pos);
            i = 0;
            p = top;
            if(pos <= listSize())
            {
                while (i != pos){   
                    p2 = p;
                    p = p->nextNode;
                    i++;
                }
                newNode = (node*)malloc(sizeof(node*));
                newNode->data = value;
                newNode->nextNode = p;
                p2->nextNode = newNode;
            }
            else
            {
                printf("\nInvalid Position\n");
            }
            break;

        case 3:
            newNode = (node*)malloc(sizeof(node*));
            p = top;
            while (p->nextNode != NULL){
                p = p->nextNode;
            }
            newNode->data = value;
            p->nextNode = newNode;                
            break;
        default:
            printf("\nWrong choice\n");
            break;
        }
    printf("\nNode added sucessfully\n");
    
}