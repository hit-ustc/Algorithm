/****************************************************************** 
* Theme:         KMP算法 
* Content: 
* Language:      C 
* Author:        Aesthetic92 
* Description: 
******************************************************************/  
  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
void get_next(char s[], int next[])  
{  
    int i, j, len;  
    i = 0;  
    j = -1;  
    len = strlen(s);  
    next[0] = -1;  
    while(i < len)  
    {  
        if(j == -1 || s[i] == s[j])  
        {  
            ++i;  
            ++j;  
            next[i] = j;  
        }  
        else  
        {  
            j = next[j];  
        }  
    }  
}  
  
///优化的next数组  
void get_nextval(char s[], int nextval[])  
{  
    int i, j, len;  
    i = 0;  
    j = -1;  
    len = strlen(s);  
    nextval[0] = -1;  
    while(i < len)  
    {  
        if(j == -1 || s[i] == s[j])  
        {  
            ++i;  
            ++j;  
            if(s[i] != s[j])  
            {  
                nextval[i] = j;  
            }  
            else  
            {  
                nextval[i] = nextval[j];  
            }  
        }  
        else  
        {  
            j = nextval[j];  
        }  
    }  
}  
  
int kmp(char s[], char t[])  
{  
    int i, j, next[255];  
    int s_len, t_len;  
    i = 0;  
    j = 0;  
    s_len = strlen(s);  
    t_len = strlen(t);  
    get_next(t, next);  
    ///get_nextval(t, next);  
  
    while(i < s_len && j < t_len)  /// j 指向最后一个元素的坐标比数组长度小1  
    {  
        if(j == -1 || s[i] == t[j])  
        {  
            ++i;  
            ++j;  
        }  
        else  
        {  
            j = next[j];  
        }  
    }  
    if(j >= t_len)  
    {  
        return i - t_len;  
    }  
    else  
    {  
        return 0;  
    }  
}  
  
int main()  
{  
    char src[255] = "ABCABCABCD";  /// 空格也算  
    char des[255] = "ABCABCD";  
    int index, pos;  
    index = kmp(src, des);  
    printf("%d\n", index);  
    return 0;  
}