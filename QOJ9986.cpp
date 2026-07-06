#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,INF=1000000000000LL;
int n,m,a[N],mn[N<<2],mx[N<<2],sum[N<<2],ad[N<<2],tg[N<<2],cov[N<<2];
vector<int> L,R,V;
void up(int k)
{
    mn[k]=min(mn[k<<1],mn[k<<1|1]);
    mx[k]=max(mx[k<<1],mx[k<<1|1]);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
void put1(int k,int l,int r,int v)
{
    mn[k]=mx[k]=tg[k]=v;
    sum[k]=(r-l+1)*v;
    ad[k]=0;
    cov[k]=1;
}
void put2(int k,int l,int r,int v)
{
    mn[k]+=v;
    mx[k]+=v;
    sum[k]+=(r-l+1)*v;
    if(cov[k])tg[k]+=v;
    else ad[k]+=v;
}
void down(int k,int l,int r)
{
    int mid=(l+r)>>1;
    if(cov[k])
    {
        put1(k<<1,l,mid,tg[k]);
        put1(k<<1|1,mid+1,r,tg[k]);
        cov[k]=0;
    }
    if(ad[k])
    {
        put2(k<<1,l,mid,ad[k]);
        put2(k<<1|1,mid+1,r,ad[k]);
        ad[k]=0;
    }
}
void build(int k,int l,int r)
{
    cov[k]=ad[k]=tg[k]=0;
    if(l==r)
    {
        mn[k]=mx[k]=sum[k]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    up(k);
}
void change1(int k,int l,int r,int x,int y,int v)
{
    if(x<=l&&r<=y)
    {
        put1(k,l,r,v);
        return;
    }
    down(k,l,r);
    int mid=(l+r)>>1;
    if(x<=mid)change1(k<<1,l,mid,x,y,v);
    if(y>mid)change1(k<<1|1,mid+1,r,x,y,v);
    up(k);
}
void change2(int k,int l,int r,int x,int y,int v)
{
    if(x<=l&&r<=y)
    {
        put2(k,l,r,v);
        return;
    }
    down(k,l,r);
    int mid=(l+r)>>1;
    if(x<=mid)change2(k<<1,l,mid,x,y,v);
    if(y>mid)change2(k<<1|1,mid+1,r,x,y,v);
    up(k);
}
int ask1(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)return mn[k];
    down(k,l,r);
    int mid=l+r>>1,ans=INF;
    if(x<=mid)ans=min(ans,ask1(k<<1,l,mid,x,y));
    if(y>mid)ans=min(ans,ask1(k<<1|1,mid+1,r,x,y));
    return ans;
}
int ask2(int k,int l,int r,int x,int y)
{
    if(x<=l&&r<=y)return sum[k];
    down(k,l,r);
    int mid=l+r>>1,ans=0;
    if(x<=mid)ans+=ask2(k<<1,l,mid,x,y);
    if(y>mid)ans+=ask2(k<<1|1,mid+1,r,x,y);
    return ans;
}
void addseg(int l,int r,int v)
{
    if(!L.empty()&&R.back()+1==l&&V.back()==v)R.back()=r;
    else L.push_back(l),R.push_back(r),V.push_back(v);
}
void del(int k,int l,int r,int x,int y,int v)
{
    if(r<x||y<l||mn[k]>v||mx[k]<v)return;
    if(x<=l&&r<=y&&mn[k]==mx[k])
    {
        addseg(l,r,v);
        put1(k,l,r,INF);
        return;
    }
    if(l==r)
    {
        addseg(l,r,v);
        put1(k,l,r,INF);
        return;
    }
    down(k,l,r);
    int mid=(l+r)>>1;
    del(k<<1,l,mid,x,y,v);
    del(k<<1|1,mid+1,r,x,y,v);
    up(k);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(m--)
    {
        int op,l,r,v;
        cin>>op>>l>>r;
        if(op==1)
        {
            cin>>v;
            change1(1,1,n,l,r,v);
        }
        else if(op==3)
            cout<<ask2(1,1,n,l,r)<<endl;
        else
        {
            int now=ask1(1,1,n,l,r);
            if(now)
                continue;
            L.clear(),R.clear(),V.clear();
            int mex=0;
            while(1)
            {
                del(1,1,n,l,r,mex);
                int nxt=ask1(1,1,n,l,r);
                if(nxt!=mex+1)
                {
                    mex++;
                    break;
                }
                mex=nxt;
            }
            change2(1,1,n,l,r,mex);
            for(int i=0;i<(int)L.size();i++)
                change1(1,1,n,L[i],R[i],V[i]+mex);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
