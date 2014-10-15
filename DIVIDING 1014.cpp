#include <stdio.h>

int main(void)
{
    int a[6] = {0};
    int temp[4] = {0};
    int i,j,k,p,q;
    int result;
    int sum;
    int flag;
    int start = 1;
    while(1)
    {
            flag = 0;
            sum = 0;
            for(i = 0;i < 6;i++)
            {
                  scanf("%d",&a[i]);
                  sum += a[i] * (i + 1);
            }
            if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0)break;
            if(sum % 2 != 0)
            {
                   flag = 0;
            }
            else 
            {
                 result = sum / 2;
                 for(i = 0;i <= a[0];i++)
                 {
                       if(flag)break;
                       for(j = 0;j <= a[1];j++)
                       {
                             temp[0] = i + 2 * j;
                             if(temp[0] > result || flag == 1)break;
                             for(k = 0;k <= a[2];k++)
                             {
                                   temp[1] = temp[0] + 3 * k;
                                   if(temp[1] > result || flag == 1)break;
                                   for(p = 0;p <= a[3];p++)
                                   {
                                         temp[2] = temp[1] + 4 * p;
                                         if(temp[2] > result || flag == 1)break;
                                         for(q = 0;q <= a[4];q++)
                                         {
                                               temp[3] = temp[2] + 5 * q;
                                               if(temp[3] > result || flag == 1)break;
                                               if(temp[3] == result){flag = 1;break;}
                                               else if((result - temp[3]) % 6 == 0)
                                               {
                                                    if(a[5] >= (result - temp[3]) / 6)
                                                    {
                                                            flag = 1;
                                                            break;
                                                    }
                                               }
                                         }
                                   }
                             }
                       }
                 }
            }
            printf("Collection #%d:\n",start);
            if(flag)
            {
                    printf("Can be divided.\n");
            }
            else
            {
                printf("Can't be divided.\n");
            }
            printf("\n");
            start ++;
    }
    return 0;
}
