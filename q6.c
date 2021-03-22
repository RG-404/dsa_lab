/*
Write a program to implement bubble sort, selection sort, insertion sort and quick sort in
a menu driven program.
*/

#include <stdio.h>

// Prototypes
void swap(int *, int *);
void bubbleSort(int[], int);
void selectionSort(int[], int);
void insertionSort(int[], int);
int partition(int[], int, int);
void quickSort(int[], int, int);
void printArray(int[], int);

int main()
{
    int arr[100], n, i, ch;
    printf("Enter number of elements(max 100): ");
    scanf(" %d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n%d : ", i);
        scanf(" %d", &arr[i]);
        fflush(stdin);
    }
    printf("\nSelect method:\n1. Bubble sort\n2. Selection sort\n3. Insertion sort\n4. Quick sort\n\n:");
    scanf(" %d", &ch);
    switch (ch)
    {
    case 1:
        bubbleSort(arr, n);
        break;
    case 2:
        selectionSort(arr, n);
        break;
    case 3:
        insertionSort(arr, n);
        break;
    case 4:
        quickSort(arr, 0, n - 1);
        break;
    default:
        printf("Invalid Option. Terminating...");
        return 1;
    }
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int a[], int size)
{
    int temp_v, temp_l, temp;

    for (int i = 0; i < size; i++)

    {
        temp_v = a[i];
        temp_l = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < temp_v)
            {
                temp_v = a[j];
                temp_l = j;
            }
        }
        swap(&a[i], &a[temp_l]);
    }
}

void insertionSort(int a[], int size)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = a[i];
        for (j = i - 1; temp < a[j] && j >= 0; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}