#include <iostream>
using namespace std;
int main(void)
{
    int n = 1;
    double num;
    double q;
    double sum = 0.0;
    while(cin >> num)
    {
           if(0 == num)break;
           for(n = 2;sum < num;n++)
           {
                 q = 1 / (double)n;
                 sum += q;
           }
           cout << n - 2 << " card(s)" << endl;
           sum = 0.0;
    }
    return 0;
}
