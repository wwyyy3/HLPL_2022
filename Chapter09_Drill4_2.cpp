
#include "std_lib_facilities.h"
struct Date{
    int year, month, day;
    Date(int y, int m, int d);
    void add_day(int n);
};

Date::Date(int y, int m, int d){
    // check that (y,m,d) is a valid date
    // if it is, use it to initialize dd
    if( y > 0 )
        year = y;
    else error("Wrong year");
    
    if (m >0 && m < 13 )
        month = m;
    else error("Wrong month");
    
    if (m ==1|| m==3||m==5||m==7||m==8||m==10||m==12){
        if (d > 0 && d < 32)
            day = d;
    else if(m ==2|| m==4||m==6||m==9||m==11)
        if (d > 0 && d < 31)
            day =d;
    else error("Wrong day");
    }
}

void Date::add_day(int n)
{
    // increase dd by n days
    day += n;
    if (day > 31)
    {
        month++;
        day -=31;
        if(month > 12)
        {
            year++;
            month-=12;
        }
    }
}
void f()
{
    Date today{2022, 5, 2};
    cout<<today.year<<"_"<<today.month<<"_"<<today.day<<endl;
    today.add_day(1);
    Date tomorrow = today;
    cout<<tomorrow.year<<"_"<<tomorrow.month<<"_"<<tomorrow.day<<endl;
}


int main() {
    f();
    keep_window_open();
    return 0;
}
