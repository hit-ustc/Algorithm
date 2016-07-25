#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
#define INF 999999  
  
int book[100];  
  
int main(int argc, char const *argv[])  
{  
    int i, j, m, n, cur;  
    int a, b, e[101][101];  
    int que[10001], head, tail;  
  
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
        scanf("%d %d", &a, &b);  
        e[a][b] = 1;  
        e[a][b] = 1;  
    }  
  
    head = 1;        /// 队列初始化  
    tail = 1;          
  
    que[tail] = 1;   /// 从 1 顶点出发, 将1顶点加入队列    
    ++tail;  
    book[1] = 1;  
  
    while(head < tail)  
    {  
        cur = que[head];  
        for(i = 1; i <= n; ++i)  
        {  
            if(e[cur][i] == 1 && book[i] == 0)  
            {  
                que[tail++] = i;  
                book[i] = 1;  
            }  
        }  
  
        if(tail > n)  
        {  
            break;  
        }  
  
        head++;  
    }  
  
    for(i = 1; i <= n; ++i)  
    {  
        printf("%d ", que[i]);  
    }  
  
    system("pause");  
    return 0;  
}