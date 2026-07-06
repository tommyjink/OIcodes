#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,q,a[N],b[N],sum,mx,sum1,sum2;
set<int> s1,s2;
void ins(set<int> &s,int c[],int &res,int x)
{
    auto it=s.lower_bound(x);
    int y=*it;
    if(it!=s.begin())
    {
        auto jt=prev(it);
        int z=*jt;
        res-=c[z]*(y-z);
        res+=c[z]*(x-z);
    }
    res+=c[x]*(y-x);
    s.insert(x);
}
void del(set<int> &s,int c[],int &res,int x)
{
    auto it=s.find(x),jt=next(it);
    int y=*jt;
    if(it!=s.begin())
    {
        auto kt=prev(it);
        int z=*kt;
        res-=c[z]*(x-z);
        res+=c[z]*(y-z);
    }
    res-=c[x]*(y-x);
    s.erase(it);
}
void add(set<int> &s,int c[],int &res,int x,int v)
{
    auto it=s.find(x);
    if(it!=s.end())
    {
        auto jt=next(it);
        res+=v*(*jt-x);
        c[x]+=v;
    }
    else
    {
        c[x]+=v;
        auto jt=s.lower_bound(x);
        int z=0;
        if(jt!=s.begin())
        {
            auto kt=prev(jt);
            z=*kt;
        }
        if(c[x]<=c[z])return;
        ins(s,c,res,x);
    }
    auto jt=next(s.find(x));
    while(*jt!=n+1&&c[*jt]<=c[x])
    {
        int y=*jt;
        jt=next(jt);
        del(s,c,res,y);
    }
}
void build(set<int> &s,int c[],int &res)
{
    s.clear();
    s.insert(n+1);
    res=0;
    int now=0,last=0;
    for(int i=1;i<=n;i++)
        if(c[i]>now)
        {
            if(last)res+=c[last]*(i-last);
            s.insert(i);
            last=i;
            now=c[i];
        }
    res+=c[last]*(n+1-last);
}
void solve()
{
    cin>>n;
    sum=0,mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        mx=max(mx,a[i]);
        b[n-i+1]=a[i];
    }
    a[0]=b[0]=0;
    build(s1,a,sum1);
    build(s2,b,sum2);
    cin>>q;
    while(q--)
    {
        int x,v;cin>>x>>v;
        sum+=v;
        add(s1,a,sum1,x,v);
        add(s2,b,sum2,n-x+1,v);
        mx=max(mx,a[x]);
        cout<<sum1+sum2-n*mx-sum<<endl;
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
