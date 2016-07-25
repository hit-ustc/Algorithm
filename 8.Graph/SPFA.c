#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
#define INF 999999  
int book[10];              /// 初始化为顶点都不在队列  
int que[100];              /// 松弛成功并且顶点不在队列则并入队列  
  
int main(int argc, char const *argv[])  
{  
    int i, j, n, m;  
    int q1, q2, q3;  
    int dis[10], e[10][10];  
    int head, tail;  
  
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
        dis[i] = INF;  
    }  
    dis[1] = 0;              /// 初始化dis[1]为0，其他为∞  
  
    head = tail = 1;  
    que[head] = 1;           /// 1号顶点入队  
    book[1] = 1;  
    tail++;  
    while(head < tail)  
    {  
        for(i = 1; i <= n; ++i)  
        {  
            if(e[que[head]][i] != INF && dis[i] > dis[que[head]] + e[que[head]][i])  
            {  
                dis[i] = dis[que[head]] + e[que[head]][i];  
                if (!book[i])               /// 顶点不在队列，加入队列  
                {  
                    book[i] = 1;  
                    que[tail++] = i;  
                }  
            }  
        }  
  
        book[que[head]] = 0;    /// 重新标记不在队列  
        head++;                 /// 相当于出队  
    }  
  
    for(i = 1; i <= n; ++i)  
    {  
        printf("%d ", dis[i]);  
    }  
    printf("\n");  
  
    system("pause");  
    return 0;  
}