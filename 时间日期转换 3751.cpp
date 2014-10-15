#include <stdio.h>
#include <string.h>
int main(void)
{
    int T,i,j,top,p,la;
    int temp1;
    char a[100];
    char b[102];
    char temp;
    scanf("%d",&T);
    while(T)
    {
            scanf("%s",a);
            la = strlen(a);
            top = -1;
            for(i = 0;a[i] != '/';i++)
                  b[++top] = a[i];
            for(j = 0;j <= 4;j++)
            {
                  temp = a[j];
                  a[j] = a[i + j + 1];
                  a[i + j + 1] = temp;
            }
            a[j] = '/';
            for(i = j + 1,p = 0;p <= top;i++,p++)
                  a[i] = b[p];
            i++;
            temp1 = (a[i] - '0') * 10 + (a[i+1] - '0');
            if(temp1 > 12)
            {
                     temp1 -= 12;
                     a[i] = temp1 / 10 + '0';
                     a[i+1] = temp1 % 10 + '0';
                     a[la] = 'p';
                     a[la+1] = 'm';
                     a[la+2] = '\0';
            }
            else if(temp1 == 12)
            {
                     a[la] = 'p';
                     a[la+1] = 'm';
                     a[la+2] = '\0';                 
            }
            else if(temp1 == 0)
            {
                     a[i] = 1 + '0';
                     a[i+1] = 2 + '0';
                     a[la] = 'a';
                     a[la+1] = 'm';
                     a[la+2] = '\0';                 
            }
            else
            {
                     a[la] = 'a';
                     a[la+1] = 'm';
                     a[la+2] = '\0';                
            }
            printf("%s\n",a);
            T --;
    }
    return 0;
}
