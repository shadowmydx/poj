#include <stdio.h>
int main(void)
{
    int flag = 0;
    int temp = 1;
    int start = 0;
    char cur,pre;
    while((cur = getchar()) != EOF)
    {
                 if(start == 0)
                 {
                          pre = cur;
                          start ++;
                 }    
                 else if(cur == pre && flag == 0)
                 {
                      temp++;
                      pre = cur;
                      if(temp >= 10)
                      {
                              printf("%d%c",temp - 1,pre);
                              temp = 1;
                      }
                 }
                 else if(cur != pre && temp == 1 && flag == 0)
                 {
                      flag = 1;
                      printf("%d%c",1,pre);
                      if(pre == '1')printf("%c",pre);
                      pre = cur;
                 }
                 else if(cur != pre && flag == 1)
                 {
                      printf("%c",pre);
                      if(pre == '1')printf("%c",pre);
                      pre = cur;
                 }
                 else if(cur == pre  && flag == 1)
                 {
                      temp = 2;
                      flag = 0;
                      printf("%d",1);
                      pre = cur;
                 }
                 else if(cur != pre)
                 {
                      printf("%d%c",temp,pre);
                      pre = cur;
                      temp = 1;
                 }
                 if(cur == '\n')
                 {
                        if(flag == 1)printf("%d",1);
                        start = 0;
                        temp = 1;
                        flag = 0;
                        printf("\n");
                 }
    }
    return 0;
}
