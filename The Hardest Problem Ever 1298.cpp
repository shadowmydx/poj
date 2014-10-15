#include <stdio.h>
#include <string.h>

int main(void)
{
    char start[100];
    char temp;
    while(1)
    {
            scanf("%s",start);
            if(strcmp(start,"ENDOFINPUT") == 0)break;
            getchar();
            while((temp = getchar()) != '\n')
            {
                        if(temp >= 65 && temp <= 69)temp += 21;
                        else if(temp > 69 && temp <= 90)temp -= 5;
                        printf("%c",temp);
            }
            printf("\n");
            scanf("%s",start);
    }
    return 0;
}
