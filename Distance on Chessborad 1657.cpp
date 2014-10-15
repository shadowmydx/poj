#include <iostream>
using namespace std;
int abs1(int num)
{
    if(num < 0)return -1 * num;
    else return num;
}
int main(void)
{
    int t;
    int min;
    char p1,p2;
    int p3,p4;
    int king,queen,rock,bishop;
    cin >> t;
    while(t)
    {
            cin >> p1;
            cin >> p3;
            cin >> p2;
            cin >> p4;
            if(p1 == p2 && p3 == p4)
            {
                  king = 0;
                  queen = 0;
                  bishop = 0;
                  rock = 0;
            }
            else if(p1 == p2 || p3 == p4)
            {
                  rock = 1;
                  queen = 1;
                  king = abs1(p1 - p2 > 0) ? abs1(p1 - p2) : abs1(p3 - p4);
                  if(((p1 + p3) % 2 == 0 && (p2 + p4) % 2 == 0) || (((p1 + p3) % 2 != 0) && ((p2 + p4) % 2 != 0)))
                  {
                          bishop = 2;
                  }
                  else bishop = -1;
            }
            else if(abs1(p1 - p2) == abs1(p3 - p4)) 
            {
                 rock = 2;
                 queen = 1;
                 king = abs1(p2 - p1);
                 bishop = 1;
            }
            else
            {
                rock = 2;
                queen = 2;
                if(((p1 + p3) % 2 == 0 && (p2 + p4) % 2 == 0) || (((p1 + p3) % 2 != 0) && ((p2 + p4) % 2 != 0)))
                {
                          bishop = 2;
                }
                else bishop = -1;
                king = abs1(p2 - p1) <= abs1(p3 - p4) ? abs1(p3 - p4) : abs1(p2 - p1); 
            }
            cout << king << " " << queen << " " << rock << " ";
            if(bishop != -1)cout << bishop << endl;
            else cout << "Inf" << endl;
            t --;
    }
    return 0;
}
