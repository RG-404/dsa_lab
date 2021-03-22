#include <stdio.h>

void swap(int *, int *);
void insertion_sort(int[], int);
void printArray(int[], int);

int main()
{
    int arr[] = {44, 22, 33, 77, 55, 11};
    insertion_sort(arr, 6);
    printArray(arr, 6);
    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int arr[], int size)
{
    int temp, j;
    for (int i = 0; i < size; i++)
    {
        temp = arr[i];
        for (j = i - 1; temp < arr[j] && j >= 0; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}