#include <stdio.h>
#include <string.h>
/*方法：
初始位向量全部为1 
1、even排除
2、up/down-》同之前的初始位向量做交
3、输出-》初始位向量仅有一位为1*/

int main(void)
{
    char f[3][6];
    char a[6][12];
    char b[2][10] = {"light","heavy"};
    int pai[12];
    int temp[12] = {0};
    int flag = 0,flag2;
    int result1,result2;
    int n,i,j;
    scanf("%d",&n);
    while(n)
    {
           for(i = 0;i < 5;i+=2)
           {
                 scanf("%s%s%s",a[i],a[i+1],f[i/2]);
           } 
           for(i = 0;i < 12;i++)
           {
                 pai[i] = 1;
                 temp[i] = 0;
           }
           result1 = 0;
           result2 = 0;
           flag = 0;
           flag2 = 0;
                   for(i = 0;i < 3;i++)
                   {
                         for(j = 0;j < 12;j++)
                               temp[j] = 0;
                         if(strcmp(f[i],"even") == 0)
                         {
                                   for(j = 0;a[i*2][j] != '\0';j++)
                                         pai[a[i*2][j]-65] = 0;
                                   for(j = 0;a[i*2+1][j] != '\0';j++)
                                         pai[a[i*2+1][j]-65] = 0;            
                         }
                         else if(strcmp(f[i],"up") == 0)
                         {
                                   for(j = 0;a[i*2][j] != '\0';j++)
                                         pai[a[i*2][j]-65] = 0;     
                                   for(j = 0;a[i*2+1][j] != '\0';j++)
                                         temp[a[i*2+1][j]-65] = 1;
                                   for(j = 0;j < 12;j++)
                                   {
                                         if(temp[j] == 1 && pai[j] == 1)pai[j] = 1;
                                         else pai[j] = 0;
                                   }
                                                                  
                         }
                         else if(strcmp(f[i],"down") == 0)
                         {
                                   for(j = 0;a[i*2+1][j] != '\0';j++)
                                         pai[a[i*2+1][j]-65] = 0; 
                                   for(j = 0;a[i*2][j] != '\0';j++)  
                                         temp[a[i*2][j]-65] = 1;   
                                   for(j = 0;j < 12;j++)
                                   {
                                         if(temp[j] == 1 && pai[j] == 1)pai[j] = 1;
                                         else pai[j] = 0;
                                   }                                                            
                         }
                   }
                   for(i = 0;i < 12;i++)
                   {
                             if(pai[i] == 1)
                             {
                                   result1 ++;
                                   result2 = i;
                             }
                   }
                   if(result1 > 1 || result1 == 0)
                   {
                              flag = 1;
                              flag2 = 0;
                              result1 = 0;
                              result2 = 0;
                              for(i = 0;i < 12;i++)
                              {
                                    pai[i] = 1;
                                    temp[i] = 0;
                              }
                   }
           if(flag == 1) 
           {
                   for(j = 0;j < 12;j++)
                         temp[j] = 0;
                   for(i = 0;i < 3;i++)
                   {
                         if(strcmp(f[i],"even") == 0)
                         {
                                   for(j = 0;a[i*2][j] != '\0';j++)
                                         pai[a[i*2][j]-65] = 0;
                                   for(j = 0;a[i*2+1][j] != '\0';j++)
                                         pai[a[i*2+1][j]-65] = 0;            
                         }
                         else if(strcmp(f[i],"up") == 0)
                         {
                                   for(j = 0;a[i*2+1][j] != '\0';j++)
                                         pai[a[i*2+1][j]-65] = 0; 
                                   for(j = 0;a[i*2][j] != '\0';j++)
                                         temp[a[i*2][j]-65] = 1; 
                                   for(j = 0;j < 12;j++)
                                   {
                                         if(temp[j] == 1 && pai[j] == 1)pai[j] = 1;
                                         else pai[j] = 0;
                                   }                                                                        
                         }
                         else if(strcmp(f[i],"down") == 0)
                         {
                                   for(j = 0;a[i*2][j] != '\0';j++)
                                         pai[a[i*2][j]-65] = 0; 
                                   for(j = 0;a[i*2+1][j] != '\0';j++)  
                                         temp[a[i*2+1][j]-65] = 1;  
                                   for(j = 0;j < 12;j++)
                                   {
                                         if(temp[j] == 1 && pai[j] == 1)pai[j] = 1;
                                         else pai[j] = 0;
                                   }                                                                         
                         }
                   }
                       for(i = 0;i < 12;i++)
                       {
                             if(pai[i] == 1)
                             {
                                   result1 ++;
                                   result2 = i;
                             }
                       }           
           }
           printf("%c is the counterfeit coin and it is %s.\n",result2 + 65,b[flag]);
            n --;
    }
    return 0;
}
