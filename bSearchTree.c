#include <stdio.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
node *root=NULL,*newNode,*p;
void addNode(int value)
{
    int count=0;
    p = root;
    if(p==NULL)
    {
        newNode = (node*)malloc(sizeof(node*));
        newNode->data=value;
        newNode->left=NULL;
        newNode->right=NULL;
        p=newNode;
        if(root==NULL)
            root=p;
        count++;
    }
    else
    {
        int flag = 0;
        while(1)
        {
            if (p->data == value)
            {
                printf("Duplicate value skipping...");
                break;
            }
            else if (p->data > value)
            {
                if(p->left != NULL)
                    p=p->left;
                else
                    flag = 1;

            }
            else
            {
                if(p->right != NULL)
                    p=p->right;
                else
                    flag = 2;

            }
            if(flag)
            {
                newNode = (node*)malloc(sizeof(node*));
                newNode->data=value;
                newNode->left=NULL;
                newNode->right=NULL;
                switch (flag)
                {
                case 1:
                    p->left=newNode;
                    break;

                case 2:
                    p->right=newNode;
                    break;
                }
                break;
            }
        }
    }

}
void display(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        display(root->left);
        display(root->right);
    }
}

void inDisplay(node *root)//Display tree in In-order fashion
{
  if(root->left!=NULL)
  {
    inDisplay(root->left);
  }
  printf("%d ",root->data);
  if(root->right!=NULL)
  {
    inDisplay(root->right);
  }
}

void main()
{
    int ch,val;
    do
    {
        printf("\n1. Add new data to tree\n2. Display tree data in Pre-order\n3. Display tree data in In-order\n9. Exit\n\nEnter Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter Data: ");
            scanf("%d",&val);
            addNode(val);
            break;

        case 2:
            printf("\nDisplaying....Pre-order\n");
            display(root);
            break;

        case 3:
            printf("\nDisplaying....In-order\n");
            inDisplay(root);
            break;
        case 9:
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    } while (ch!=9);
    printf("\nExiting...\n");
}
