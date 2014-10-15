#include <iostream>
using namespace std;
char a[200][200];
int b[200][200] = {0};
int N,M;
void find(int i,int j)
{
    b[i][j] = 1;
    if(i - 1 >= 0 && j - 1 >= 0 && b[i-1][j-1] == 0 && a[i-1][j-1] == 'W')find(i-1,j-1);
    if(i - 1 >= 0 && b[i-1][j] == 0 && a[i-1][j] == 'W')find(i-1,j);
    if(i - 1 >= 0 && j + 1 < M && b[i-1][j+1] == 0 && a[i-1][j+1] == 'W')find(i-1,j+1);
    if(j - 1 >= 0 && b[i][j-1] == 0 && a[i][j-1] == 'W')find(i,j-1);
    if(j + 1 < M && b[i][j+1] == 0 && a[i][j+1] == 'W')find(i,j+1);
    if(i + 1 < N && j - 1 >= 0 && b[i+1][j-1] == 0 && a[i+1][j-1] == 'W')find(i+1,j-1);
    if(i + 1 < N && b[i+1][j] == 0 && a[i+1][j] == 'W')find(i+1,j);
    if(i + 1 < N && j + 1 < M && b[i+1][j+1] == 0 && a[i+1][j+1] == 'W')find(i+1,j+1);
}
int main(void)
{
    int sum = 0;
    cin >> N >> M;
    for(int i = 0;i < N;i++)
    {
            for(int j = 0;j < M;j++)
                    cin >> a[i][j];
    }
    for(int i = 0;i < N;i++)
            for(int j = 0;j < M;j++)
            {
                    if(a[i][j] == 'W' && b[i][j] == 0)
                    {
                               sum++;
                               find(i,j);
                    }
            }
    cout << sum << endl;
    return 0;
}
