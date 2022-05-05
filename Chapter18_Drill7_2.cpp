#include "std_lib_facilities.h"

vector<int> gv = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(const vector<int>& a)
{
    vector<int> lv(a.size());
    lv = gv;
    for (int i = 0; i<10; ++i)
        cout<<lv[i]<<" ";
    cout<<endl;
    
    vector<int> lv2(a.size());
    lv2 = a;
    for (int i = 0; i<10; ++i)
        cout<<lv2[i]<<" ";
    cout<<endl;
}
int main()
{
    f(gv);
    vector<int> vv;
    vv.push_back(1);
    for (int i = 1; i<10; ++i)
    {
        vv.push_back(vv[i-1]*(i+1));
    }
    f(vv);
}
