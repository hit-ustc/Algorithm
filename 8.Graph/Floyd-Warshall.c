#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
#define INF 999999  
  
int main(int argc, char const *argv[])  
{  
    int k, i, j, n, m;  
    int q1, q2, q3;  
    int e[10][10];  
  
    scanf("%d %d", &n, &m);  
  
    for(i = 1; i <= n; ++i)  
    {  
        for(j = 1; j <= n; ++j)  
        {  
            if(i == j)  
            {  
                e[i][j] = 0;  
            }  
            else  
            {  
                e[i][j] = INF;  
            }  
        }  
    }  
  
    for(i = 1; i <= m; ++i)  
    {  
        scanf("%d %d %d", &q1, &q2, &q3);  
        e[q1][q2] = q3;  
    }  
  
    for(k = 1; k <= n; ++k)             /// Floyd-Warshall 算法核心语句  
    {  
        for(i = 1; i <= n; ++i)  
        {  
            for(j = 1; j <= n; ++j)  
            {  
                if(e[i][j] > e[i][k] + e[k][j])  
                {  
                    e[i][j] = e[i][k] + e[k][j];  
                }  
            }  
        }  
    }  
  
    for(i = 1; i <= n; ++i)  
    {  
        for(j = 1; j <= n; ++j)  
        {  
            printf("%5d", e[i][j]);  
        }  
        printf("\n");  
    }  
  
    system("pause");  
    return 0;  
}