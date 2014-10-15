#include <stdio.h>
#include <stdlib.h>
#define MAXN 5000
int ma[MAXN][MAXN] = {0};
int ans[MAXN];
void clause(int size)
{
     for(int i = 0;i < size;i++)
     {
             for(int j = 0;j < size;j++)
             {
                     if(ma[j][i] == 1)
                     {
                          for(int k = 0;k < size;k++)
                          {
                                  if(ma[i][k] == 1)ma[j][k] = 1;
                          }       
                     }
             }
     }
}
int main(void)
{
    int N,M;
    int cow1,cow2;
    int result = 0;
    scanf("%d%d",&N,&M);
    for(int i = 0;i < N;i++)
            ans[i] = i + 1;
    while(M)
    {
            scanf("%d%d",&cow1,&cow2);
            ma[cow1-1][cow2-1] = 1;
            M --;
    }
    clause(N);
    for(int i = 0;i < N;i++)
    {
            if(ans[i] != 0)
            {
                    for(int j = 0;j < N;j++)
                    {
                            if(ma[i][j] == 0 && i != j)
                            {
                                        if(ma[j][i] == 0 && i != j)
                                        {
                                                    ans[i] = 0;
                                                    ans[j] = 0;
                                        }
                            }
                    }
            }
    }
    for(int i = 0;i < N;i++)
            if(ans[i] != 0)result++;
    printf("%d",result);
    return 0;
}
