#include <stdio.h>
typedef struct node
{
    int data;
    struct node *nextNode;    

}node;
node *newNode,*p,*p2,*top=NULL;
int listSize()
{
   // printf("\nCounting....");
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
   // printf("Done\n");
    return count; 
}
void createNode(int value)
{
    int Size = listSize();
    printf("\n\nCreating Node.....\n");
    int i,sCh,pos;
    if(Size==0)//Eliminating useless choices
        sCh = 1;
    else
    {
        printf("\nPress 1 to add from begin\nPress 2 to add from any position\nPress 3 to add from end\n\nEnter choice: ");
        scanf("%d",&sCh);
    }
    switch (sCh)
    {
        case 1:
        AddStart:
            newNode = (node*)malloc(sizeof(node*));
            newNode->data = value;
            if(top!=NULL)
            {
                p=top;
                while(p->nextNode!=top)//Traversing to last node where the link will circulate back
                {
                    p=p->nextNode;
                }
                p->nextNode = newNode;
                newNode->nextNode = top;
                top = newNode;
            }
            else
            {
                top=newNode;
                top->nextNode = top;
            }
            
            break;
        
        case 2:
            printf("\nEnter position: ");
            scanf("%d",&pos);
            i = 0;
            p = top;
            if(pos <= Size)
            {
                if(pos==0)
                    goto AddStart;
                else if(pos==Size)
                    goto AddEnd;
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
        AddEnd:
            newNode = (node*)malloc(sizeof(node*));
            p = top;
            while (p->nextNode != top){
                p = p->nextNode;
            }
            newNode->data = value;
            p->nextNode = newNode; 
            p->nextNode->nextNode =top;               
            break;
        default:
            printf("\nWrong choice\n");
            break;
        }
    printf("\nNode added sucessfully\n");
    
}
void deleteNode()
{
    int Size = listSize();
    printf("\n\nDeleting node...\n");
    int i,sCh,pos,value;
    if(Size==1)//Eliminating useless choices when only one node present
    {
        value = top->data;
        free(top->nextNode);
        free(top);
        printf("\nNode deleted (Value = %d)\n",value);
        top=NULL;
        return;
    }
    else
    {
        printf("\nPress 1 to remove from begin\nPress 2 to remove from any position\nPress 3 to remove from end\n\nEnter choice: ");
        scanf("%d",&sCh);
    }
    switch (sCh){
        case 1:
        DelStart:
            p = top;
            node *temp = top; //To free the location later
            value = p->data;
            while(p->nextNode!=top)//Traversing to last node where the link will circulate back
            {
                p=p->nextNode;
            }
            top = top->nextNode;
            p->nextNode = top;
            free(temp);//deallocating the unused memory location
            break;
        
        case 2:
            printf("\nEnter position: ");
            scanf("%d",&pos);
            i = 0;
            p = top;
            if(pos <= Size)
            {
                if(pos==0)
                    goto DelStart;
                else if(pos==Size)
                    goto DelEnd;
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
        DelEnd:
            p = top;
            //p2 = p->nextNode;
            while (p->nextNode->nextNode != top){
                p = p->nextNode;
            }
            value = p->nextNode->data;
            free(p->nextNode);
            p->nextNode = top;
            break;
        default:
            printf("\nWrong choice\n");
            break;                
    }
    printf("\nNode deleted (Value = %d)\n",value);
}
void display()
{
    printf("\n");
    p=top;
    do
    {
        printf("%d ",p->data);
        p=p->nextNode;
    }while (p!=top);
    printf("\n");
}
void main()
{

    int ch,sCh,value,pos,i;
    do{
       // printf("\nIn Loop....\n");
       // if(top==NULL)
        //    printf("\nTop NULL\n");
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
        //printf("\nOutside loop...\n");       
    }while (ch!=9); 
    printf("\nExiting...\n");
}