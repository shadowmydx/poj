#include <stdio.h>
#include <queue>
using namespace std;
/*
��������Сʱ��ʱ�䣡������
��Ȼ��������ն��еĵͼ�BUG��������

1������Ƿ���ʹ�ĳ����㣬������ʹ���������ӣ�
2�������ǰ�Ľ��ֵ��x������Ҫ��������ʹ��Ľ���ٴ���ӣ�������Ϊ.�����ֲ�����չ�������ڽ��õ�չ��Ϊһ���߶Σ�ͷ��չ�Ľ����β��β��չ��Χ�Ľ��
*/
typedef struct point
{
    int x;
    int y;
}point;

queue<point> road;
char prison[201][201];
int  visit[201][201];
int  high[201][201];
int n,m;
int startX,startY;

void init()
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(prison[i][j] == 'a')
            {
                startX = i;
                startY = j;
            }
        }
    }
    for(int i = 0;i < 201;i++)
        for(int j = 0;j < 201;j++)
        {
            high[i][j] = 0;
            visit[i][j] = 0;
        }
    while(!road.empty())
        road.pop();
}

void BFS()
{
    point tmp;
    point p1;
    tmp.x = startX;
    tmp.y = startY;
    int finalX,finalY;
    high[startX][startY] = 0;
    visit[startX][startY] = 1;
    road.push(tmp);
    int flag = 0;
    while(!road.empty())
    {
        tmp = road.front();
        road.pop();
        if(prison[tmp.x][tmp.y] == 'x')
        {
            road.push(tmp);
            high[tmp.x][tmp.y] ++;
            prison[tmp.x][tmp.y] = '.';
        }
        else if(prison[tmp.x][tmp.y] == 'r')
        {
            flag = 1;
            finalX = tmp.x;
            finalY = tmp.y;
            break;
        }
        else
        {
            for(int i = -1;i <= 1;i++)
            {
                if(0 == i)continue;
                if(tmp.x + i >= 0 && tmp.x + i < n)
                {
                    if(visit[tmp.x+i][tmp.y] == 0 && prison[tmp.x+i][tmp.y] != '#')
                    {
                        visit[tmp.x+i][tmp.y] = 1;
                        p1.x = tmp.x + i;
                        p1.y = tmp.y;
                        high[p1.x][p1.y] = high[tmp.x][tmp.y] + 1;
                        road.push(p1);
                    }
                }
                if(tmp.y + i >= 0 && tmp.y + i < m)
                {
                    if(visit[tmp.x][tmp.y+i] == 0 && prison[tmp.x][tmp.y+i] != '#')
                    {
                        visit[tmp.x][tmp.y+i] = 1;
                        p1.x = tmp.x;
                        p1.y = tmp.y + i;
                        high[p1.x][p1.y] = high[tmp.x][tmp.y] + 1;
                        road.push(p1);
                    }
                }
            }
        }
    }
    if(flag)
    {
        printf("%d\n",high[finalX][finalY]);
    }
    else printf("Poor ANGEL has to stay in the prison all his life.\n");
}

int main(void)
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%s",prison[i]);
        init();
        BFS();
    }
    return 0;
}
