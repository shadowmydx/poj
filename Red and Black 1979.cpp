#include <iostream>
using namespace std;
char map[21][21];
int count_1 = 0;
void construct(int *dir,int x,int y,int W,int H)
{
     if(x - 1 >= 0)
     {
          if(map[x-1][y] != '#')dir[0] = 1;
     }
     if(x + 1 < H)
     {
          if(map[x+1][y] != '#')dir[1] = 1;
     }
     if(y - 1 >= 0)
     {
          if(map[x][y-1] != '#')dir[2] = 1;
     }
     if(y + 1 < W)
     {
          if(map[x][y+1] != '#')dir[3] = 1;
     }
}
void DFS(int x,int y,int W,int H)
{
     if(map[x][y] == '#')return;
     int dir[4] = {0,0,0,0}; 
     count_1 ++;
     map[x][y] = '#';
     construct(dir,x,y,W,H);
     for(int i = 0;i < H;i++)
     {
             for(int j = 0;j < W;j++)
                     cout << map[i][j];
             cout << endl;
     }
     for(int i = 0;i < 4;i++)
     {
             if(dir[i] != 0)
             {
                       switch(i)
                       {
                                case 0 : DFS(x-1,y,W,H);
                                         break;
                                case 1 : DFS(x+1,y,W,H);
                                         break;
                                case 2 : DFS(x,y-1,W,H);
                                         break;
                                case 3 : DFS(x,y+1,W,H);
                                         break;
                       }
             }
     }
}
int main(void)
{
    int W,H;
    int result;
    int startX,startY;
    while(1)
    {
            count_1 = 0;
            result = 0;
            cin >> W;  //ÁÐÊý 
            cin >> H;
            if(0 == W || 0 == H)break;
            for(int i = 0;i < H;i++)
            {
                    for(int j = 0;j < W;j++)
                    {
                            cin >> map[i][j];
                            if(map[i][j] == '@')
                            {
                                         startX = i;
                                         startY = j;
                            }
                    }
            }
            DFS(startX,startY,W,H);
            cout << count_1 << endl;
    }
    return 0;
}
