/*
Write a program to implement a priority queue using a linked linear list.

Implemented using special enqueue operation and a typical dequeue operation.

- 	new element having same priority as other element(s) is inserted after
	the element(s) in the list priority is inserted after 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	int priority;
	struct Node *next;
};

struct Node *HEAD = NULL;

// Prototypes
void enqueue(int, int);
void dequeue();
void display();

int main()
{
	int choice, flag = 1, value, priority;
	while (flag == 1)
	{
		printf("1. Enqueue\n2. Dequeue\n3. DisplayQueue\n4. Exit\n");
		scanf(" %d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter a value and priority: ");
			scanf(" %d %d", &value, &priority);
			enqueue(value, priority);
			fflush(stdin);
			printf("\n");
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			flag = 0;
			break;
		default:
			printf("Enter a valid option!!");
			break;
		}
	}
	return 0;
}

void enqueue(int value, int priority)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = value;
	new_node->priority = priority;
	if (HEAD == NULL)
	{
		new_node->next = NULL;
		HEAD = new_node;
	}
	else if (priority < HEAD->priority)

	{
		new_node->next = HEAD;
		HEAD = new_node;
	}

	else
	{
		struct Node *previous = HEAD;

		while ((previous->next != NULL) && (priority >= previous->next->priority))
			previous = previous->next;
		new_node->next = previous->next;
		previous->next = new_node;
	}
}

void dequeue()
{
	if (HEAD == NULL)
	{
		printf("queue underflow!");
		return;
	}
	struct Node *item = HEAD;
	HEAD = HEAD->next;
	printf("%d dequeued", item->data);
	free(item);
}

void display()
{
	struct Node *n = HEAD;
	while (n != NULL)
	{
		printf("(%d, P%d)", n->data, n->priority);
		n = n->next;
	}
	printf("!!!\n");
}