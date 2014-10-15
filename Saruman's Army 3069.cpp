#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    int N,R;
    int temp_r;
    int temp;
    int ans;
    int a[2000] = {0};
    while(cin >> R >> N)
    {
              if(N == -1 || R == -1)break;
              for(int i = 0;i < N;i++)
                      cin >> a[i];
              sort(a,a + N);
              ans = 0;
              for(int i = 0;i < N;)
              {
                      temp_r = R;
                      while(a[i] + temp_r >= a[i+1] && i + 1 < N)
                      {
                                 temp_r -= a[i+1] - a[i];
                                 i ++;
                      }
                      ans ++;
                      temp_r = R;
                      temp = a[i];
                      i++;
                      while(a[i] <= temp + temp_r && i < N)
                                 i++;
              }
              cout << ans << endl;
    }
    
    return 0;
}
