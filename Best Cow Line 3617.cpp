#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[3000];
    char b[3000];
    char c;
    int i,j,p,k,q,ans = 0;
    int la;
    int N;
    scanf("%d",&N);
    getchar();
    i = 0;
    while(N)
    {
            c = getchar();
            if(c != '\n')
            {
                 a[i] = c;
                 i++;
            }
            else
                N --;
            
    }
    a[i] = '\0';
    la = strlen(a);
    i = 0;
    j = la - 1;
    for(k = 0;k < la;)
    {
          if(a[i] < a[j])
          {
                  b[k] = a[i];
                  i++;
                  k++;
          }
          else if(a[i] > a[j])
          {
               b[k] = a[j];
               j--;
               k++;
          }
          else if(i == j)
          {
               b[k] = a[i];
               break;
          }
          else if(a[i] == a[j])
          {
               p = i;
               q = j;
               while(p < q && a[p] == a[q])
               {
                       p++;
                       q--;
               }
                   if(a[p] < a[q])
                   {
                           b[k] = a[i];
                           i++;
                           k++;
                   }
                   else 
                   {
                        b[k] = a[j];
                        j--;
                        k++;
                   }
               
          }
    }
    b[k+1] = '\0';
    j = strlen(b);
        for(i = 0; i < j; i++) {
            printf("%c", b[i]);
            ans++;
            if(ans % 80 == 0 && i < j - 1)
                printf("\n");
        }

    return 0;
}
