#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,q,p[N],lst[N],nxt[N],f[N],inv2=0;
int lazyx[N],lazyy[N],lim[N],ans[N];
vector<int> ins[N];
struct node
{
    int l,r;
    int h,t;
}t[N*4];
struct node1
{
    int l,id;
};
vector<node1> Q[N];
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
void pushdown(int k)
{
    if(t[k].l==t[k].r)return;
    if(lazyy[k])
    {
        (t[k*2].h+=t[k*2].t*lazyy[k]%P)%=P;
        (t[k*2+1].h+=t[k*2+1].t*lazyy[k]%P)%=P;
        (lazyy[k*2]+=lazyy[k]*lazyx[k*2]%P)%=P;
        (lazyy[k*2+1]+=lazyy[k]*lazyx[k*2+1]%P)%=P;
        lazyy[k]=0;
    }
    if(lazyx[k]!=1)
    {
        (t[k*2].t*=lazyx[k])%=P;
        (t[k*2+1].t*=lazyx[k])%=P;
        (lazyx[k*2]*=lazyx[k])%=P;
        (lazyx[k*2+1]*=lazyx[k])%=P;
        lazyx[k]=1;
    }
}
void pushup(int k)
{
    t[k].h=(t[k*2].h+t[k*2+1].h)%P;
    t[k].t=(t[k*2].t+t[k*2+1].t)%P;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazyx[k]=1;
    lazyy[k]=0;
    if(l==r){t[k].t=2;return;}
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void addtag(int k,int l,int r,int x,int y)
{
    if(t[k].l>r||t[k].r<l)return;
    pushdown(k);
    if(l<=t[k].l&&t[k].r<=r)
    {
        (t[k].h+=y*t[k].t%P)%=P;
        (t[k].t*=x)%=P;
        (lazyx[k]*=x)%=P;
        (lazyy[k]+=y)%P;
        return;
    }
    addtag(k*2,l,r,x,y);
    addtag(k*2+1,l,r,x,y);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].h;
    pushdown(k);
    return (query(k*2,l,r)+query(k*2+1,l,r))%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    inv2=qpow(2,P-2);
    for(int i=1;i<=n;i++)
        cin>>p[i];
    stack<int> s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&p[s.top()]<p[i])s.pop();
        if(!s.empty())lst[i]=s.top();
        s.push(i);
    }
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        Q[r].push_back({l,i});
    }
    while(!s.empty())s.pop();
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&p[s.top()]>p[i])s.pop();
        if(!s.empty())nxt[i]=s.top();
        s.push(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(lst[i+1])ins[i+1].push_back(i);
        if(nxt[i+1]&&lst[i]&&p[nxt[i+1]]<p[lst[i]])ins[nxt[i+1]].push_back(i);
        if(nxt[i])ins[nxt[i]].push_back(i);
        if(lst[i]&&nxt[i])lim[nxt[i]]=max(lim[nxt[i]],lst[i]);
    }
    build(1,1,n);
    for(int r=1;r<=n;r++)
    {
        addtag(1,1,r-1,2,0);
        for(int j:ins[r])
        {
            int now=lst[j+1];
            if(nxt[j+1]&&nxt[j+1]<=r&&lst[j]&&p[nxt[j+1]]<p[lst[j]])
                now=max(now,lst[j]);
            if(nxt[j]&&nxt[j]<=r)now=j;
            if(now>f[j])addtag(1,f[j]+1,now,inv2,0);
            f[j]=max(f[j],now);
        }
        if(lim[r])addtag(1,1,lim[r],0,0);
        addtag(1,1,r,1,1);
        for(auto [l,id]:Q[r])
        {
            ans[id]=query(1,l,r);
        }
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
    return 0;
}