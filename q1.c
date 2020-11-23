/*
Write a program to implement a stack using array. 
Moreover, show how this stack can be used to check whether a string is a palindrome or not.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define sz 5

// Prototypes
void push(char *, int *, int);
int pop(char *, int *);
void display(char *, int);
int isEmpty(int);
int isFull(int);
int isPalindrome(char *);

int main()
{
    char word[100];

    printf("Enter a string (max. 100) : ");

    scanf("%s", word);

    if (isPalindrome(word))
    {
        printf("\"%s\" is a palindrome", word);
    }
    else
    {
        printf("\"%s\" is not a palindrome", word);
    }

    return 0;
}

int isPalindrome(char *str)
{
    int length = strlen(str), top = -1;
    char *stack = (char *)malloc(length * sizeof(char));
    int i, mid = length / 2;

    for (i = 0; i < mid; i++)
    {
        push(stack, &top, str[i]);
    }
    if (length % 2 != 0)
    {
        i++;
    }
    while (str[i] != '\0')
    {
        char letter = pop(stack, &top);
        if (letter != str[i])
            return 0;
        i++;
    }
    return 1;
}

int isFull(int top)
{
    return top == sz - 1 ? 1 : 0;
}

int isEmpty(int top)
{
    return top == -1 ? 1 : 0;
}

void push(char *stack, int *top, int element)
{
    if (isFull(*top))
        printf("Stack Overflow\n");
    else
        stack[++(*top)] = element;
}

int pop(char *stack, int *top)
{
    if (isEmpty(*top))
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
        return stack[(*top)--];
}

void display(char *stack, int top)
{
    if (isEmpty(top))
        printf("Stack is empty");
    else
        for (int i = 0; i <= top; i++)
            printf("%d\t", *(stack + i));
    printf("\n");
}