#include <stdio.h>

int main(void)
{
    char a[100];
    char win[100];
    int i = 0;
    int P1 = 0,P2 = 0;
    int start = 0;
    char tmp;
    while(1)
    {
            tmp = getchar();
            if(tmp == 'E'){getchar();getchar();break;}
            if(start != 0)printf("\n");
            start++;
            a[i] = tmp;
            switch(tmp)
            {
                       case 'R' : win[i] = 'P';
                                  break;
                       case 'P' : win[i] = 'S';
                                  break;
                       case 'S' : win[i] = 'R';
                                  break;
            }
            i++;
            while((tmp = getchar()) != '\n')
            {
                       a[i] = tmp;
                        switch(tmp)
                        {
                                   case 'R' : win[i] = 'P';
                                              break;
                                   case 'P' : win[i] = 'S';
                                              break;
                                   case 'S' : win[i] = 'R';
                                              break;
                        } 
                        i++;                      
            }
            i = 0;
            while((tmp = getchar()) != '\n')
            {
                       if(tmp != a[i])
                       {
                              if(tmp != win[i])P1++;
                              else P2++;
                       }
                       i++;
            }
            printf("P1: %d\n",P1);
            printf("P2: %d",P2);
            P1 = 0;
            P2 = 0;
            i = 0;
    }
    return 0;
}
