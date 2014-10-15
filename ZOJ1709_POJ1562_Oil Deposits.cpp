#include <stdio.h>
int visit[102][102];
char oil[102][102];
int m,n;

void init()
{
    for(int i = 0;i < 102;i++)
        for(int j = 0;j < 102;j++)
            visit[i][j] = 0;
}

void DFS(int x,int y)
{
    visit[x][y] = 1;
    for(int j = 1;j >= -1;j--)
    {
        for(int i = 1;i >= -1;i--)
        {
            if(0 == i && j == 0)continue;
            if(x+i >= 0 && x+i < m && y+j >= 0 && y+j < n && oil[x+i][y+j] == '@' && visit[x+i][y+j] == 0)
            {
                DFS(x+i,y+j);
            }
        }
    }
}

int countPocket()
{
    int result = 0;
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(oil[i][j] == '@' && visit[i][j] == 0)
            {
                result ++;
                DFS(i,j);
            }
        }
    }
    return result;
}

int main(void)
{
    while(scanf("%d%d",&m,&n))
    {
        if(0 == m)break;
        init();
        for(int i = 0;i < m;i++)
            scanf("%s",oil[i]);
        int result = countPocket();
        printf("%d\n",result);
    }
    return 0;
}
