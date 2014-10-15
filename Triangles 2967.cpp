#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int num[1000009] = {0};
int readInteger()  
{  
    int res = 0;  
    char ch = getchar();  
    while(ch >= '0' && ch <= '9')  
    {  
        res = res * 10 + ch - '0';  
        ch = getchar();  
    }  
    return res;  
}  

int main(void)
{
    int N;
    int flag = 1;
    N = readInteger(); 
    for(int i = 0;i < N;i++)
            num[i] = readInteger();
    sort(num,num + N);
    if(N <= 3 || num[0]  > num[N-1] - num[1])
              flag = 1;
    else
    {
        for(int i = 2;i < N;i++)
        {
                if(num[i-2] > num[i] - num[i-1])
                {
                          flag = 0;
                          break;
                }
        }
    }
    if(flag)
    {
            printf( "The set is rejected.\n");
    }
    else printf("The set is accepted.\n");
    return 0;
}
