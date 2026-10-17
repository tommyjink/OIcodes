#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+10,INF=4e18;
const int S0=(N+63)/64,S1=(S0+63)/64,S2=(S1+63)/64;
int n,m,len,tot,sz,a,b,c;
int ch[N][26],dep[N],v[N],l[N],r[N];
int id[N],w[N],cnt[N],val[N];
int g[N],bel[N],lim[N],tag[N],ans[N];
int now,sum;
bool ok[N];
unsigned long long s0[S0],s1[S1],s2[S2];

inline int high(unsigned long long x)
{
    return 63-__builtin_clzll(x);
}

inline int low(unsigned long long x)
{
    return __builtin_ctzll(x);
}

inline unsigned long long lmask(int x)
{
    if(!x)return 0;
    return (1ULL<<x)-1;
}

inline unsigned long long rmask(int x)
{
    if(x==63)return 0;
    return ~0ULL<<(x+1);
}

inline void insert(int x)
{
    int p=x>>6;
    unsigned long long bt=1ULL<<(x&63);
    if(s0[p])
    {
        s0[p]|=bt;
        return;
    }
    s0[p]=bt;
    int q=p>>6;
    bt=1ULL<<(p&63);
    if(s1[q])
    {
        s1[q]|=bt;
        return;
    }
    s1[q]=bt;
    s2[q>>6]|=1ULL<<(q&63);
}

inline void erase(int x)
{
    int p=x>>6;
    s0[p]&=~(1ULL<<(x&63));
    if(s0[p])return;
    int q=p>>6;
    s1[q]&=~(1ULL<<(p&63));
    if(s1[q])return;
    s2[q>>6]&=~(1ULL<<(q&63));
}

inline int getpre(int x)
{
    int p=x>>6,q=x&63;
    unsigned long long z=s0[p]&lmask(q);
    if(z)return (p<<6)+high(z);
    int p1=p>>6,q1=p&63;
    z=s1[p1]&lmask(q1);
    if(z)
    {
        int x=(p1<<6)+high(z);
        return (x<<6)+high(s0[x]);
    }
    int p2=p1>>6,q2=p1&63;
    z=s2[p2]&lmask(q2);
    if(z)
    {
        int x=(p2<<6)+high(z);
        int y=(x<<6)+high(s1[x]);
        return (y<<6)+high(s0[y]);
    }
    for(int i=p2-1;i>=0;i--)
        if(s2[i])
        {
            int x=(i<<6)+high(s2[i]);
            int y=(x<<6)+high(s1[x]);
            return (y<<6)+high(s0[y]);
        }
    return -1;
}

inline int getnxt(int x)
{
    int p=x>>6,q=x&63;
    unsigned long long z=s0[p]&rmask(q);
    if(z)return (p<<6)+low(z);
    int p1=p>>6,q1=p&63;
    z=s1[p1]&rmask(q1);
    if(z)
    {
        int x=(p1<<6)+low(z);
        return (x<<6)+low(s0[x]);
    }
    int p2=p1>>6,q2=p1&63;
    z=s2[p2]&rmask(q2);
    if(z)
    {
        int x=(p2<<6)+low(z);
        int y=(x<<6)+low(s1[x]);
        return (y<<6)+low(s0[y]);
    }
    for(int i=p2+1;i<S2;i++)
        if(s2[i])
        {
            int x=(i<<6)+low(s2[i]);
            int y=(x<<6)+low(s1[x]);
            return (y<<6)+low(s0[y]);
        }
    return -1;
}

inline void insg(int x)
{
    int l=getpre(x),r=getnxt(x);
    now-=(x-l)*(r-x);
    insert(x);
}

inline void delg(int x)
{
    int l=getpre(x),r=getnxt(x);
    now+=(x-l)*(r-x);
    erase(x);
}

inline void add(int x)
{
    int p=id[x];
    cnt[p]++;
    val[p]+=w[x];
    if(!ok[p]&&val[p]>=lim[p])
    {
        ok[p]=1;
        int x=bel[p];
        if(++tag[x]==1)insg(x);
    }
}

inline void del(int x)
{
    int p=id[x];
    cnt[p]--;
    val[p]-=w[x];
    if(ok[p]&&(cnt[p]==0||val[p]<lim[p]))
    {
        ok[p]=0;
        int x=bel[p];
        if(--tag[x]==0)delg(x);
    }
}

struct node
{
    int l,r,id,bl;
}q[N];

bool cmp(const node &x,const node &y)
{
    if(x.bl!=y.bl)return x.bl<y.bl;
    if(x.bl&1)return x.r<y.r;
    return x.r>y.r;
}

int gcd(int x,int y)
{
    while(y)
    {
        int t=x%y;
        x=y;
        y=t;
    }
    return x;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        len=max(len,(int)s.size());
        l[i]=sz+1;
        int p=0;
        for(int j=0;j<s.size();j++)
        {
            int x=s[j]-'a';
            if(!ch[p][x])
            {
                ch[p][x]=++tot;
                dep[tot]=dep[p]+1;
            }
            p=ch[p][x];
            id[++sz]=p;
            w[sz]=v[i];
        }
        r[i]=sz;
    }
    for(int i=1;i<=len;i++)cin>>g[i];
    static int h[N];
    for(int i=1;i<=len;i++)
    {
        int x=c-a*i;
        if(x<=0)h[i]=0;
        else if(!b)h[i]=INF;
        else h[i]=(x+b-1)/b;
    }
    for(int i=1;i<=tot;i++)
    {
        bel[i]=g[dep[i]];
        lim[i]=h[dep[i]];
    }
    insert(0);
    insert(len+1);
    sum=len*(len+1)/2;
    now=sum;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        q[i].l=l[x];
        q[i].r=r[y];
        q[i].id=i;
    }
    int block=max(1LL,(int)(sz/sqrt((double)m)));
    for(int i=1;i<=m;i++)q[i].bl=(q[i].l-1)/block;
    sort(q+1,q+m+1,cmp);
    int l=1,r=0;
    for(int i=1;i<=m;i++)
    {
        while(r<q[i].r)add(++r);
        while(l>q[i].l)add(--l);
        while(r>q[i].r)del(r--);
        while(l<q[i].l)del(l++);
        ans[q[i].id]=now;
    }
    for(int i=1;i<=m;i++)
    {
        int x=sum-ans[i],y=sum;
        int d=gcd(x,y);
        cout<<x/d<<"/"<<y/d<<endl;
    }
    return 0;
}
