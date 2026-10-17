#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],p[N];
string s,t;
struct BIT
{
    int t[N];
    void init()
    {
        for(int i=0;i<=n;i++)
            t[i]=0;
    }
    void add(int x,int d)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            t[i]+=d;
    }
    int sum(int x)
    {
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=t[i];
        return res;
    }
}B;
int g(int x)
{
    return (x+3)%3;
}
int num(char c)
{
    if(c=='R')return 0;
    if(c=='G')return 1;
    if(c=='B')return 2;
}
void solve()
{
    cin>>n>>s>>t;
    s=" "+s;
    t=" "+t;
    for(int i=1;i<=n;i++)
        a[i]=num(s[i]);
    for(int i=1;i<=n;i++)
        b[i]=num(t[i]);
    int cnta[3]={0,0,0},cntb[3]={0,0,0};
    stack<int> q[3];
    for(int i=n;i>=2;i--)
    {
        a[i]=g(a[i]-a[i-1]),
        b[i]=g(b[i]-b[i-1]);
        cnta[a[i]]++;
        q[b[i]].push(i);
        cntb[b[i]]++;
    }
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<b[i]<<" ";
    // cout<<endl;
    if(s[1]!=t[1]||s[n]!=t[n]){cout<<"-1"<<endl;return;}
    for(int i=0;i<=2;i++)
        if(cnta[i]!=cntb[i]){cout<<"-1"<<endl;return;}
    for(int i=2;i<=n;i++)
    {
        p[i]=q[a[i]].top();
        q[a[i]].pop();
    }
    // for(int i=1;i<=n;i++)
    //     cout<<p[i]<<" ";
    // cout<<endl;
    B.init();
    int ans=0;
    for(int i=n;i>=2;i--)
    {
        ans+=B.sum(p[i]);
        B.add(p[i],1);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}