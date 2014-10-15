#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    int a[10];
    int la,lc;
    int flag1 = 1;
    int sum = 0;
    int count = 0;
    int wei = 1;
    char work1[12];
    char temp[12];
    char work[12];
    work[0] = 'a';
    work[1] = '\0';
    scanf("%s",temp);
    lc = strlen(temp);
    for(int i = lc - 1;i >= 1;i--)
    {
            if(temp[i-1] < temp[i])flag1 = 1;
            else {flag1 = 0;break;}
    }
    if(flag1 == 0)wei = 12;
    while(wei < 11)
    {
           int flag = 0,j = 0;
           if(wei == lc)
           {
                  if(strcmp(temp,work) == 0)
                  {
                                       break;
                  }
                  
           }
           la = strlen(work);
           for(int i = la - 1;i >= 0;i--)
           {
                    work1[i] = 'z' - j;
                    j++;
           }
           for(int i = la - 1;i >= 0;i--)
           {
                   if(work[i] < work1[i])
                   {
                              work[i]++;
                              flag = 1;
                              for(int j = i + 1;j < wei;j++)
                                      work[j] = work[j-1] + 1;
                              sum++;
                              break;
                   }
           }
           if(flag == 0)
           {
                   wei++;
                   for(int i = 0;i < wei;i++)
                           work[i] = 'a' + i;
                   work[wei] = '\0';
                   sum++;
           }
    }
    if(wei < 12)
           printf("%d\n",sum+1);
    else printf("%d\n",0);
    return 0;
}
