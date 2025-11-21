#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

int search(struct Node *root, int value)
{
    if (root == NULL)
        return 0;
    if (root->data == value)
        return 1;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct Node *root = NULL;
    int values[10] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    for (int i = 0; i < 10; i++)
    {
        root = insert(root, values[i]);
    }
    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

    int searchVal = 45;
    printf("Searching for %d: %s\n", searchVal, search(root, searchVal) ? "Found" : "Not Found");

    printf("Height of tree: %d\n", height(root));
    printf("Total nodes: %d\n", countNodes(root));

    return 0;
}
