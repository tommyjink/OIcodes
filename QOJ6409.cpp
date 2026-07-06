#include<bits/stdc++.h>
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1000000+10;
const unsigned int P=(1u<<30),S=P-1;
int n,m,tot=0,rt=0;
int ls[N],rs[N],pri[N];
unsigned int len[N],siz[N],val[N],tag[N],sum[N];
mt19937 rnd(time(0));
int newnode(unsigned int x,unsigned int y)
{
    ++tot;
    ls[tot]=rs[tot]=0;
    pri[tot]=rnd();
    len[tot]=siz[tot]=x;
    val[tot]=y;
    tag[tot]=0;
    sum[tot]=1ull*x*y&S;
    return tot;
}
void pushup(int x)
{
    siz[x]=siz[ls[x]]+len[x]+siz[rs[x]];
    sum[x]=(sum[ls[x]]+sum[rs[x]]+(1ull*val[x]*len[x]&S))&S;
}
void addtag(int x,unsigned int y)
{
    if(!x)return;
    val[x]=(val[x]+y)&S;
    tag[x]=(tag[x]+y)&S;
    sum[x]=(sum[x]+1ull*siz[x]*y)&S;
}
void pushdown(int x)
{
    if(!tag[x])return;
    addtag(ls[x],tag[x]);
    addtag(rs[x],tag[x]);
    tag[x]=0;
}
int merge(int x,int y)
{
    if(!x||!y)return x+y;
    if(pri[x]>pri[y])
    {
        pushdown(x);
        rs[x]=merge(rs[x],y);
        pushup(x);
        return x;
    }
    else
    {
        pushdown(y);
        ls[y]=merge(x,ls[y]);
        pushup(y);
        return y;
    }
}
void split(int now,int k,int &x,int &y)
{
    if(!now)
    {
        x=y=0;
        return;
    }
    if(k<=0)
    {
        x=0,y=now;
        return;
    }
    if(k>=(int)siz[now])
    {
        x=now,y=0;
        return;
    }
    pushdown(now);
    if(k<(int)siz[ls[now]])
    {
        split(ls[now],k,x,ls[now]);
        y=now;
        pushup(now);
        return;
    }
    if(k>(int)(siz[ls[now]]+len[now]))
    {
        split(rs[now],k-siz[ls[now]]-len[now],rs[now],y);
        x=now;
        pushup(now);
        return;
    }
    if(k==(int)siz[ls[now]])
    {
        x=ls[now];
        ls[now]=0;
        y=now;
        pushup(now);
        return;
    }
    if(k==(int)(siz[ls[now]]+len[now]))
    {
        y=rs[now];
        rs[now]=0;
        x=now;
        pushup(now);
        return;
    }
    int t=newnode(len[now]-(k-siz[ls[now]]),val[now]);
    int rr=rs[now];
    len[now]=k-siz[ls[now]];
    rs[now]=0;
    pushup(now);
    x=now;
    y=merge(t,rr);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    unsigned int lim=(1u<<m),mask=lim-1,ans=0;
    rt=newnode(lim,0);
    for(int i=1;i<=n;i++)
    {
        unsigned int p,q;
        cin>>p>>q;
        unsigned int pp=(p+ans)&mask,qq=(q+ans)&mask;
        unsigned int l=min(pp,qq),r=max(pp,qq);
        int x,y,z;
        split(rt,l,x,y);
        split(y,r-l+1,y,z);
        ans=(ans+sum[y]+1ull*(r-l+1)*(unsigned int)i)&S;
        addtag(y,i);
        rt=merge(x,merge(y,z));
    }
    cout<<ans<<endl;
    return 0;
}
