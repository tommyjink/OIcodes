#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
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
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    int p=n+1,sum=0;
    node ans1={0,1},ans2={1,1};
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        while(p-1>i&&sum+a[p-1]<a[p-1]*(i+(n-p+2)))sum+=a[--p];
        if(p>i&&sum<a[p]*(i+(n-p+1)))
            ans1=max(ans1,{n-p+1,i+(n-p+1)});
    }
    print(ans1);
    p=0,sum=0;
    for(int i=n;i>=1;i--)
    {
        sum+=a[i];
        while(p+1<i&&sum+a[p+1]>=a[p+1]*((n-i+1)+p+1))sum+=a[++p];
        if(p<i&&sum>=a[p]*((n-i+1)+p))
            ans2=min(ans2,{n-i+1,p+(n-i+1)});
    }
    for(int i=2;i<=n;i++)
        if(a[i]==a[i-1])
            ans2={0,1};
    print(ans2);
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}