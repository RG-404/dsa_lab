/*
Write a program to create a binary search tree along with the operations
of searching and deletion. Moreover, perform a post order traversal of this tree.
*/

// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *left;
    struct node *right;
};

struct node *newNode(int value) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->item = value;
  temp->left = temp->right = NULL;
  return temp;
}

// Postorder traversal
void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->item);
}

// Create a new Node
struct node *createNode(value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insertNew(struct node *node, int value) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(value);

  // Traverse to the right place and insert the node
  if (value < node->item)
    node->left = insertNew(node->left, value);
  else
    node->right = insertNew(node->right, value);

  return node;
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct node *deleteNode(struct node *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->item)
        root->left = deleteNode(root->left, value);
    else if (value > root->item)
        root->right = deleteNode(root->right, value);

    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->item = temp->item;
        root->right = deleteNode(root->right, temp->item);
    }
    return root;
}

// int main() {
//   struct node* root = createNode(1);
//   insertLeft(root, 2);
//   insertRight(root, 3);
//   insertLeft(root->left, 4);
//   printf("\nPostorder traversal \n");
//   postorderTraversal(root);
// }

int main()
{
    struct node *root = NULL;
    root = insertNew(root, 8);
    root = insertNew(root, 3);
    root = insertNew(root, 1);
    root = insertNew(root, 6);
    root = insertNew(root, 7);
    root = insertNew(root, 10);
    root = insertNew(root, 14);
    root = insertNew(root, 4);

    printf("Post order traversal: ");
    postorderTraversal(root);

    printf("\nAfter deleting 10\n");
    root = deleteNode(root, 10);
    printf("Post order traversal: ");
    postorderTraversal(root);
    return 0;
}
