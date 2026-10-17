#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=2e5+10,P=998244353,B=700;
int n,a[N],f[N],id[N],st[N],ed[N],lazy[N];

void add(int &x,int y)
{
    x+=y;
    if(x>=P)x-=P;
}

struct bit
{
    int t[N];
    void add(int x,int d)
    {
        for(int i=x;i<=n;i+=i&-i)
            ::add(t[i],d);
    }
    int query(int x)
    {
        int res=0;
        for(int i=x;i;i-=i&-i)
            ::add(res,t[i]);
        return res;
    }
    int sum(int l,int r)
    {
        if(l>r)return 0;
        return (query(r)-query(l-1)+P)%P;
    }
}t;

struct node
{
    int id,mx,val,sum;
}b[N],c[B+5],d[B+5];
vector<node> v[N/B+10];

void pushdown(int x)
{
    if(!lazy[x])return;
    for(int i=0;i<(int)v[x].size();i++)
    {
        v[x][i].mx=max(v[x][i].mx,lazy[x]);
        b[v[x][i].id].mx=v[x][i].mx;
    }
    lazy[x]=0;
}

void build(int x)
{
    int cnt1=0,cnt2=0,val=0;
    for(int i=0;i<(int)v[x].size();i++)
    {
        node now=b[v[x][i].id];
        if(now.mx==v[x][i].mx)c[cnt1++]=now;
        else
        {
            d[cnt2++]=now;
            val=now.mx;
        }
    }
    int p=0,j=0;
    while(j<cnt1&&(cnt2==0||c[j].mx<val))
        v[x][p++]=c[j++];
    for(int i=0;i<cnt2;i++)
        v[x][p++]=d[i];
    while(j<cnt1)
        v[x][p++]=c[j++];
    int sum=0;
    for(int i=0;i<(int)v[x].size();i++)
    {
        add(sum,v[x][i].val);
        v[x][i].sum=sum;
    }
}

int calc(int k,int x)
{
    if(lazy[k]>x||v[k].front().mx>x)return v[k].back().sum;
    if(v[k].back().mx<=x)return 0;
    int l=0,r=v[k].size();
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(v[k][mid].mx<=x)l=mid+1;
        else r=mid;
    }
    int res=v[k].back().sum;
    if(l)
    {
        res-=v[k][l-1].sum;
        if(res<0)res+=P;
    }
    return res;
}

int query(int r,int x)
{
    if(r<=0)return 0;
    int res=0,k=id[r];
    for(int i=1;i<k;i++)
        add(res,calc(i,x));
    for(int i=st[k];i<=r;i++)
        if(max(b[i].mx,lazy[k])>x)
            add(res,b[i].val);
    return res;
}

void modify(int k,int l,int r,int x)
{
    if(l>r)return;
    if(l==st[k]&&r==ed[k])
    {
        lazy[k]=max(lazy[k],x);
        return;
    }
    if(lazy[k]>=x)return;
    pushdown(k);
    bool flag=false;
    for(int i=l;i<=r;i++)
        if(b[i].mx<x)
        {
            b[i].mx=x;
            flag=true;
        }
    if(flag)build(k);
}

void modify(int l,int r,int x)
{
    if(l>r)return;
    int L=id[l],R=id[r];
    if(L==R)
    {
        modify(L,l,r,x);
        return;
    }
    modify(L,l,ed[L],x);
    for(int i=L+1;i<R;i++)
        lazy[i]=max(lazy[i],x);
    modify(R,st[R],r,x);
}

void insert(int x,int val)
{
    int k=id[x];
    pushdown(k);
    b[x].mx=0;
    b[x].val=val;
    build(k);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int tot=(n+B-1)/B;
    for(int k=1;k<=tot;k++)
    {
        st[k]=(k-1)*B+1;
        ed[k]=min(n,k*B);
        for(int i=st[k];i<=ed[k];i++)
        {
            id[i]=k;
            b[i]={i,0,0,0};             
            v[k].push_back(b[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        if(i==1)f[x]=1;
        else
        {
            int u=a[i-1];
            f[x]=(x<a[1]);
            if(u<x)add(f[x],t.sum(u,x-1));
            add(f[x],query(min(u,x)-1,x));
            if(u<x)modify(u,x-1,x);
        }
        insert(x,f[x]);
        t.add(x,f[x]);
    }
    cout<<t.sum(a[n],n)<<endl;
    return 0;
}
