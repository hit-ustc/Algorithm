
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
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
#define INF 999999  
int book[101], e[101][101];         /// book 数组代表顶点是否被访问  
int sum, n;  
  
void dfs(int cur)  
{  
    int i;  
    printf("%d ", cur);  
    if(n == ++sum)            ///   所有的顶点全部访问则退出  
    {  
        return;  
    }  
    for(i = 1; i <= n; ++i)  
    {  
        if(e[cur][i] == 1 && book[i] == 0)  
        {  
            book[i] = 1;  
            dfs(i);  
        }  
    }  
}  
  
int main()  
{  
    int i, j, a, b, m;  
    scanf("%d %d", &n, &m);            /// n 代表顶点个数, m 代表边的条数  
    for (i = 1; i <= n; ++i)  
    {  
        for (j = 1; j <= n; ++j)  
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
  
    for(i = 1; i <= m; ++i)      /// 读入顶点之间的边  
    {  
  
        scanf("%d %d", &a, &b);  
        e[a][b] = 1;  
        e[b][a] = 1;  
    }  
  
  
    for(i = 1; i <= n; ++i)       /// 遍历,适用于统计连通分量个数  
    {  
        if(book[i] == 0)  
        {  
            book[i] = 1;  
            dfs(i);  
        }  
    }  
    system("pause");  
    return 0;  
}