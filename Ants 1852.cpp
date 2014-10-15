#include <stdio.h>

int main(void)
{
    int N,l,n;
    int ant;
    int min,max,tempmin,tempmax;
    scanf("%d",&N);
    while(N)
    {
            min = 0;
            max = 0;
            scanf("%d%d",&l,&n);
            for(int i = 0;i < n;i++)
            {
                    scanf("%d",&ant);
                    if(l - ant > ant)
                    {
                         tempmin = ant;
                         tempmax = l - ant;
                    }
                    else
                    {
                        tempmin = l - ant;
                        tempmax = ant;
                    }
                    if(tempmin > min)min = tempmin;
                    if(tempmax > max)max = tempmax;
            }
            printf("%d %d\n",min,max);
            N --;
    }
    return 0;
}
