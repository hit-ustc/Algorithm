#include <stdio.h>
#include <stdlib.h>

int search_first_large_k(int *arr, int length, int k)
{
    if(length <= 0 || arr[length - 1] < k)
    {
        return -1;
    }

    int res = length - 1;
    int left = 0;
    int right = length - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] > k)
        {
            res = mid;
            right = mid - 1;
        } else
        {
            left = mid + 1;
        }
    }

    return res;
}

int main()
{
    int arr[8] = {1, 2, 3, 3, 3, 4, 5, 8};

    int index = search_first_large_k(arr, 8, 3);

    printf("%d\n", index);
    return 0;
}
