#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a[22][22] = {0};
    int N,S,temp;
    int i = 0;
    scanf("%d%d",&N,&S);
    for(int j = 0;j < N;j++)
    {
            i = 0;
            while(i <= j)
            {
                    a[i][j] = S;
                    S ++;
                    if(S > 9)S = 1;
                    i++;
            }          
    }
    for(int i = 0;i < N;i++)
    {
            temp = i;
            for(;temp > 0;temp--)
            {
                      printf("  ");
            }
            for(int j = 0;j < N;j++)
            {
                    if(a[i][j] != 0 && j != N - 1)printf("%d ",a[i][j]);
                    else if(a[i][j] != 0 && j == N - 1)printf("%d",a[i][j]);
            }
            printf("\n");
    }
    return 0;
} 
