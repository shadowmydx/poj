#include <stdio.h>
#include <string.h>


int main(void)
{
    char a1[100];
    int A1[100] = {0};
    char a2[100];
    int A2[100] = {0};
    int jia1,jia2,i,j,flag,flag1;
    int n;
    scanf("%d",&n);
    while(n)
    {
            scanf("%s%s",a1,a2);
            jia1 = strlen(a1);
            jia2 = strlen(a2);
            for(i = jia1 - 1;i >= 0;i--)
                  A1[i] = a1[i] - '0';
            for(i = jia2 - 1;i >= 0;i--)
                  A2[i] = a2[i] - '0';
            for(i = 0;i < (jia1 > jia2 ? jia1 : jia2);i++)
            {
                  A2[i] = A2[i] + A1[i];
                  if(A2[i] > 9)
                  {
                           A2[i] -= 10;
                           A2[i+1]++;
                  }
            }
            j = jia1 > jia2 ? jia1 : jia2;
            if(A2[j] == 0)flag1 = 0;
            else flag1 = 1;
            flag = 0;
            for(i = 0;i < (jia1 > jia2 ? jia1 : jia2) + flag1;i++)
            {
                  if(flag == 0 && A2[i] == 0)
                  {
                          continue;
                  }
                  else
                  {
                      flag = 1;
                  }
                  printf("%d",A2[i]);
            }
            printf("\n");
            for(i = 0;i < 100;i++)
            {
                  A1[i] = 0;
                  A2[i] = 0;
            }
            n --;
    }
    return 0;
}
