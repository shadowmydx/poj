#include <iostream>
using namespace std;
int c[1503] = {0};
int min(int a,int b,int c)
{
    if(a <= b)
    {
         if(a <= c)return a;
    }
    if(c <= b)
    {
         if(c <= a)return c;
    }
    if(b <= a)
    {
         if(b <= c)return b;
    }
}
void cal()
{
     int p = 0;
     int M2,M3,M5;
     int next_2,next_3,next_5;
     c[p] = 1;
     while(p < 1500)
     {
             int flag2 = 1;
             int flag3 = 1;
             int flag5 = 1;
             for(int i = 0;i <= p;i++)
             {
                     if(flag2)M2 = c[i] * 2;
                     if(M2 > c[p])
                     {
                           flag2 = 0;
                           next_2 = M2;
                     }
                     if(flag3)M3 = c[i] * 3;
                     if(M3 > c[p])
                     {
                           flag3 = 0;
                           next_3 = M3;
                     }
                     if(flag5)M5 = c[i] * 5; 
                     if(M5 > c[p])
                     {
                           flag5 = 0;
                           next_5 = M5;
                     }
             }
             c[++p] = min(next_2,next_3,next_5);
     }
}

int main(void)
{
    int n;
    cal();
    while(cin >> n)
    {
              if(0 == n)break;
              cout << c[n-1] << endl;
    }
    return 0;
}
