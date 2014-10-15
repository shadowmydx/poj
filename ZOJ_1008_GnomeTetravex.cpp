#include <stdio.h>

typedef struct vex
{
    int top;
    int right;
    int down;
    int left;
}vex;

vex target[30];
int n,length;
vex result[6][6];
int visit[30];

int haveSol(int x,int y)
{
    if(x >= n)
        return 1;
    int flag = 0;
    int x1 = x - 1;
    int y1 = y;
    int x2 = x;
    int y2 = y - 1;
    int nextY = y + 1;
    int nextX = x;
    if(nextY >= n)
    {
        nextX = x + 1;
        nextY = 0;
    }
    for(int i = 0;i < length;i++)
    {
        if(visit[i] == 0)
        {
            if(x1 >= 0 && y2 >= 0)
            {
                if(target[i].top == result[x1][y1].down && target[i].left == result[x2][y2].right)
                {
                    result[x][y] = target[i];
                    visit[i] = 1;
                    flag = haveSol(nextX,nextY);
                    if(!flag)visit[i] = 0;
                }
            }
            else if(x1 >= 0)
            {
                if(target[i].top == result[x1][y1].down)
                {
                    result[x][y] = target[i];
                    visit[i] = 1;
                    flag = haveSol(nextX,nextY);
                    if(!flag)
                    {
                        visit[i] = 0;
                    }
                }
            }
            else if(y2 >= 0)
            {
                if(target[i].left == result[x2][y2].right)
                {
                    result[x][y] = target[i];
                    visit[i] = 1;
                    flag = haveSol(nextX,nextY);
                    if(!flag)visit[i] = 0;
                }
            }
            else
            {
                    result[x][y] = target[i];
                    visit[i] = 1;
                    flag = haveSol(nextX,nextY);
                    if(!flag)visit[i] = 0;
            }
            if(flag == 1)break;
        }
    }
    return flag;
}

int main(void)
{
    while(scanf("%d",&n))
    {
        if(0 == n)break;
        length = n * n;
        for(int i = 0;i < length;i++)
        {
            vex tmp;
            scanf("%d%d%d%d",&tmp.top,&tmp.right,&tmp.down,&tmp.left);
            target[i] = tmp;
        }
        if(haveSol(0,0))
            printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
