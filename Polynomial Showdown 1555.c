#include <stdio.h>
#include <math.h>
void print(int num,int po)
{
    if(po == 0)printf("%d",num);
    else if(po == 1)
    {
            if(num != 1)printf("%dx",num);
            else printf("x");
    }
    else
    {
        if(num != 1)printf("%dx^%d",num,po);
        else printf("x^%d",po);
    }
}
int main(void)
{
    int i = 0;
    int num;
    int start = 0;
    char oper = '+';
    while(scanf("%d",&num) != EOF)
    {
        if(!start && num != 0)
        {
            if(num < 0)printf("-");
            print(abs(num),8 - i);
            start = 1;
        }
        else if(num != 0)
        {
            if(num < 0)printf(" - ");
            else printf(" + ");
            print(abs(num),8 - i);
        }
        else if(i == 8 && !start && num == 0)
        {
            printf("0");
        }
        i++;
        if(i > 8)
        {
            i = 0;
            start = 0;
            printf("\n");
        }
    }
    return 0;
}
