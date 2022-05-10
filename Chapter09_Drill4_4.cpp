#include "std_lib_facilities.h"
class Year{
    static const int min = 1800;
    static const int max = 2200;
public:
    class Invalid {};
    Year(int x):y{x}{if(x<min||max<=x)throw Invalid{};}
    int year(){return y;}
    void increment() {y++;}
private:
    int y;
};

Year operator++(Year& y)
{
    y.increment();
    return y;
}

ostream& operator<<(ostream& os, Year year)
{
    return os <<year.year();
}


enum class Month{
    jan=1, feb, mar, apr, may, jun, aug, sep, oct, nov, dec
};

Month operator++(Month& m)
{
    m = (m == Month::dec)? Month::jan : Month(int(m)+1);
    return m;
}

const vector<string> month_tbl =
{
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};


ostream& operator<<(ostream& os, Month m)
{
    return os <<month_tbl[int(m)];
}

class Date{
private:
    Year year;
    Month month;
    int day;
public:
    class Invalid{};
    Date(Year year, Month month, int day): year(year),month(month),day(day)
    {if (!is_valid()) throw Invalid{};}
    bool is_valid();
    void add_day(int n);
    int get_day(){return day;}
    Month get_month(){return month;}
    Year get_year(){return year;}
};


void Date::add_day(int n)
{
    // increase dd by n days
    day += n;
    if (day > 31)
    {
        ++month;
        day -=31;
        if(month == Month::jan)
        {
            ++year;
        }
    }
}

bool Date::is_valid(){
    if (day < 1 || day > 31) return false;
    return true;
}

void f()
{
    Date today{Year{2022}, Month::may, 2};
    cout<<today.get_year()<<"_"<<today.get_month()<<"_"<<today.get_day()<<endl;
    today.add_day(1);
    Date tomorrow = today;
    cout<<today.get_year()<<"_"<<today.get_month()<<"_"<<today.get_day()<<endl;

}
int main()
try
{
    f();
    keep_window_open();
    return 0;
}catch (exception& e){
    cout << "Error: " << e.what() << endl;
        return 1;
}catch (Date::Invalid) {
    cout << "Error: Invalid date\n";
    return 2;
} catch (Year::Invalid) {
    cout << "Error: Invalid year\n";
    return 3;
}
