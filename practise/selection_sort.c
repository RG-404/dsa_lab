#include <stdio.h>

void swap(int *, int *);
void selection_sort(int[], int);
void printArray(int[], int);

int main()
{
    int arr[] = {44, 22, 33, 77, 55, 11};
    selection_sort(arr, 6);
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

void selection_sort(int arr[], int size)
{
    int temp_v, temp_i;
    for (int i = 0; i < size; i++)
    {
        temp_v = arr[i];
        temp_i = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                temp_v = arr[j];
                temp_i = j;
            }
        }
        swap(&arr[i], &arr[temp_i]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}