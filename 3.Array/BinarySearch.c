#include <stdio.h>

int binarySearch(int arr[], int len, int index)
{
    int start = 0;
    int end = len - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == index)
        {
            return index;
        }
        else if (arr[mid] > index)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int index = binarySearch(arr, 10, 6);

    printf("%d position in array.", index + 1);

}