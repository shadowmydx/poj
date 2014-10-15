#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
    int n;
    int result;
    int i = 1;
    double x,y;
    double cir;
    cin >> n;
    while(n)
    {
            cin >> x;
            cin >> y;
            cir = 0.5 * (M_PI * (x * x + y * y));
            result = ceil(cir / 50);
            cout << "Property " << i << ": This property will begin eroding in year " << result << "." << endl;
            n--;
            i++;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}
