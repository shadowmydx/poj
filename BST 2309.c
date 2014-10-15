#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    long long X;
    long long min;
    long long max;
    long long tmp = 1;
    long long root;
    long long total;
    long long gap;
    scanf("%d",&N);
    while(N--)
    {
        tmp = 1;
        scanf("%lld",&X);
        if(X % 2 != 0)
        {
            max = X;
            min = X;
        }
        else
        {
            while(tmp < X)tmp = tmp << 1;
            if(tmp == X){root = X;total = (root - 1) * 2 + 1;}
            else {root = tmp / 2;total = tmp - 1;}
            gap = root / 2;
            while(root != X)
            {
                if(root > X)
                    root -= gap;
                else if(root < X)
                    root += gap;
                gap /= 2;
                total = (total - 1) / 2;
            }
            total = (total - 1) / 2;
            min = root - total;
            max = root + total;
        }
        printf("%lld %lld\n",min,max);
    }
    return 0;
}
