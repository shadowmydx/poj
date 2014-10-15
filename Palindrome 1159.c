#include <stdio.h>
int dp[5001][5001];
int fun(int a,int b,char *c)
{
    if(a >= b)return 0;
    if(dp[a][b] != 0)return dp[a][b];
    if(c[a] == c[b])return dp[a][b] = fun(a+1,b-1,c);
    else
    {
        int tmp1,tmp2;
        return dp[a][b] = (tmp1 = fun(a+1,b,c)) > (tmp2 = fun(a,b-1,c)) ? tmp2 + 1 : tmp1 + 1;
    }
}
int main(void)
{
    char c[5001];
    int N;
    scanf("%d",&N);
    scanf("%s",c);
    printf("%d\n",fun(0,N-1,c));
    return 0;
}
