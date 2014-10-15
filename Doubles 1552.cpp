#include <iostream>
using namespace std;
int ans[15] = {0};
int num[101] = {0};
int main(void)
{
    int result = 0;
    int i = 0;
    int temp;
    while(cin >> temp)
    {
              if(-1 == temp)break;
              if(0 == temp)
              {
                   cout << result << endl;
                   result = 0;
                   for(int j = 0;j < 15;j++)
                   {
                           num[ans[j]] = 0;
                           ans[j] = 0;
                   }
                   i = 0;
                   continue;
              }
              num[temp] = 1;
              ans[i] = temp;
              if(temp / 2 > 0 && temp % 2 == 0 && num[temp / 2] != 0)
                          result ++;
              if(temp * 2 < 100 && num[temp * 2] != 0)
                      result ++;
              i++;
    }
    return 0;
}
