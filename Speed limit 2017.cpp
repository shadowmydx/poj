#include <iostream>
using namespace std;
int main(void)
{
    int n,s,t,temp,temp1;
    int result;
    while(1)
    {
            result = 0;
            temp = 0;
            cin >> n;
            if(-1 == n)break;
            while(n)
            {
                   cin >> s;
                   cin >> t;
                   temp1 = t;
                   t -= temp;
                   result += s * t;
                   temp = temp1;
                   n --; 
            }
            cout << result << " miles" << endl;
    }
    return 0;
}
