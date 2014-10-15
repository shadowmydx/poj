#include <iostream>
using namespace std;
bool is_prime(int num)
{
     if(num == 2)return true;
     if(num == 1)return false;
     for(int i = 2;i * i <= num;i++)
     {
             if(num % i == 0)return false;
     }
     return true;
}
int main(void)
{
    int a,d,n;
    int result;
    int i;
    while(1)
    {
            cin >> a;
            cin >> d;
            cin >> n;
            if(a == 0 && d == 0)break;
            for(i = a;n > 0;i += d)
            {
                    if(is_prime(i))n--;
                    result = i;
            }
            cout << result << endl;
    }
    return 0;
}
