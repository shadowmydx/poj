#include <iostream>
#include <string>
using namespace std;
int dist[40000];//i到根节点的距离
int node[40000];
int total[40000];//i为根节点时，子树的节点数
/*
带权并查集
维护每个结点到根节点的距离
*/
void init()
{
    for(int i = 0;i < 40000;i++)
    {
        node[i] = -1;
        total[i] = 1;
    }
}


int findRoot(int num)
{
    if(node[num] == -1)
        return num;
    else
    {
       int tmp = node[num];
       node[num] = findRoot(node[num]);
       dist[num] += dist[tmp];
    }
    return node[num];
}

void unionRoot(int p1,int p2)
{
    node[p2] = p1;
    dist[p2] = total[p1];
    total[p1] += total[p2];
}

int main(void)
{
    init();
    int p,num1,num2;
    string m;
    cin >> p;
    while(p--)
    {
        cin >> m;
        if(m == "M")
        {
            cin >> num1 >> num2;
            int p1 = findRoot(num1);
            int p2 = findRoot(num2);
            unionRoot(p1,p2);
        }
        else if(m == "C")
        {
            cin >> num1;
            int p1 = findRoot(num1);
            cout << total[p1] - dist[num1] - 1 << endl;
        }
    }
    return 0;
}
