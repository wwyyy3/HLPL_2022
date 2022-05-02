#include "std_lib_facilities.h"
struct Date{
    int y, m, d;
};

void init_day(Date& dd, int y, int m, int d){
    // check that (y,m,d) is a valid date
    // if it is, use it to initialize dd
    if( y > 0 )
        dd.y = y;
    else error("Wrong year");
    
    if (m >0 && m < 13 )
        dd.m = m;
    else error("Wrong month");
    
    if (m ==1|| m==3||m==5||m==7||m==8||m==10||m==12){
        if (d > 0 && d < 32)
            dd.d = d;
    else if(m ==2|| m==4||m==6||m==9||m==11)
        if (d > 0 && d < 31)
            dd.d =d;
    else error("Wrong day");
    }
}

void add_day(Date& dd, int n)
{
    // increase dd by n days
    dd.d += n;
    if (dd.d > 31)
    {
        dd.m++;
        dd.d -=31;
        if(dd.m > 12)
        {
            dd.y++;
            dd.m-=12;
        }
    }
}
void f()
{
    Date today;
    init_day(today, 2022, 5, 2);
    cout<<today.y<<"_"<<today.m<<"_"<<today.d<<endl;
    add_day(today, 2);
    cout<<today.y<<"_"<<today.m<<"_"<<today.d<<endl;
}


int main() {
    f();
    keep_window_open();
    return 0;
}
