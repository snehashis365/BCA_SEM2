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
void preDisplay(node *root)//Display tree in Pre-order fashion
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preDisplay(root->left);
        preDisplay(root->right);
    }
}

void inDisplay(node *root)//Display tree in In-order fashion
{
    if(root->left!=NULL)
        inDisplay(root->left);
    printf("%d ",root->data);
    if(root->right!=NULL)
        inDisplay(root->right);
}

void postDisplay(node *root)//Display tree in Post-order fashion
{
    if(root->left!=NULL)
        postDisplay(root->left);
    if(root->right!=NULL)
        postDisplay(root->right);
    printf("%d ",root->data);
}

void main()
{
    int ch,val;
    do
    {
        printf("\n1. Add new data to tree\n2. Display tree data in Pre-order\n3. Display tree data in In-order\n4. Display tree in Post-order\n9. Exit\n\nEnter Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter Data: ");
            scanf("%d",&val);
            addNode(val);
            break;

        case 2:
            printf("\nDisplaying....Pre-order\n\n");
            preDisplay(root);
            printf("\n");
            break;

        case 3:
            printf("\nDisplaying....In-order\n\n");
            inDisplay(root);
            printf("\n");
            break;
        case 4:
            printf("\nDisplaying....Post-order\n\n");
            postDisplay(root);
            printf("\n");
            break;
        case 9:
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    } while (ch!=9);
    printf("\nExiting...\n\n");
}
