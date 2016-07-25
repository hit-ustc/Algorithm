#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
#define INF 999999  
int book[10];          /// 用来纪录已经是最短路径的点  
  
int main(int argc, char const *argv[])  
{  
    int i, j, m, n;  
    int q1, q2, q3;  
    int u, v, min;  
    int e[100][100], dis[10];  
  
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
  
    for(i = 1; i <= n; ++i)  
    {  
        dis[i] = e[1][i];  
    }  
  
    book[1] = 1;              /// Dijkstra 算法核心  
    for(i = 1; i < n; ++i)      /// 计算n-1次  
    {  
        min = INF;  
        for(j = 1; j <= n; ++j)  
        {  
            if(dis[j] < min && book[j] == 0)  
            {  
                min = dis[j];  
                u = j;  
            }  
        }  
  
  
        book[u] = 1;  
        for(v = 1; v <= n; ++v)  
        {  
            if(e[u][v] != INF && dis[v] > dis[u] + e[u][v])  
            {  
                dis[v] = dis[u] + e[u][v];            /// 这个过程就是"松弛"  
            }  
        }  
    }  
  
    for(i = 1; i <= n; ++i)  
    {  
        printf("%d ", dis[i]);  
    }  
    printf("\n");  
  
    system("pause");  
    return 0;  
}