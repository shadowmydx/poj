#include <iostream>
using namespace std;
int main(void)
{
    int a[600] = {0};
    int n,d;
    int num;
    int flag;
    while(1)
    {
            cin >> n;
            cin >> d;
            flag = 0;
            if(0 == n || 0 == d)break;
            for(int i = 0;i < n;i++)
                    a[i] = 1;
            while(d)
            {
                    for(int i = 0;i < n;i++)
                    {
                            cin >> num;
                            if(0 == num)a[i] = 0;
                    }
                    d --;
            }
            for(int i = 0;i < n;i++)
                    if(a[i] == 1)flag = 1;
            if(flag)cout << "yes" << endl;
            else cout << "no" << endl;
    }
    return 0;
}
