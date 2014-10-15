#include <stdio.h>
struct code
{
       int x;
       int y;
       int z;
       int o;
};
code B[101];
int temp[1000001] = {0};
int main(void)
{
    int i,j,k;
    int N;
    int temp1,result,top = -1;
    code temp2;
    for(i = 1;i <= 100;i++)
    {
          temp[i * i * i] = i;
          B[i].x = 0;
          B[i].y = 0;
          B[i].z = 0;
          B[i].o = 0;
    }
    scanf("%d",&N);
    temp1 = N * N * N;
    for(i = 2;i <= N - 2;i++)
    {
          for(j = i + 1;j <= N - 1;j++)
          {
                if(i * i * i + j * j * j >= temp1)break;
                for(k = j + 1;k <= N;k++)
                {
                      result = i * i * i + j * j * j + k * k * k;
                      if(result > temp1)break;
                      if(temp[result] != 0)
                      {
                                     B[++top].x = temp[result];
                                     B[top].y = i;
                                     B[top].z = j;
                                     B[top].o = k;      
                      }     
                }
          }
    } 
    for(i = 0;i <= top;i++)
    {
          for(j = 0;j < top;j++)
          {
                if(B[j].x > B[j+1].x)
                {
                          temp2 = B[j];
                          B[j] = B[j+1];
                          B[j+1] = temp2;
                }     
          }
    }
    for(i = 0;i <= top;i++)
    {
          printf("Cube = %d, Triple = (%d,%d,%d)\n",B[i].x,B[i].y,B[i].z,B[i].o);
    }    
    return 0;
}
