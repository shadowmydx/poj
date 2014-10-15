//注意！！当min1被替换时，min2要被min1替换！要保证a[i] < a[i+1] 
#include <iostream>
#include <stdio.h>
using namespace std;
int a[30000] = {0};
void swap(int *a,int *b)
{
     int temp;
     temp = *a;
     *a = *b;
     *b = temp;
}
int main(void)
{
    int N;
    long long result = 0;
    int min1,min2;
    cin >> N;
    for(int i = 0;i < N;i++)
            cin >> a[i];
    for(int i = 0;i < N - 1;i++)
    {

            min1 = a[i];
            min2 = a[i+1];
            if(min1 > min2)
            {
                    min1 = a[i+1];
                    min2 = a[i];
                    swap(&a[i],&a[i+1]);
            }
            for(int j = i + 2;j < N;j++)
            {
                    if(a[j] < min1){swap(&a[i],&a[i+1]);swap(&a[j],&a[i]);min1 = a[i];min2 = a[i+1];}
                    else if(a[j] < min2){swap(&a[j],&a[i+1]);min2 = a[i+1];}
            }
            a[i+1] += a[i];
            result += a[i+1];    
    }
    printf("%lld\n",result);
    system("pause");
    return 0;
}
