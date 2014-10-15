#include <iostream>
using namespace std;
struct qujian
{
       int x;
       int y;
};
int main(void)
{
    qujian ans[5002];
    int top = -1;
    int L,M;
    int start,end;
    int result;
    int flag;
    while(1)
    {
            cin >> L;
            cin >> M;
            if(0 == L)break;
            result = L + 1;
            top = -1;
            while(M)
            {
                    cin >> start;
                    cin >> end;
                    flag = 0;
                    for(int i = 0;i <= top && top >= 0;i++)
                    {
                            if(start == ans[i].x && end == ans[i].y)
                            {
                                     flag = 1;
                                     break;
                            }
                            else if(start < ans[i].x && end > ans[i].y)
                            {
                                     result -= ans[i].x - start;
                                     result -= end - ans[i].y;
                                     ans[i].x = start;
                                     ans[i].y = end;
                                     flag = 1;
                            }
                            else if(start < ans[i].x && end >= ans[i].x)
                            {
                                 result -= ans[i].x - start;
                                 ans[i].x = start;
                                 flag = 1;
                            }
                            else if(end > ans[i].y && start <= ans[i].y)
                            {
                                 result -= end - ans[i].y;
                                 ans[i].y = end;
                                 flag = 1;
                            }
                    }
                    if(!flag)
                    {
                             ans[++top].x = start;
                             ans[top].y = end;
                             result -= end - start + 1;
                    }
                    M --;
            }
            cout << result << endl;
    }
    return 0;
}
