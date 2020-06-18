/*
                               BCAN293 Assignment

                             Name: Snehashis Sarkar
                          University Roll: 29901219012
                                Date: 25-04-2020

*/

//                                  Link List

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
    while (point!=NULL)
    {
        count++;
        point = point->nextNode;
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
            newNode->nextNode = top; //when it is the 1st node the top is NULL by default so works both ways
            top = newNode;
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
void deleteNode()
{
    printf("\n\nDeleting node\n");
    int i,sCh,pos,value;
    if(listSize()==1)//Eliminating useless choices when only one node present
    {
        sCh = 1;
    }
    else
    {
        printf("\nPress 1 to remove from begin\nPress 2 to remove from any position\nPress 3 to remove from end\n\nEnter choice: ");
        scanf("%d",&sCh);
    }
    switch (sCh){
        case 1:
            p = top;
            top = top->nextNode;//When only one node present next node is NULL so top is technically freed
            value = p->data;
            free(p);//deallocating the unused memory location
            break;
        
        case 2:
            printf("\nEnter position: ");
            scanf("%d",&pos);
            i = 0;
            p = top;
            if(pos <= listSize()){
                while (i != pos){   
                    p2 = p;
                    p = p->nextNode;
                    i++;
                }
                p2->nextNode = p->nextNode;//skipping the node to be removed and linking the next node
                value = p->data;
                free(p);//deallocating the unused memory location
            }
            else{
                printf("\nInvalid Position\n");
            }
            
            break;

        case 3:
            p = top;
            while (p->nextNode->nextNode != NULL){
                p = p->nextNode;
            }
            value = p->nextNode->data;
            free(p->nextNode);//deallocating the unused memory location
            p->nextNode = NULL;
            break;
        default:
            printf("\nWrong choice\n");
            break;                
    }
    printf("\nNode deleted (Value = %d)\n",value);
}
void display()
{
    p=top;
    while (p!=NULL){
        printf("\n%d\n",p->data);
        p=p->nextNode;
    }
}
void main()
{

    int ch,sCh,value,pos,i;
    do{
        if(listSize()==0)
        {
            printf("\nPress 1 to create new node\nPress 9 to exit\n\nEnter choice: ");
        }
        else
        {
            printf("\nPress 1 to add new node\nPress 2 to delete node\nPress 3 to display\nPress 9 to exit\n\nEnter choice: ");
        }
        scanf("%d",&ch);
        switch (ch){
        case 1:
            printf("\nEnter Data: ");
            scanf("%d",&value);
            createNode(value);
            break;

        case 2:
            deleteNode();
            break;

        case 3:
            display();
            break;

        
        default:
            break;
        }       
    }while (ch!=9); 
    printf("\nExiting...\n");
}

/*
Output:

Press 1 to create new node
Press 9 to exit

Enter choice: 1

Enter Data: 20


Creating Node.....

Node added sucessfully

Press 1 to add new node
Press 2 to delete node
Press 3 to display
Press 9 to exit

Enter choice: 1

Enter Data: 12


Creating Node.....

Press 1 to add from begin
Press 2 to add from any position
Press 3 to add from end

Enter choice: 3

Node added sucessfully

Press 1 to add new node
Press 2 to delete node
Press 3 to display
Press 9 to exit

Enter choice: 1

Enter Data: 51


Creating Node.....

Press 1 to add from begin
Press 2 to add from any position
Press 3 to add from end

Enter choice: 1

Node added sucessfully

Press 1 to add new node
Press 2 to delete node
Press 3 to display
Press 9 to exit

Enter choice: 1

Enter Data: 6


Creating Node.....

Press 1 to add from begin
Press 2 to add from any position
Press 3 to add from end

Enter choice: 2

Enter position: 2

Node added sucessfully

Press 1 to add new node
Press 2 to delete node
Press 3 to display
Press 9 to exit

Enter choice: 3

51

20

6

12

Press 1 to add new node
Press 2 to delete node
Press 3 to display
Press 9 to exit

Enter choice: 2


Deleting node

Press 1 to remove from begin
Press 2 to remove from any position
Press 3 to remove from end

Enter choice: 1

Node deleted (Value = 51)

Press 1 to add new node
Press 2 to delete node
Press 3 to display
Press 9 to exit

Enter choice: 3

20

6

12

Press 1 to add new node
Press 2 to delete node
Press 3 to display
Press 9 to exit

Enter choice: 2


Deleting node

Press 1 to remove from begin
Press 2 to remove from any position
Press 3 to remove from end

Enter choice: 2

Enter position: 1

Node deleted (Value = 6)

Press 1 to add new node
Press 2 to delete node
Press 3 to display
Press 9 to exit

Enter choice: 3

20

12

Press 1 to add new node
Press 2 to delete node
Press 3 to display
Press 9 to exit

Enter choice: 2


Deleting node

Press 1 to remove from begin
Press 2 to remove from any position
Press 3 to remove from end

Enter choice: 3

Node deleted (Value = 12)

Press 1 to add new node
Press 2 to delete node
Press 3 to display
Press 9 to exit

Enter choice: 2


Deleting node

Node deleted (Value = 20)

Press 1 to create new node
Press 9 to exit

Enter choice: 9

Exiting...
*/