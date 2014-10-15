#include <stdio.h>
#include <string.h>
int length;
int getIt(char *a,char *b,char *c,int a_start,int a_end,int b_start,int b_end,int c_start,int c_end)  
{
           if((a_start > a_end || b_start > b_end || c_start > c_end) || (a_end - a_start > length || b_end - b_start > length || c_end - c_start > length))
           return -1; 
                 
           char temp;
           int left_tree;
           int right_tree;
           int whole_tree = a_end - a_start + 1;
           int i = b_start;
           temp = a[a_start];
           c[c_end] = temp;
           if(a_start == a_end || b_start == b_end || c_start == c_end)
           return -1;
           while(temp != b[i] && i < b_end)
                      i++;
           left_tree = i - b_start;      
           right_tree = whole_tree - left_tree - 1;
           getIt(a,b,c,a_start + 1,a_start + 1 + left_tree - 1,i - left_tree,i - 1,c_start,c_start + left_tree - 1);
           getIt(a,b,c,a_start + 1 + left_tree,a_start + 1 + left_tree + right_tree - 1,i + 1,i + 1 + right_tree - 1,c_start + left_tree,c_start + left_tree + right_tree - 1);//¶ÔÓÒ×ÓÊ÷µİ¹é    
}

int main(void)
{
          int i;
          char fro[1000];
          char mid[1000];
          char bac[1000];
          while(scanf("%s%s",fro,mid) != EOF)
          {
                                      for(i = 0;i < 1000;i++)
                                            bac[i] = 0;
                                      length = strlen(fro);
                                      getIt(fro,mid,bac,0,length - 1,0,length - 1,0,length - 1);
                                      bac[length] = '\0';
                                      printf("%s\n",bac);          
          }        
          return 0;
}
