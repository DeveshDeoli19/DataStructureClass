#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{

    struct BST *left, *right;
    int info;
} node;

int nodeCount = 0;
int leafCount = 0;
node *insert(node *, int);
void preorder(node *);
void inorder(node *);
void postorder(node *);

void counting(node *); // count nodes of BST
void leafNodesCount(node *);

int main()
{

    node *root = NULL;

    int ch = 0, value;

    do
    {

        printf("\n1.Insert\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.Count Nodes\n6.Count Leaf Nodes\n7.Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
        printf("\n\n");
        switch (ch)
        {

        case 1:
            printf("Enter Data: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            preorder(root);
            printf("\n");
            break;
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;
        case 5:
            counting(root);
            printf("Total %d nodes\n", nodeCount);
            break;
        case 6:
            leafNodesCount(root);
            printf("Total %d leaf nodes\n", leafCount);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    } while (ch < 7);

    return 0;
}

node *insert(node *root, int value)
{

    if (root == NULL)
    {

        root = (node *)malloc(sizeof(node));

        root->info = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    else if (value > root->info)
        root->right = insert(root->right, value);

    else
        root->left = insert(root->left, value);
    return root;
}

void preorder(node *root)
{

    if (root != NULL)
    {

        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{

    if (root != NULL)
    {

        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void postorder(node *root)
{

    if (root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

void counting(node *root)
{
    if (root != NULL)
    {

        counting(root->left);
        counting(root->right);
        nodeCount++;
    }
}

void leafNodesCount(node *root)
{
    if(root== NULL) return;
    
    if (root->left == NULL && root->right == NULL)
        leafCount++;

    else
    {
        leafNodesCount(root->left);
        leafNodesCount(root->right);
    }
}