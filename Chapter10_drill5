#include "std_lib_facilities.h"
struct Point
{
    int x; int y;
    Point() :x(), y(){}
    Point(int xx, int yy) :x(xx),y(yy){}
};

ostream& operator<<(ostream& os, const Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

istream& operator>>(istream& is, Point& p)
{
    int x, y;
    char ch1, ch2, ch3;
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (!is) return is;
    if (ch1!='(' || ch2!=',' || ch3!=')') {
        is.clear(ios_base::failbit);
        return is;
    }
    p = Point(x,y);
    return is;
}

bool operator !=(Point&p1, Point&p2)
{
    p1.x != p2.x || p1.y != p2.y;
    return false;
    
}


void print_point(const vector<Point>& p)
{
    for (int i = 0; i<p.size(); ++i)
            cout << p[i] << endl;
}

void input_to_file(const vector<Point>& p, const string& oname)
{
    ofstream ost{oname};
    if(!ost)error("can't input to file",oname);
    for(int i =0; i<p.size();i++)
    ost<<p[i]<<endl;
    ost.close();
}
//read file
void output_from_file(vector<Point>& point, const string& iname)
{
    ifstream ist{iname};
    if(!ist)error("can't output from file",iname);
    Point p;
    while (ist>>p) {
        point.push_back(p);
    }
}



void compare(vector<Point>& p1, vector<Point>& p2)
{
    if(p1.size()!=p2.size())
        error("Something's wrong!");
    for (int i = 0; i<p1.size(); ++i){
        if(p1[i]!=p2[i])
            error("Something's wrong!");
    
    }
}


int main()try{
    //enter vector
    vector<Point> original_points;
    for(int i=0; i<2; i++){
        Point p;
        cin>>p;
        original_points.push_back(p);
    }
    print_point(original_points);
    input_to_file(original_points, "mydate");
    vector<Point> processed_point;
    output_from_file(processed_point, "mydate");
    print_point(processed_point);
    compare(original_points, processed_point);
    
    return 0;
}catch (exception& e){
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...){
    cerr << "Something wrong happened\n";
    return 2;
}
