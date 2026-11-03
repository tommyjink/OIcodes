#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
int gcd(int x,int y)
{
    if(y==0)return x;
    return gcd(y,x%y);
}
int lcm(int x,int y)
{
    return x/gcd(x,y)*y;
}
struct node
{
    int x,y;
    void cal()
    {
        if(x==0)x=0,y=1;
        int d=gcd(x,y);
        x/=d;
        y/=d;
    }
}ans;
bool operator <(node a,node b)
{
    a.cal(),b.cal();
    int d=lcm(a.y,b.y);
    return a.x*d/a.y<b.x*d/b.y;
}
bool operator <=(node a,node b)
{
    a.cal(),b.cal();
    int d=lcm(a.y,b.y);
    return a.x*d/a.y<=b.x*d/b.y;
}
void print(node x)
{
    x.cal();
    cout<<x.x<<"/"<<x.y<<" ";
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=b[i-1]+a[i];
    sort(a+1,a+1+n);
    int r=n;
    for(int i=n;i>1;i--)
    {   
        
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}