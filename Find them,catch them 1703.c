#include <stdio.h>
typedef struct man
{
  int rev;
  int parent;
}man;
man set[100008];
int set_find(int p)
{
    if(p < 0)return -1;
    if(set[p].parent < 0)return p;
    return set[p].parent = set_find(set[p].parent);
}
void join(int p,int q)
{
    p = set_find(p);
    q = set_find(q);
    if(p != q)set[p].parent = q;
}
void deal(int p,int q)
{
    int tmp_rev1;
    int tmp_rev2;
    if(set[q].rev == -1)set[q].rev = p;
    if(set[p].rev == -1)set[p].rev = q;
    tmp_rev1 = set_find(set[p].rev);
    tmp_rev2 = set_find(set[q].rev);
    p = set_find(p);
    q = set_find(q);
    if(q != tmp_rev1)join(q,tmp_rev1);
    if(p != tmp_rev2)join(p,tmp_rev2);
}
void searchSet(int p,int q)
{
    p = set_find(p);
    q = set_find(q);
    if(p == q)
    {
        printf("In the same gang.\n");
    }
    else if(p == set_find(set[q].rev) || q == set_find(set[p].rev))
    {
        printf("In different gangs.\n");
    }
    else printf("Not sure yet.\n");
}
int main(void)
{
    int T;
    int N,M,i;
    int CASE;
    int num1,num2;
    char command;
    scanf("%d",&T);
    while(T --)
    {
        scanf("%d%d",&N,&M);
        if(N == 2)CASE = 1;
        else CASE = 0;
        for(i = 0;i <= N;i++)
        {
                set[i].parent = -1;
                set[i].rev = -1;
        }
        for(i = 0;i < M;i++)
        {
            getchar();
            command = getchar();
            scanf("%d%d",&num1,&num2);
            if(!CASE)
            {
                if(command == 'A')
                {
                    searchSet(num1,num2);
                }
                else if(command == 'D')
                {
                    deal(num1,num2);
                }
            }
            else printf("In different gangs.\n");
        }

    }
    return 0;
}
