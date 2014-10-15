#include <stdio.h>

int main(void)
{
    char c;
    int zi[26] = {0};
    int count = 0;
    int max = 0;
    int temp;
    int i,j;
    while(count < 4)
    {
                c = getchar();
                if(c == '\n')count ++;
                if(c >= 65 && c <= 90)zi[c - 65]++;
    }
    for(i = 0;i < 26;i++)
            if(zi[i] > max)max = zi[i];
    temp = max;
    for(i = 0;i < temp;i++)
    {
            for(j = 0;j < 26;j++)
            {
                    if(zi[j] >= max)printf("*");
                    else printf(" ");
                    if(j < 25)printf(" ");
            }
            printf("\n");
            max --;
    }
    c = 65;
    for(i = 0;i < 26;i++)
    {
          printf("%c",c);
          if(i < 25)printf(" ");
          c++;
    }
    return 0;
}

