#include <stdio.h>


int main(void)
{
    int n,temp;
    int b[2000];
    int top = -1;
    int i,j;
    int flag;
    int start = 0;
    FILE *fp = fopen("c:\\data\\rails.in","r");
    while(fscanf(fp,"%d",&n))
    {
                         if(0 == n)break;
                         if(start)printf("\n");
                         start = 1;
                         flag = 1;
                         top = -1;
                         i = 1;
                         while(1)
                         {
                                     fscanf(fp,"%d",&temp);
                                     if(temp == 0)
                                     {
                                             top = -1;
                                             i = 1;
                                             break;
                                     }
                                     else
                                     {
                                         if(i == temp)
                                                 i++;
                                         else 
                                         {
                                             while(i != temp && i <= n)
                                             { 
                                              b[++top] = i;
                                              i++;
                                              }
                                              if(i == temp)i++; 
                                         }
                                         for(j = 1;j < n;j++)
                                         {
                                                 fscanf(fp,"%d",&temp);
                                                 if(!flag)continue;
                                                 if(i <= n && i == temp)
                                                 {
                                                        
                                                         i++;
                                                 }
                                                 else if(b[top] == temp && top >= 0)
                                                 {
                                                      
                                                      top --;
                                                 }
                                                 else if(i <= n)
                                                 {
                                                      while(i != temp && i <= n)
                                                      {
                                                                 b[++top] = i;
                                                                 i++;
                                                      }
                                                      if(i == temp)i++;   
                                                 }  
                                                 else if(i > n)
                                                 {
                                                     if(temp != b[top])flag = 0;
                                                 }                                 
                                         }
                                         if(flag)printf("Yes\n");
                                         else printf("No\n");
                                         flag = 1;
                                         i = 1;
                                         top = -1;
                                     }
                         }
    }
    getchar();
    return 0;
}
