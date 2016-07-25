/****************************************************************** 
游戏规则：将一副扑克牌平均分为两份，每人拿一份，A先拿出手中的第一张扑克牌放在桌上，
然后B也拿出手中的第一张扑克牌，并放在A刚打出的扑克牌的上面，就像这样两人交替出牌. 
出牌时如果某人打出的牌与桌上某张牌的牌面相同时，即可将两张相同的牌及其中间所夹的牌全部取走，
并依次放到自己手中牌的末尾，当其中一人手中的牌全部出完时，游戏结束，对方获胜.

假设游戏开始，预设牌面只有1~9，A手中有6张牌，顺序为：2 4 1 2 5 6，
B手中也有6张牌，顺序为：3 1 3 5 6 4. 最终谁会获胜？

Solution: A，B主要是有两种操作，分别是出牌和赢牌. 这恰好是队列的出队和入队两个操作，
而桌子就是一个栈，每打出一张牌就等于入栈，当有人赢牌时就相当于出栈拿走牌. 
取走牌的规则是某人打出的牌与桌上某张相同，这里我们可以类似桶排序用一个数组记录桌上有哪些牌，
当然枚举用一个for循环也是可以的.
******************************************************************/ 
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
struct queue  
{  
    int data[1000];  
    int head;  
    int tail;  
};  
  
struct stack  
{  
    int data[10];  
    int top;  
};  
  
int main(int argc, char const *argv[])  
{  
    struct queue q1, q2;  
    struct stack s;  
    int book[10];  
    int i, t;  
  
    q1.head = q1.tail = 0;  
    q2.head = q2.tail = 0;  
  
    s.top = -1;  
  
    for (i = 1; i <= 9; ++i)         /// 记录桌上有哪些牌，初始为空  
    {  
        book[i] = 0;  
    }  
  
  
    for (i = 0; i < 6; ++i)  
    {  
        scanf("%d", &q1.data[q1.tail++]);  
    }  
  
    for (i = 0; i < 6; ++i)  
    {  
        scanf("%d", &q2.data[q2.tail++]);  
    }  
  
    while(q1.head < q1.tail && q2.head < q2.tail)  
    {  
        t = q1.data[q1.head];       /// 第一个人出第一张牌 出队  
        if(0 == book[t])            /// 桌上没有这张牌 入栈  
        {  
            s.data[++s.top] = t;  
            book[t] = 1;        /// 并标记桌上已经有牌面为t的牌  
            q1.head++;  
        }  
        else  
        {  
            q1.data[q1.tail++] = t;         /// 赢牌  
            q1.head++;  
            while(s.data[s.top] != t)       /// 把相同的牌放到某人手中牌的末尾  
            {  
                book[s.data[s.top]] = 0;  
                q1.data[q1.tail++] = s.data[s.top--];  
            }  
        }  
  
        t = q2.data[q2.head];  
        if(0 == book[t])  
        {  
            s.data[++s.top] = t;  
            book[t] = 1;  
            q2.head++;  
        }  
        else  
        {  
            q2.data[q2.tail++] = t;  
            q2.head++;  
            while(s.data[s.top] != t)  
            {  
                book[s.data[s.top]] = 0;  
                q2.data[q2.tail++] = s.data[s.top--];  
            }  
        }  
    }  
  
    if(q2.head == q2.tail)                 /// 对手手中没有牌  
    {  
        printf("\nA win\n");  
        printf("A手中的纸牌: ");  
        for (i = q1.head; i < q1.tail; ++i)  
        {  
            printf("%d ", q1.data[i]);  
        }  
  
        if(s.top > -1)                       /// 输出桌上的牌  
        {  
            printf("\n桌上的牌: ");  
            for (i = 0; i <= s.top; ++i)  
            {  
                printf("%d ", s.data[i]);  
            }  
        }  
        else  
        {  
            printf("\n桌上已经没有纸牌了！");  
        }  
    }  
    else  
    {  
        printf("\nB win\n");  
        printf("B手中的纸牌: ");  
        for (i = q2.head; i < q2.tail; ++i)  
        {  
            printf("%d ", q2.data[i]);  
        }  
  
        if(s.top > -1)  
        {  
            printf("\n桌上的牌: ");  
            for (i = 0; i <= s.top; ++i)  
            {  
                printf("%d ", s.data[i]);  
            }  
        }  
        else  
        {  
            printf("\n桌上已经没有纸牌了！");  
        }  
    }  
    return 0;  
}