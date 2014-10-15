#include <stdio.h>

int main(void)
{
    char c;
    int sum = 0;
    int i = 1;
    while(1)
    {
            c = getchar();
            if(c == '\n')
            {
                 printf("%d\n",sum);
                 i = 0;
                 sum = 0;
            }
            else if(c == '#')break;
            else if(c >= 65)sum += i * (c - 64);
            i++;
    }
    return 0;
}
