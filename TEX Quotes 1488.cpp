#include <stdio.h>
int main(void)
{
    char c;
    int flag = 1;
    while((c = getchar())!= EOF)
    {
             if(c == '"' && flag == 1)
             {
                  printf("%c%c",96,96);
                  flag = !flag;
             }
             else if(c == '"' && flag == 0)
             {
                  printf("%c%c",39,39);
                  flag = !flag;
             }
             else
                 printf("%c",c);
    }
    return 0;
}
