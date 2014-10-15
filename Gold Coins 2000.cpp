#include <iostream>
using namespace std;
int main(void)
{
    long long N;
    long long result;
    long long temp;
    int i;
    while(1)
    {
            result = 0;
            i = 1;
            cin >> N;
            if(N == 0)break;
            for(i = 1;(temp = i * (i + 1)) <= 2 * N;i++);
            for(int j = 1;j < i;j++)
                    result += j * j;
            if(2 * N != temp)
                 result += (N - ((i-1) * i ) / 2) * i;
            cout << N << " " << result << endl;                 
    }
    return 0;
}
