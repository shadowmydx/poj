#include <stdio.h>

int main(void)
{
    char a[27];
    char c;
    scanf("%s",a);
    getchar();
    while((c = getchar()) != '\n')
    {
             if(c >= 65 && c <= 90)
             {
                  printf("%c",a[c-65] - 32);
             }
             else if(c >= 97 && c <= 122)
             {
                  printf("%c",a[c-97]);
             }
             else
                 printf("%c",c);
    }
    return 0;
}
