
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
int main()  
{  
    char str[100], s[100];  
    int i, len, mid, top;  
  
    gets(str);  
    len = strlen(str);  
    mid = len/2 - 1;     /// 字符串的中点  
  
    top = -1;            /// 栈初始化  
    for (i = 0; i <= mid; ++i)  
    {  
        s[++top] = str[i];  
    }  
  
    if(len % 2)          /// 判断字符串长度是偶数还是奇数  
    {  
        mid += 2;  
    }  
    else  
    {  
        mid++;  
    }  
  
    for (i = mid; i < len; ++i)  
    {  
        if (str[i] != s[top])  
        {  
            break;  
        }  
        top--;  
    }  
  
    printf("%s\n", top == -1? "Yes": "No");  
    return 0;  
}