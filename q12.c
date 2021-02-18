#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void ins_end(struct Node *HEAD, int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->link = NULL;
    if (HEAD == NULL)
        HEAD = n;
    else
    {
        struct Node *s = HEAD;
        while (s->link != NULL)
            s = s->link;
        s->link = n;
    }
}

void display(struct Node *HEAD)
{
    struct Node *temp = HEAD;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->link;
    }
}

int main()
{
    struct Node *list1 = NULL, *list2 = NULL;
    int arr1[] = {2, 4, 6, 12, 34, 35, 40, 50};
    int arr2[] = {3, 5, 7, 14, 20, 25};
    int i;
    for (i = 0; i < sizeof(arr1) / sizeof(int); i++)
    {
        ins_end(list1, arr1[i]);
        display(list1);
    }
    for (i = 0; i < sizeof(arr1) / sizeof(int); i++)
    {
        ins_end(list2, arr1[i]);
        display(list2);
    }
    return 0;
}
