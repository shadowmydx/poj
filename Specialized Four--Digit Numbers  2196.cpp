#include <iostream>
using namespace std;
int main(void)
{
    int digit;
    int num1;
    int num2;
    int num3;
    int sum1;
    int sum2;
    int sum3;
    int num = 2993;
    cout << 2992;
    while(num <= 9999)
    {
              sum1 = 0;
              sum2 = 0;
              sum3 = 0;
              num1 = num;
              while(num1 > 0)
              {
                         digit = num1 % 10;
                         sum1 += digit;
                         num1 /= 10;
              }
              num2 = num;
              while(num2 > 0)
              {
                         digit = num2 % 12;
                         sum2 += digit;
                         num2 /= 12;
              }
              if(sum1 == sum2)
              {
                      num3 = num;
                      while(num3 > 0)
                      {
                                 digit = num3 % 16;
                                 sum3 += digit;
                                 num3 /= 16;
                      }
                      if(sum3 == sum2)
                      {
                              cout << endl;
                              cout << num;
                      }
              }
              num ++;
    }
    return 0;
}
