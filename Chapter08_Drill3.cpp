#include "std_lib_facilities.h"
void swap_v(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a,int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
/*
void swap_cr(const int& a,const int& b){
    int temp;
    temp = a;
    a = b; //a is a constant that cannot be modified
    b = temp;
}
*/

int main(){
    int x = 7;
    int y =9;
    cout<<"x="<<x<<" y=" <<y<<endl;
    swap_v(x,y);//x and y is local od swap_v
    cout<<x<<y<<endl; //so they are not change
    swap_r(x, y);
    cout<<x<<y<<endl;

    swap_v(7,9);
    cout<<x<<y<<endl;
    //swap_r(7,9);-->reference argument r needs a variable to refer to
    //swap_cr(7,9);-->this is ok, if we make some change for swap_cr
                    //since cr is const we can pass a literal
    //--
    const int cx = 7;
    const int cy = 9;
    cout<<"cx="<<cx<<" cy=" <<cy<<endl;
    swap_v(cx,cy);
    cout<<cx<<cy<<endl;//cx and cy is local od swap_v
    //swap_r(cx,cy); error: we can not change the constant value
    
    swap_v(7.7,9.9);
    cout<<cx<<cy<<endl;//only output the integer,because (int a,int b)
    //swap_r(7.7,9.9); -->reference argument r needs a variable to refer to
    //swap_cr(7.7,9.7);-->this is ok, if we make some change for swap_cr
                        //since cr is const we can pass a literal
    
    //----------
    double dx = 7.7;
    double dy = 9.9;
    cout<<"dx="<<cx<<" dy=" <<cy<<endl;
    swap_v(dx,dy);//dx and dy is local od swap_v
    cout<<dx<<dy<<endl;
    //swap_r(dx, dy);--dx and dy are double, and swap_r is int
    
    return 0;
}
