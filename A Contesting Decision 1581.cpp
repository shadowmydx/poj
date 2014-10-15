#include <stdio.h>
#include <string.h>

int main(void)
{
    int time[4] = {0};
    int timu[4] = {0};
    int ac,totaltime,maxac = 0,mintime = -1;
    char team[100];
    char cham[100];
    int i;
    int N;
    scanf("%d",&N);
    while(N)
    {
            ac = 0;
            totaltime = 0;
            scanf("%s",team);
            for(i = 0;i < 4;i++)
            {
                  scanf("%d%d",&timu[i],&time[i]);
                  if(time[i] != 0)
                  {
                             ac++;
                             totaltime += (timu[i] - 1) * 20 + time[i];
                  } 
            }
            if(mintime == -1)mintime = totaltime;
            if(ac >= maxac)
            {
                  if(ac == maxac)
                  {
                        if(totaltime <= mintime)
                        {
                                     strcpy(cham,team);
                                     maxac = ac;
                                     mintime = totaltime;     
                        }
                  }
                  else
                  {
                                     strcpy(cham,team);
                                     maxac = ac;
                                     mintime = totaltime;                      
                  }
            }
            N--;
    }
    printf("%s %d %d\n",cham,maxac,mintime);
    return 0;
}
