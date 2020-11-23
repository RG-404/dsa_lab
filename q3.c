/*
Write a program to implement a singly linked linear list 
along with operations of traversing, insertion, deletion and display.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void ins_beg(int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->link = head;
    head = n;
}

void ins_end(int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->link = NULL;
    if (head == NULL)
        head = n;
    else
    {
        struct node *s = head;
        while (s->link != NULL)
            s = s->link;
        s->link = n;
    }
}

void display(struct node *np)
{
    while (np != NULL)
    {
        printf("%d -> ", np->data);
        np = np->link;
    }
    printf("!!!\n");
}

int main()
{
    do
    {
        printf("1. Insert Beg\n2. Insert end\n3.Display\n0.Exit ");
        int n,
            x, a;
        printf("\n\nChoice:");
        scanf("%d", &n);
        switch (n)
        {
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
            display(head);
            break;
        case 0:
            return 0;
        }
    } while (1);
}