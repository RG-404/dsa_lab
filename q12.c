/*
Write a program to merge two singly linked non circular lists.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

// Prototypes
void ins_end(struct Node **, int);
void display(struct Node *);
void create_list(int[], int, struct Node **);
void merge_lists(struct Node *, struct Node *, struct Node **);

int main()
{
    struct Node *list1 = NULL, *list2 = NULL, *final = NULL;
    int arr1[] = {2, 4, 6, 12, 34, 35, 40, 50};
    int arr2[] = {3, 5, 7, 14, 20, 25};
    create_list(arr1, sizeof(arr1) / sizeof(int), &list1);
    create_list(arr2, sizeof(arr2) / sizeof(int), &list2);
    printf("List 1:\n");
    display(list1);
    printf("List 2:\n");
    display(list2);
    printf("Merging.....\n\n");
    merge_lists(list1, list2, &final);
    printf("Merged List:\n");
    display(final);
    return 0;
}

void ins_end(struct Node **HEAD, int value)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->link = NULL;
    if (*HEAD == NULL)

        *HEAD = new_node;
    else
    {
        struct Node *last_node = *HEAD;
        while (last_node->link != NULL)
            last_node = last_node->link;
        last_node->link = new_node;
    }
}

void display(struct Node *HEAD)
{
    while (HEAD != NULL)
    {
        printf("%d -> ", HEAD->data);
        HEAD = HEAD->link;
    }
    printf("!!!\n\n");
}

void create_list(int arr[], int size, struct Node **list)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        ins_end(list, arr[i]);
    }
}

void merge_lists(struct Node *list1, struct Node *list2, struct Node **final)
{
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            ins_end(final, list1->data);
            list1 = list1->link;
        }
        else
        {
            ins_end(final, list2->data);
            list2 = list2->link;
        }
    }
    if (list1 != NULL || list2 != NULL)
    {
        struct Node *last_node = *final;
        while (last_node->link != NULL)
            last_node = last_node->link;
        if (list1 != NULL)
            last_node->link = list1;
        else
            last_node->link = list2;
    }
}
