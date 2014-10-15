/*
错误
1、忘记考虑相同距离
2、忘记重置hotel数组
*/
#include <stdio.h>
int hotel[10001] = {0};
int main(void)
{
    int N;
    int i;
    int tmp1,tmp2;
    int max,min;
    int maxPrice;
    int result;
    while(scanf("%d",&N))
    {
        max = 0;
        min = 10001;
        result = 0;
        if(N == 0)break;
        for(i = 0;i < N;i++)
        {
            scanf("%d%d",&tmp1,&tmp2);
            if(hotel[tmp1] == 0)hotel[tmp1] = tmp2;
            else
            {
                if(tmp2 < hotel[tmp1])hotel[tmp1] = tmp2;
            }
            if(tmp1 >= max)max = tmp1;
            if(tmp1 <= min)min = tmp1;
        }
        maxPrice = hotel[min] + 1;
        for(i = min;i <= max;i++)
        {
            if(hotel[i] == 0)continue;
            if(hotel[i] < maxPrice)
            {
                result ++;
                maxPrice = hotel[i];
            }
            hotel[i] = 0;
        }
        printf("%d\n",result);
    }
    return 0;
}
