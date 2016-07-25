#include <stdio.h>  
#include <stdlib.h>  
  
void Adjust_heap(int array[], int pos, int n)  
{  
    int i, temp;  
    for(i = 2 * pos; i <= n; i *= 2)  
    {  
        if(i < n && array[i] < array[i+1])  
        {  
            i++;  
        }  
        if(array[i] < array[i/2])  
        {  
            break;  
        }  
        temp = array[i];  
        array[i] = array[i/2];  
        array[i/2] = temp;  
    }  
}  
  
int main()  
{  
    int array[] = {0, 1, 5, 195, 17, 23, 38, 40, 690, 275, 113};  
    int i, temp;  
    int n = 10;  
    for(i = n / 2; i > 0; i--)  
    {  
        Adjust_heap(array, i, n);  
    }  
    for(i = n; i > 1; i--)  
    {  
        temp = array[1];  
        array[1] = array[i];  
        array[i] = temp;  
        Adjust_heap(array, 1, i - 1);  
    }  
    for(i = 1; i <= n; i++)  
    {  
        printf("%d ", array[i]);  
    }  
    printf("\n");  
    return 0;  
}