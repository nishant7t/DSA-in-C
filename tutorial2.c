#include <stdio.h>

int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binaryserch(int arr[], int size, int element)//always initilise the varibles which u declare.
{
    int low, mid, high;
    low=0,high=size-1;
    while (low<=high)// can also execute with while condition as (low<high) .
    //, but need to set high = mid for mid>element . but still u miss last element,rest of all can be read. to avoid this set initial high = size insted of size-1.
    // easy method is low<=high and low=mid+1 or high =mid-1
    {
        mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }

        if (arr[mid] > element)
        {
            high = mid-1 ;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 34, 56}, element = 56;
    int searchindex = binaryserch(arr, 12, element);
    printf("the element %d was found at index %d\n", element, searchindex);

    return 0;
}
