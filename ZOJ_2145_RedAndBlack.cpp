#include <stdio.h>

char house[30][30];
int  w,h;

int DFS(int x,int y)
{
    if(x < 0 || y < 0 || x >= h || y >= w)
        return 0;
    if(house[x][y] == '#')
        return 0;
    house[x][y] = '#';
    int result = 0;
    for(int i = -1;i <= 1;i++)
    {
        result += DFS(x+i,y);
        result += DFS(x,y+i);
    }
    return 1 + result;
}

int countBlack()
{
    int startX,startY;
    for(int i = 0;i < h;i++)
    {
        for(int j = 0;j < w;j++)
        {
            if(house[i][j] == '@')
            {
                startX = i;
                startY = j;
                break;
            }
        }
    }
    return DFS(startX,startY);
}

int main(void)
{
    while(1)
    {
        scanf("%d%d",&w,&h);
        if(0 == w && 0 == h)
            break;
        for(int i = 0;i < h;i++)
            scanf("%s",house[i]);
        int result = countBlack();
        printf("%d\n",result);
    }
    return 0;
}
