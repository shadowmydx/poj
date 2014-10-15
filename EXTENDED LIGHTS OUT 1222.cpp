#include <iostream>
using namespace std;
int sol[5][6];
int END = 0;
void gerne(int *a)
{
     int i = 0;
     if(a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1 && a[4] == 1 && a[5] == 1)return;
     else
     {
         a[0] ++;
         while(a[i] == 2)
         {
                    a[i] = 0;
                    a[i+1]++;
                    i++;
         }
     }
}
void turn(int i,int j,int que[][6])
{
     que[i][j] = !que[i][j];
     if(i-1 >= 0)que[i-1][j] = !que[i-1][j];
     if(i+1 < 5)que[i+1][j] = !que[i+1][j];
     if(j-1 >= 0)que[i][j-1] = !que[i][j-1];
     if(j+1 < 6)que[i][j+1] = !que[i][j+1];
}
int is_a_sol(int que[][6])
{
    int flag = 1;
    for(int i = 0;i < 5;i++)
            for(int j = 0;j < 6;j++)
                    if(que[i][j] == 1){flag = 0;break;}
    return flag;
}
void fun(int num,int start,int que[][6])
{
     if(num > 5)return;
     int flag = 0;
     int temp[5][6];
     int a[6] = {0};
     int count_1 = 64;
     if(num >= 2)
     for(int i = 0;i < 6;i++)
     {
             if(que[num-2][i] == 1){flag = 1;break;}
     }
     if(flag)return;
     for(int i = 0;i < 5;i++)
     for(int j = 0;j < 6;j++)
     temp[i][j] = que[i][j];
     if(is_a_sol(temp))
     {
                            cout << "PUZZLE #" << start << endl;
                            for(int i = 0;i < 5;i++)
                            {
                                    for(int j = 0;j < 6;j++)
                                            cout << sol[i][j] << " ";
                                    cout << endl;
                            }
                            END = 1;
                            return;
     }
     else if(num < 5)
     {
         while(count_1)
         {
                       for(int i = 0;i < 6;i++)
                       {
                               sol[num][i] = a[i];
                               if(a[i] == 1)
                               turn(num,i,temp);
                       }
                       fun(num+1,start,temp);
                       if(END)break;
                       gerne(a);
                       for(int i = 0;i < 5;i++)
                               for(int j = 0;j < 6;j++)
                                       temp[i][j] = que[i][j];
                       count_1 --;
         }
     }

}
int main(void)
{
    int n;
    int que[5][6];
    int start = 1;
    cin >> n;
    while(n)
    {
            for(int i = 0;i < 5;i++)
                    for(int j = 0;j < 6;j++)
                    {
                            cin >> que[i][j];
                            sol[i][j] = 0;                          
                    }
            END = 0;
            fun(0,start,que);
            start++;
            n --;
    }
    return 0;
}
