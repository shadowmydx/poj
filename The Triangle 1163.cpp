#include <iostream>
using namespace std;
int num[101][101] = {0};
int ans[101][101];
int max(int x,int y)
{
    if(x >= y)return x;
    else return y;
}
int fun(int x,int y)
{
    if(x == 0 && y == 0)
         return ans[0][0] = num[0][0],ans[0][0];
    if(ans[x][y] != -1)return ans[x][y];
    int x1,y1,y2;
    x1 = x - 1;
    y1 = y;
    y2 = y - 1;
    if(x == y)
    {
         ans[x][y] = fun(x1,y2) + num[x][y];
         return ans[x][y];
    }
    else if(y2 < 0) //遗漏了这种情况！！ 
    {
         ans[x][y] = fun(x1,y1) + num[x][y];
         return ans[x][y];
    }
    else
    {
        ans[x][y] = max(fun(x1,y1),fun(x1,y2)) + num[x][y];
        return ans[x][y];
    }
}
int main(void)
{
    int N;
    int i,j;
    int temp;
    int max = -1;
    cin >> N;
    for(i = 0;i < 101;i++)
          for(j = 0;j < 101;j++)
                ans[i][j] = -1;
    for(i = 0;i < N;i++)
    {
          for(j = 0;j <= i;j++)
                cin >> num[i][j];
    }
    i--,j--;
    for(j = 0;j < N;j++)
    {
        temp = fun(i,j);
        if(temp >= max)max = temp;
    }
    cout << max;
    return 0;
}
