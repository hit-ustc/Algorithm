#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[102];
    gets(str);

    int len;
    len = strlen(str);

    if(len == 0 || len > 100)
    {
        return 0;
    }

    int i, j;

    for(i = 1; i < len; ++i)
    {
        for(j = len - 1; j >= i; --j)
        {
            int k = j;
            if(isalpha(str[j]))
            {
                while(!isalpha(str[k - 1]))
                {
                    k--;
                }
                if(str[k - 1] > str[j])
                {
                    char c = str[k - 1];
                    str[k - 1] = str[j];
                    str[j] = c;
                }
            }
            else
            {
                continue;
            }
        }
    }

    puts(str);
    return 0;
}