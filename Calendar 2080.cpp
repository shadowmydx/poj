#include <iostream>
using namespace std;
int year[8000] = {0};
int main(void)
{
    int days;
    int j;
    int start;
    int year1,month,day;
    int temp_xq;
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    char xq[10][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    for(int i = 0;i < 8000;i++)
    {
            if((i + 2000) % 4 == 0)
            {
                  if((i + 2000) % 100 == 0 && (i + 2000) % 400 != 0)
                        continue;
                  else
                      year[i] = 1;
            }
    }
    while(1)
    {
            cin >> days;
            if(-1 == days)break;
            j = 0;
            year1 = 0;
            month = 0;
            day = 0;
            temp_xq = 0;
            start = 366;
            if(days == 0)temp_xq = 6;
            else
            {
                temp_xq = (days - 1) % 7;
            }
            if(days >= start)
            {
                    while(days >= start)
                    {
                       if(year[j] == 0)days -= 365;
                       else days -= 366;
                       year1 ++; 
                       if(year[year1] == 1)start = 366;
                       else start = 365;
                       j++;       
                    }
            }
            if(year[year1] == 1)months[1] = 29;
            else months[1] = 28;
            j = 0;
            int temp_day = 0;
            while(temp_day < days)
            {
                           temp_day += months[j];
                           month++;
                           j++;
            }
            if(temp_day == days)
            {
                        month++;
                        day = 1;
            }
            else
            {
                j--;
                day = months[j] - (temp_day - days) + 1;
            }
            cout << year1 + 2000 << "-";
            if(month < 10)cout << 0 << month;
            else cout << month;
            cout << "-";
            if(day < 10)cout << 0 << day;
            else cout << day;
            cout << " " << xq[temp_xq] << endl;
    }
    return 0;
}
