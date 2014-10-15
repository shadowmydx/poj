#include <stdio.h>
#include <ctype.h>
#define NUM 1000000
#define MAXM 10000000

int ans[MAXM] = {0};
int fun(char c)
{
    if(isdigit(c))return c - 48;
    else if(c == 'Q' || c == 'Z')return -1;
    else if(c >= 65 && c <= 67)return 2;
    else if(c >= 68 && c <= 70)return 3;
    else if(c >= 71 && c <= 73)return 4;
    else if(c >= 74 && c <= 76)return 5;
    else if(c >= 77 && c <= 79)return 6;
    else if(c >= 80 && c <= 83)return 7;
    else if(c >= 84 && c <= 86)return 8;
    else if(c >= 87 && c <= 89)return 9;
    else return -1;
}
int main(void)
{
    char c;
    int n;
    int num;
    int result;
    int i,j,k,p;
    int temp1;
    int temp2;
    int flag = 1;
    scanf("%d",&n);
    getchar();
    while(n)
    {
            result = 0;
            i = NUM;
            while((c = getchar()) != '\n')
            {
                     if(fun(c) >= 0)num = fun(c);
                     else continue;
                     result += num * i;
                     i /= 10;
            }
            ans[result]++;
            n --;
    }
    for(i = 0;i < MAXM;i++)
    {
          if(ans[i] > 1)
          {
                 j = 0;
                 k = 0;
                 flag = 0;
                 temp1 = i / 10000;
                 temp2 = i % 10000;
                 if(temp1 < 100 && temp1 >= 10)j = 1;
                 else if(temp1 >= 0 && temp1 < 10)j = 2;
                 if(temp2 < 1000 && temp2 >= 100)k = 1;
                 else if(temp2 < 100 && temp2 >= 10)k = 2;
                 else if(temp2 < 10 && temp2 >= 0)k = 3;
                 for(p = 0;p < j;p++)
                       printf("%d",0);
                 printf("%d%c",temp1,'-');
                 for(p = 0;p < k;p++)
                       printf("%d",0);
                 printf("%d %d\n",temp2,ans[i]); 
          }
    }
    if(flag)printf("No duplicates.\n");
    return 0;
}
