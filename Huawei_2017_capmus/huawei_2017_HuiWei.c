#include <stdio.h>

int main()
{
	int num, mod;
    int n = 0;
    int temp;

    scanf("%d", &num);

    if(num == 0)
    {
        printf("1");
        return 0;
    }

    if(num < 0)
    {
    	num = -num;
    }

    temp = num;

    while(temp != 0)
    {
    	mod = temp % 10;
        n = n * 10 + mod;
        temp = temp / 10;
    }

    if(n == num)
    {
    	printf("1");
    }
    else
    {
    	printf("0");
    }
     return 0;
}