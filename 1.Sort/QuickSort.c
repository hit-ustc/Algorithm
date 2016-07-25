/******************************************************************  
* Theme:         QuickSort  
* Content:       算法导论版快排  
* Language:      C  
* Author:        Aesthetic92  
* Description:     
******************************************************************/  
  
#include <stdio.h>  
#include <stdlib.h>  
  
void QuickSort(int array[], int p, int r);  
int partition(int array[], int p, int r);  
  
int main()  
{  
    int i;  
    int array[10];  
    for(i = 0; i < 10; i++)  
    {  
        scanf("%d", &array[i]);  
    }  
    QuickSort(array, 0, 9);  
    for(i = 0; i < 10; i++)  
    {  
        printf("%d ", array[i]);  
    }  
    return 0;  
}  
  
int partition(int array[], int p, int r)  
{  
    int i, j, temp, pivot;  
    pivot = array[r];  
    i = p - 1;  
    for(j = p; j < r; j++)  
    {  
        if(array[j] <= pivot)  
        {  
            i += 1;  
            temp = array[i];  
            array[i] = array[j];  
            array[j] = temp;  
        }  
    }  
    temp = array[i + 1];  
    array[i + 1] = array[r];  
    array[r] = temp;  
    return i + 1;  
}  
  
void QuickSort(int array[], int p, int r)  
{  
    int q;  
    if(p < r)  
    {  
        q = partition(array, p, r);  
        QuickSort(array, p, q - 1);  
        QuickSort(array, q + 1, r);  
    }  
}