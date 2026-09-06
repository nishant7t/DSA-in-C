#include <stdio.h>
// void swap (int,int );

void swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
int bubblesort(int arr[], int n)
{
    int i, j;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    for (int z = 0; z < n; z++)
    {
        printf("%d", arr[z]);
    }
    return 0;
}

int selectionsort(int arr[], int n)
{
    int mini;
    for (int i = 0; i < n; i++)
    {
        mini = i;

        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        if (mini != i)
            swap(&arr[i], &arr[mini]);
    }
    for (int z = 0; z < n; z++)
    {
        printf("%d", arr[z]);
    }
    return 0;
}

int insertionsort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            swap(&arr[j + 1], &arr[j]);
            j--;
        }
    }
    for (int z = 0; z < n; z++)
    {
        printf("%d", arr[z]);
    }
    return 0;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void qs(int arr[], int l, int h)
{
    if (l < h)
    {
        int pi = partition(arr, l, h);

        qs(arr, l, pi - 1);
        qs(arr, pi + 1, h);
    }
}


int main()
{
    int arr[] = {1, 3, 2}, n, t, g, s, elements = 3;

    printf("orignal array:\n");
    for (int i = 0; i < elements; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    printf("the result of bubble sort is: \n");
    n = bubblesort(arr, elements);
    printf("  \n");
    printf("the result of selection sort is: \n");
    t = selectionsort(arr, elements);
    printf("  \n");
    printf("the result of insertion sort is: \n");
    g = insertionsort(arr, elements);
    printf("  \n");
    printf("the result of quick sort is: \n");
    
    qs(arr, 1, 2);
    
    return 0;
}
