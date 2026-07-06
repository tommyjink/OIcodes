#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4e6+10;
const double pi=acos(-1);
int n,m;
struct Complex{
    double x,y;
    Complex operator+(const Complex &b) const{
        return Complex{x+b.x,y+b.y};
    }
    Complex operator-(const Complex &b) const{
        return Complex{x-b.x,y-b.y};
    }
    Complex operator*(const Complex &b) const{
        return Complex{x*b.x-y*b.y,x*b.y+y*b.x};
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    
    return 0;
}