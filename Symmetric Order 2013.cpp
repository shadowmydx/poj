#include <stdio.h>
#include <string.h>
int main(void)
{
    char zi[100][100];
    char temp[100][100] = {0};
    int count;
    int start = 1;
    int i,j,k,p;
    while(scanf("%d",&count))
    {
                             if(0 == count)break;
                             k = 0;
                             p = count - 1;
                             for(i = 0;i < count;i++)
                                   scanf("%s",&zi[i]);
                             for(j = 0,i = 1;j < count && i < count;j += 2,i += 2)
                             {
                                   strcpy(temp[k],zi[j]);
                                   strcpy(temp[p],zi[i]);
                                   k++;
                                   p--;
                             }
                             if(count % 2 != 0)
                                      strcpy(temp[k],zi[count-1]);
                             printf("SET %d\n",start);
                             for(i = 0;i < count;i++)
                                   printf("%s\n",temp[i]);     
                             start ++;
    }
    return 0;
}
