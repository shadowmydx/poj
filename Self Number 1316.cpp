#include <iostream>
using namespace std;
int num[100001] = {0};
int main(void)
{
    int n;
    int i = 10;
    int temp = 0;
    int wei;
    for(int i = 1;i < 10000;i++)
    {
            n = i;
            while(n != 0)
            {
                    wei = n % 10;
                    temp += wei;
                    n /= 10;
            }
            if(temp + i < 10000)
                    num[temp + i] = 1;
            temp = 0;
    }
    for(int i = 1;i < 10000;i++)
            if(num[i] == 0)cout << i << endl;
    return 0;
}
