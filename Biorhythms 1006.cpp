#include <iostream>
using namespace std;
int main(void)
{
    int p,e,i,d;
    int result;
    int start = 1;
    while(1)
    {
            cin >> p >> e >> i >> d;
            if(-1 == p && -1 == e && -1 == i && -1 == d)break;
            for(int j = 1;j < 22000;j ++)
            {
                    if((j - p) % 23 == 0 && (j - e) % 28 == 0 && (j - i) % 33 == 0)
                    {
                          if(j > d){result = j - d;break;}
                    }
            }
            if(result == 21253)result = 1;
            cout << "Case " << start << ": " << "the next triple peak occurs in " << result << " days." << endl;
            start ++;
    }
    return 0;
}
