#include <iostream>
using namespace std;
long long fun(int x)
{
     int y = 1;
     if(x == 0)return 1;
     else
     {
         for(int i = 0;i < x;i++)
                 y *= 10;
     }
     return y - 1;
}
int main(void)
{
    long long n = 9;
    long long i;
    long long sum = 0;
    int result;
    int t;
    int j = 1;
    for(i = 1;sum < 2147483647;i++)
    {
          sum += fun(i-1) * ((n * (i + n * i))/2); 
          n *= 10;    
    }
    cout << i << endl;
    /*cin >> t;
    while(t)
    {
            result = 0;
            cin >> i;
            
            t --;
    }*/
    system("pause");
    return 0;
}
