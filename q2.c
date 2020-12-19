/*
Write a program to implement a circular queue using array.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int A[SIZE];
int front = -1;
int rear = -1;

// Prototypes
void enqueue(int);
void dequeue();
int isEmpty();
void showfront();
void displayQueue();

int main()
{
    int choice, flag = 1, value;
    while (flag == 1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Showfront\n4. DisplayQueue\n5. Exit\n");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value");
            scanf(" %d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            showfront();
            break;
        case 4:
            displayQueue();
            break;
        case 5:
            flag = 0;
            break;
        }
    }
    return 0;
}

int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
        printf("Queue is full\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        A[rear] = value;
    }
}

void dequeue()
{
    if (isEmpty())
        printf("Queue is empty\n");
    else
        //only one element
        if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void showfront()
{
    if (isEmpty())
        printf("Queue is empty\n");
    else
        printf("element at front is: ", A[front]);
}

void displayQueue()
{
    if (isEmpty())
        printf("Queue is empty\n");
    else
    {
        int i;
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
                printf("%d ", A[i]);
        }
        else
        {
            i = front;
            while (i < SIZE)
            {
                printf("%d ", A[i]);
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                printf("%d ", A[i]);
                i++;
            }
        }
    }
}