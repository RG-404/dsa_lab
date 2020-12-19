#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *HEAD = NULL;

void ins_beg(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = HEAD;
    new_node->prev = NULL;
    if (HEAD != NULL)
        HEAD->prev = new_node;
    HEAD = new_node;
}

void ins_after(int new_data, int a)
{
    struct Node *prev_node = HEAD;
    while (prev_node->data != a)
    {
        prev_node = prev_node->next;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void ins_end(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = HEAD;
    new_node->data = data;
    new_node->next = NULL;
    if (HEAD == NULL)
    {
        new_node->prev = NULL;
        HEAD = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    return;
}

void delete_beg()
{
    if (HEAD == NULL)
    {
        printf("Queue is empty!!\n\n");
    }
    else
    {
        struct Node *temp = HEAD;
        if (temp->next == NULL)
        {
            HEAD = NULL;
        }
        else
        {
            HEAD = HEAD->next;
            temp->next->prev = NULL;
        }

        printf("%d deleted\n\n", temp->data);
        free(temp);
    }
}

void delete_end()
{
    if (HEAD == NULL)
    {
        printf("Queue is empty!!\n\n");
    }
    else
    {
        struct Node *last = HEAD;
        if (last->next == NULL)
        {
            HEAD = NULL;
        }
        else
        {
            while (last->next != NULL)
                last = last->next;
            last->prev->next = NULL;
        }
        printf("%d deleted\n\n", last->data);
        free(last);
    }
}

void delete_specific(int data)
{
    struct Node *required = HEAD;
    while (required->data != data && required != NULL)
    {
        required = required->next;
    }
    required->prev->next = required->next;
    required->next->prev = required->prev;
    printf("%d deleted\n\n", required->data);
    free(required);
}

void display(struct Node *node)
{
    struct Node *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main()
{
    do
    {
        printf("1. Insert Beg\n2. Insert end\n3.Insert after specific\n4.Delete Beg\n5.Delete End\n6.Delete Specific\n7.Display\n0.Exit ");
        int n,
            x, a;
        printf("\n\n:");
        scanf("%d", &n);
        switch (n)
        {
        case 0:
            return 0;
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            ins_beg(x);
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &x);
            ins_end(x);
            break;
        case 3:
            printf("Enter element to be inserted: ");
            scanf("%d", &x);
            printf("Enter element after which this is to be inserted: ");
            scanf("%d", &a);
            ins_after(x, a);
            break;
        case 4:
            delete_beg();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            printf("Enter element to be deleted: ");
            scanf("%d", &x);
            delete_specific(x);
            break;
        case 7:
            display(HEAD);
            break;
        }
    } while (1);
}