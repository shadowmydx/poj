#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n,temp;
    int a[2000];
    int b[2000];
    int top = -1;
    int i,j;
    int flag;
    int start = 0;
    //FILE *fp = fopen("c:\\data\\rails.in","r");
    for(i = 0;i < 2000;i++)
          a[i] = i + 1;
    while(scanf("%d",&n))
    {
                         if(0 == n)break;
                         if(start)printf("\n");
                         start = 1;
                         flag = 1;
                         top = -1;
                         i = 0;
                         while(1)
                         {
                                     scanf("%d",&temp);
                                     if(temp == 0)
                                     {
                                             top = -1;
                                             i = 0;
                                             break;
                                     }
                                     else
                                     {
                                         if(a[i] == temp)
                                                 i++;
                                         else 
                                         {
                                             while(a[i] != temp && i < n)
                                             { 
                                              b[++top] = a[i];
                                              i++;
                                              }
                                              if(a[i] == temp)i++; 
                                         }
                                         for(j = 1;j < n;j++)
                                         {
                                                 scanf("%d",&temp);
                                                 if(!flag)continue;
                                                 if(i < n && a[i] == temp)
                                                 {
                                                        
                                                         i++;
                                                 }
                                                 else if(b[top] == temp && top >= 0)
                                                 {
                                                      
                                                      top --;
                                                 }
                                                 else if(i < n)
                                                 {
                                                      while(a[i] != temp && i < n)
                                                      {
                                                                 b[++top] = a[i];
                                                                 i++;
                                                      }
                                                      if(a[i] == temp)i++;   
                                                 }  
                                                 else
                                                 {
                                                     if(temp != b[top])flag = 0;
                                                 }                                 
                                         }
                                         if(flag)printf("Yes\n");
                                         else printf("No\n");
                                         flag = 1;
                                         i = 0;
                                         top = -1;
                                     }
                         }
    }
    getchar();
    return 0;
}
