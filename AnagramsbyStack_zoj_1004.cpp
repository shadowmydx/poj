#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
// ptr ָ��a��һ��Ԫ��
// ��ǰƥ�䵽��b�ַ���λ��
int length;
stack<char> mystk;
string a,b;

void dfs(int step,vector<char> &res,int ptr,int bptr) // ��step���ǣ���ѹջ���ǵ���
{
/*
    for (int i = 0;i < step;i++)
        cout << res[i] << " ";
    cout << endl;
    cout << step << " " << "bptr = " << bptr << endl;*/
    if (bptr >= length)
    {
        for (int i = 0;i < res.size();i++)
            cout << res[i] << " ";
        cout << endl;
        return;
    }
    if (ptr >= length)
    {
        if (mystk.top() != b[bptr])
            return;
        else
        {
            char tmp = mystk.top();
            mystk.pop();
            res[step] = 'o';

            dfs(step + 1,res,ptr,bptr + 1);

            mystk.push(tmp);
            return;
        }
    }
    if (step >= length * 2)
        return;
    if (mystk.empty())
    {
        mystk.push(a[ptr]);
        res[step] = 'i';
        dfs(step + 1,res,ptr + 1,bptr);

        mystk.pop();
    }
    else if (mystk.top() != b[bptr])
    {
        mystk.push(a[ptr]);
        res[step] = 'i';
        dfs(step + 1,res,ptr + 1,bptr);

        mystk.pop();
    }
    else if (mystk.top() == b[bptr])
    {

        mystk.push(a[ptr]);
        res[step] = 'i';
        dfs(step + 1,res,ptr + 1,bptr);
        mystk.pop();
        char he = mystk.top();
        mystk.pop();

        res[step] = 'o';

        dfs(step + 1,res,ptr,bptr + 1);

        mystk.push(he);
    }
}

int main(void)
{
    while (cin >> a >> b)
    {
        cout << "[" << endl;;
        length = a.length();
        vector<char> res(2 * length);
        if (length == b.length())
            dfs(0,res,0,0);
        cout << "]" << endl;
        while (!mystk.empty())
            mystk.pop();
    }
    return 0;
}
