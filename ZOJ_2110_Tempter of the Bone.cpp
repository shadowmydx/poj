#include <stdio.h>
#include <stdlib.h>
char tempter[10][10];
int  visit[10][10];
int m,n,t;
int startX,startY;
int exitX,exitY;

int canTravel(int x1,int y1,int x2,int y2,int step)
{
    //printf("%c,x1 = %d,y1 = %d,step = %d\n",tempter[x1][y1],x1,y1,step);
    if(x1 == x2 && y1 == y2 && step == 0)
        return 1;
    if(step <= 0)
        return 0;
    visit[x1][y1] = 1;
    int flag = 0;
    for(int i = 1;i >= -1;i--)
    {
        if(i == 0)continue;
        if(x1+i >= 0 && x1+i < n && visit[x1+i][y1] != 1 && tempter[x1+i][y1] != 'X')
        {
            flag = canTravel(x1+i,y1,x2,y2,step-1);
        }
        if(flag == 0 && y1+i >= 0 && y1+i < m && visit[x1][y1+i] != 1 && tempter[x1][y1+i] != 'X')
        {
            flag = canTravel(x1,y1+i,x2,y2,step-1);
        }
        if(flag == 1)break;
    }
    visit[x1][y1] = 0;
    return flag;
}

void getResult()
{
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
        {
            if(tempter[i][j] == 'S')
            {
                startX = i;
                startY = j;
            }
            if(tempter[i][j] == 'D')
            {
                exitX = i;
                exitY = j;
            }
        }
    if(canTravel(startX,startY,exitX,exitY,t))
    {
        printf("YES\n");
    }
    else printf("NO\n");
}

int main(void)
{
    while(scanf("%d%d%d",&n,&m,&t))
    {
        if(0 == m && 0 == n && 0 == t)break;
        getchar();
        for(int i = 0;i < n;i++)
            scanf("%s",tempter[i]);
        getResult();
    }
    return 0;
}
