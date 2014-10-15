#include <stdio.h>

int direction[11] = {12,9,6,3,10,5,13,14,7,11,15};
char farm[60][60];
int trueFarm[60][60];
int visit[60][60];
int m,n;

void init()
{
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            trueFarm[i][j] = direction[farm[i][j] - 'A'];
            visit[i][j] = 0;
        }
    }
}

void DFS(int x,int y)
{
    visit[x][y] = 1;
    for(int i = 1;i <= 8; i <<= 1)
    {
        if((trueFarm[x][y] & i) != 0) //注意！！你能去那个格子的同时，那个格子也能接着你！
        {
            switch(i)
            {
                case 1: if(y+1 < n && visit[x][y+1] == 0 && (trueFarm[x][y+1] & 4))DFS(x,y+1);
                        break;
                case 2: if(x+1 < m && visit[x+1][y] == 0 && (trueFarm[x+1][y] & 8))DFS(x+1,y);
                        break;
                case 4: if(y-1 >= 0 && visit[x][y-1] == 0 && (trueFarm[x][y-1] & 1))DFS(x,y-1);
                        break;
                case 8: if(x-1 >= 0 && visit[x-1][y] == 0 && (trueFarm[x-1][y] & 2))DFS(x-1,y);
                        break;
            }
        }
    }
}

int countWater()
{
    int result = 0;
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(visit[i][j] == 0)
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
        if(m < 0 || n < 0)break;
        for(int i = 0;i < m;i++)
            scanf("%s",farm[i]);
        init();
        int result = countWater();
        printf("%d\n",result);
    }
    return 0;
}
