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

struct node *HEAD = NULL;

void ins_beg(int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->link = HEAD;
    HEAD = n;
}

void ins_end(int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->link = NULL;
    if (HEAD == NULL)
        HEAD = n;
    else
    {
        struct node *s = HEAD;
        while (s->link != NULL)
            s = s->link;
        s->link = n;
    }
}

void ins_after(int x, int a)
{
    if (HEAD == NULL)
        printf("List is Empty!!");
    else if (HEAD->link == NULL)
    {
        if (HEAD->data == a)
        {
            struct node *n = (struct node *)malloc(sizeof(struct node));
            n->data = x;
            n->link = NULL;
            HEAD->link = n;
        }
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        struct node *s = HEAD;
        n->data = x;
        while (s->data != a && s->link != NULL)
            s = s->link;
        n->link = s->link;
        s->link = n;
    }
}
void ins_bef(int x, int a)
{
    if (HEAD == NULL)
        printf("List is Empty!!");
    else if (HEAD->link == NULL)
    {
        if (HEAD->data == a)
        {
            struct node *n = (struct node *)malloc(sizeof(struct node));
            n->data = x;
            n->link = HEAD;
            HEAD = n;
        }
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        struct node *s = HEAD;
        n->data = x;
        while (s->link->data != a && s->link != NULL)
        {
            s = s->link;
        }
        n->link = s->link;
        s->link = n;
    }
}

void delete_beg()
{
    if (HEAD == NULL)
        printf("List is Empty!!");
    else
    {
        struct node *temp = HEAD;
        printf("%d has been deleted", HEAD->data);
        HEAD = HEAD->link;
        free(temp);
    }
}

void delete_end()
{
    if (HEAD == NULL)
        printf("List is Empty!!");
    else
    {
        struct node *head = HEAD, *previous = NULL;
        while (head->link != NULL)
        {
            previous = head;
            head = head->link;
        }
        printf("%d has been deleted", head->data);
        previous->link = NULL;
        free(head);
    }
}

void delete_specific(int x)
{
    if (HEAD == NULL)
        printf("List is Empty!!");
    else
    {
        struct node *head = HEAD, *previous = NULL;
        while (head->data != x)
        {
            previous = head;
            head = head->link;
        }
        printf("%d has been deleted", head->data);
        previous->link = head->link;
        free(head);
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
        printf("1. Insert Beg\n2. Insert end\n3.Insert after specific\n4.Insert before specific\n5.Delete Beg\n6.Delete End\n7.Delete Specific\n9.Display\n0.Exit ");
        int n,
            x, a;
        printf("\n\nChoice:");
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
            printf("Enter element to be inserted: ");
            scanf("%d", &x);
            printf("Enter element before which this is to be inserted: ");
            scanf("%d", &a);
            ins_bef(x, a);
            break;
        case 5:
            delete_beg();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            printf("Enter element to be deleted: ");
            scanf("%d", &x);
            delete_specific(x);
            break;
        case 9:
            display(HEAD);
            break;
        }
    } while (1);
}