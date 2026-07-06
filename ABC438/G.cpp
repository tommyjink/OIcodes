#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int MOD=998244353;
const int N=2e5+10;
int n,m,k,a[N],b[N];
vector<int> ga[N],gb[N];
struct BIT
{
    int len;
    vector<int> t;
    void init(int l){len=l;t.assign(l+1,0);}
    void add(int x,int v)
    {
        for(++x;x<=len;x+=x&-x)t[x]=(t[x]+v)%MOD;
    }
    int ask(int x)
    {
        int res=0;
        for(++x;x;x-=x&-x)res=(res+t[x])%MOD;
        return res;
    }
    int query(int l,int r)
    {
        if(l>r)return 0;
        return (ask(r)-ask(l-1)+MOD)%MOD;
    }
}b1,b2;
struct event
{
    int val,type,id;
    bool operator<(const event &x)const
    {
        if(val!=x.val)return val<x.val;
        return type<x.type;
    }
};
struct qry
{
    int val,l,r,mul;
};
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int exgcd(int a,int b,int &x,int &y)
{
    if(!b){x=1,y=0;return a;}
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int inv(int a,int p)
{
    int x,y;
    exgcd(a,p,x,y);
    return (x%p+p)%p;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int g=gcd(n,m);
    int np=n/g,mp=m/g;
    int lcm_step=np*m;
    int full=k/lcm_step;
    int rem=k%lcm_step;
    int inv_n=inv(np,mp);
    for(int i=0;i<n;i++)ga[i%g].push_back(i);
    for(int i=0;i<m;i++)gb[i%g].push_back(i);
    int ans=0;
    for(int r=0;r<g;r++)
    {
        if(ga[r].empty()||gb[r].empty())continue;
        vector<int> beta(mp);
        for(auto x:gb[r])
        {
            int pos=((x-r)/g%mp*inv_n)%mp;
            beta[pos]=b[x];
        }
        vector<qry> qs;
        for(auto x:ga[r])
        {
            if(full)qs.push_back({a[x],0,mp-1,full%MOD});
            int lim=(rem-1-x)/n;
            if(lim>=0)
            {
                int st=((x-r)/g%mp*inv_n)%mp;
                int ed=(st+lim)%mp;
                if(st<=ed)qs.push_back({a[x],st,ed,1});
                else
                {
                    qs.push_back({a[x],st,mp-1,1});
                    qs.push_back({a[x],0,ed,1});
                }
            }
        }
        vector<event> ev;
        for(int i=0;i<mp;i++)ev.push_back({beta[i],0,i});
        for(int i=0;i<qs.size();i++)ev.push_back({qs[i].val,1,i});
        sort(ev.begin(),ev.end());
        b1.init(mp);b2.init(mp);
        for(auto e:ev)
        {
            if(e.type==0)
            {
                b1.add(e.id,1);
                b2.add(e.id,e.val);
            }
            else
            {
                int l=qs[e.id].l,r=qs[e.id].r;
                int cnt=b1.query(l,r);
                int sum=b2.query(l,r);
                int len=r-l+1;
                int cur=(sum+(len-cnt)%MOD*(e.val%MOD))%MOD;
                ans=(ans+cur*qs[e.id].mul)%MOD;
            }
        }
    }
    cout<<(ans+MOD)%MOD;
    return 0;
}