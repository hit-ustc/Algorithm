#include <stdio.h>
#include <string.h>

int main()
{
    char *str;
    int len, count = 0, flag = 0;

    gets(str);

    len = strlen(str);
    for(int i = 0; i < len; ++i)
    {
        if(str[i] == ' ')
        {
            flag = 0;
        }
        else
        {
            if(flag == 0)
            {
                count++;
                flag = 1;
            }
        }
    }

    printf("The number of words is :%d.", count);
    return 0;
}