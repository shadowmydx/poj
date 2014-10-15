#include <iostream>
using namespace std;
int prime[2000] = {0};
int main(void)
{
    prime[0] = 2;
    int count_1 = 0;
    int flag = 1;
    int num;
    int ans = 0;
    for(int i = 3;i <= 10000;i++)
    {
            for(int j = 2;j <= i / 2 + 1;j++)
            {
                    if(i % j == 0)
                    {
                         flag = 0;
                         break;
                    }
            }
            if(flag)prime[++count_1] = i;
            else flag = 1;
    }
    while(cin >> num)
    {
              if(0 == num)break;
              for(int i = 0;num >= prime[i];i++)
              {
                      int cnt = 0;
                      for(int j = i;j <= count_1 && cnt < num;j++)
                              cnt += prime[j];
                      if(cnt == num)
                             ans++;
              }
              cout << ans << endl;
              ans = 0;
    }
    return 0;
}
