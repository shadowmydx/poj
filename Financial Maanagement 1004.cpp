#include <iostream>
using namespace std;
int main(void)
{
    double num,sum = 0.0,avg = 0.0;
    for(int i = 0;i < 12;i++)
    {
            cin >> num;
            sum += num;
    }
    avg = sum / 12;
    printf("$%.2f\n",avg);
    return 0;
}
