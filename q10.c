#include <stdio.h>
#include <stdlib.h>

int l_search(int arr[], int size, int x)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (x == arr[i])
        {
            index = i;
            break;
        }
    }
    return index;
}

int b_search(int arr[], int size, int x)
{
    int beg, mid, last;
    beg = 0;
    last = size - 1;
    while (beg <= last)
    {
        mid = (beg + last) / 2;
        if (x == arr[mid])
            return mid;
        else if (x > arr[mid])
            beg = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99}, searched, ch, index = -1;
    printf("Enter element to be searched: ");
    scanf(" %d", &searched);
    printf("\nSelect method:\n1.Linear search\n2.Binary Search\n\n:");
    scanf(" %d", &ch);
    switch (ch)
    {
    case 1:
        index = l_search(arr, sizeof(arr) / sizeof(int), searched);
        break;
    case 2:
        index = b_search(arr, sizeof(arr) / sizeof(int), searched);
        break;
    default:
        printf("Invalid option. Terminating program.");
        break;
    }
    if (index >= 0)
        printf("Found at index: %d\n", index);
    else
        printf("Element not found.\n");
    return 0;
}