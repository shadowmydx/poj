#include <stdio.h>
#include <string.h>

struct temp
{
       int x;
       int y;
       int z;
};
int main(void)
{
    char a[210];
    char b[210];
    char c[500];
    char f[2][10] = {"no","yes"};
    int i,j,k,flag;
    int la,lb,lc;
    int top = -1;
    int n;
    int start = 1;
    temp d[500];
    scanf("%d",&n);
    while(n)
    {
            scanf("%s%s%s",a,b,c);
            i = 0;
            j = 0;
            k = 0;
            top = -1;
            flag = 1;
            la = strlen(a);
            lb = strlen(b);
            lc = strlen(c);
            while(k < lc)
            {
                    if(a[i] == c[k] && b[j] == c[k])
                    {
                            d[++top].x = i;
                            d[top].y = j;
                            d[top].z = k;
                            i++;
                            k++;
                    }
                    else if(a[i] == c[k])
                    {
                         i++;
                         k++;
                    }
                    else if(b[j] == c[k])
                    {
                         j++;
                         k++;
                    }
                    else if(top >= 0 && k < lc - 1)
                    {
                         i = d[top].x;
                         j = d[top].y;
                         k = d[top].z;
                         top --;
                         j++;
                         k++;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
            }
            printf("Data set %d: %s\n",start,f[flag]);
            start ++;
            n --;
    }
    return 0;
}
