/*
Write a program to create a binary search tree along with the operations
of searching and deletion. Moreover, perform a post order traversal of this tree.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int item;
  struct node *left;
  struct node *right;
};

// Prototypes
struct node *newNode(int);
void postorderTraversal(struct node *);
struct node *insertNew(struct node *, int);
struct node *minValueNode(struct node *);
struct node *deleteNode(struct node *, int);

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

struct node *newNode(int value)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->item = value;
  temp->left = temp->right = NULL;
  return temp;
}

void postorderTraversal(struct node *root)
{
  if (root == NULL)
    return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}

struct node *insertNew(struct node *node, int value)
{
  if (node == NULL)
    return newNode(value);
  if (value < node->item)
    node->left = insertNew(node->left, value);
  else
    node->right = insertNew(node->right, value);

  return node;
}

struct node *minValueNode(struct node *node)
{
  struct node *current = node;
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
