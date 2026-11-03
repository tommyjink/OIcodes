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
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    int l=n,r=n;
    node ans1={0,1},ans2={1,1};
    for(l=n,r=n;l>1;l--)
    {   
        while(r>=l&&(b[r]-b[l-1]+a[1])>=a[l]*(r-l+2))r--;
        // cout<<l<<","<<r<<","<<(b[r]-b[l-1]+a[1])<<" "<<(r-l+2)<<","<<a[l]<<endl;
        ans1=max(ans1,{r-l+1,r-l+2});
    }//31+35+37+42+43+44+45+46+47
    for(l=1,r=1;r<n;r++)
    {
        while(l<=r&&(b[r]-b[l-1]+a[n])<a[r]*(r-l+2))l++;
        ans2=min(ans2,{1,r-l+2});
    }
    for(int i=2;i<=n;i++)
        if(a[i]==a[i-1])ans2={0,1};
    print(ans1);
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