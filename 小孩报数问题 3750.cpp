#include <stdio.h>

int main(void)
{
    int n;
    int w,s;
    int count;
    int size;
    int i;
    int p[65];
    char name[65][20];
    scanf("%d",&n);
    size = n;
    for(i = 0;i < n;i++)
            scanf("%s",name[i]);
    scanf("%d",&w);
    getchar();
    scanf("%d",&s);
    for(i = 0;i < n;i++)
          p[i] = i;
    w = (w + n - 1) % n;
    while(size)
    {           
          w = (w + s - 1) % size; 
          printf("%s\n",name[p[w]]);
          for(i = w;i < size - 1;i++)
                p[i] = p[i+1];
          size --;     
    }
    return 0;
}
