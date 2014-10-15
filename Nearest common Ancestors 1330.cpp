#include <stdio.h>
int tree[10001] = {0};
int flag[10001] = {0};
int main(void)
{
    int test;
    int N;
    int tmp1,tmp2;
    int i;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&N);
        for(i = 0;i < N - 1;i++)
        {
            scanf("%d%d",&tmp1,&tmp2);
            tree[tmp2] = tmp1;
        }
        scanf("%d%d",&tmp1,&tmp2);
        flag[tmp1] = 1;
        while(tree[tmp1] != 0)
        {
            flag[tree[tmp1]] = 1;
            tmp1 = tree[tmp1];
        }
        while(flag[tmp2] != 1)
        {
            tmp2 =  tree[tmp2];
        }
        printf("%d\n",tmp2);
        for(i = 0;i < N;i++)
        {
            tree[i] = 0;
            flag[i] = 0;
        }
    }
    return 0;
}
