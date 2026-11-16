#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e16;
int n,m,s,k,f[N];
int a[N],h[N];
vector<int> l[N];
struct node
{
    int l,r,L,R,D,M;
}t[N*4];
node merge(node x,node y)
{
    int w=abs(h[x.r]-h[y.l])+1;
    return {x.l,y.r,min(x.L,y.L+w+x.D),min(x.R+w+y.D,y.R),x.D+y.D+w,min(x.M,y.M)};
}
void pushup(int k)
{
    t[k]=merge(t[k*2],t[k*2+1]);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k]={l,r,f[l],f[l],0,f[l]};
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void upd(int k,int x)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        t[k]={t[k].l,t[k].r,f[t[k].l],f[t[k].r],0,f[t[k].r]};
        return;
    }
    upd(k*2,x);
    upd(k*2+1,x);
    pushup(k);
}
node query(int k,int l,int r)
{
    if(l<=t[k].l&&t[k].r<=r)return t[k];
    // if(t[k].l==t[k].r)return {0,0,INF,INF,INF,INF};
    int mid=(t[k].l+t[k].r)>>1;
    if(mid<l)return query(k*2+1,l,r);
    if(mid+1>r)return query(k*2,l,r);
    return merge(query(k*2,l,r),query(k*2+1,l,r));
}

void solve()
{
    cin>>n>>m>>s;
    for(int i=1;i<=n*m;i++)
        l[i].clear(),h[i]=0;
    k=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;cin>>x;
            l[x].push_back(j);
            k=max(k,x);
        }
    }
    for(int i=1;i<=m;i++)
        f[i]=(i==s?0ll:INF);
    build(1,1,m);
    // for(int k=1;k<=n*4;k++)
    // {
    //     cout<<t[k].l<<"~"<<t[k].r<<":"<<t[k].L<<","<<t[k].R<<","<<t[k].D<<","<<t[k].M<<endl;
    // }
    for(int i=1;i<=k;i++)
    {
        sort(l[i].begin(),l[i].end());
        int x=INF,y=INF;
        if(l[i].front()-1>0)x=query(1,l[i].front()-1,m).L;
        if(l[i].back()+1<=m)y=query(1,1,l[i].back()+1).R;
        if(l[i].front()-1>0)f[l[i].front()-1]=x,upd(1,l[i].front()-1);
        if(l[i].back()+1<=m)f[l[i].back()+1]=y,upd(1,l[i].back()+1);
        for(int j=0;j<l[i].size();j++)
        {
            int k=j;
            while(k<l[i].size()&&l[i][j]==l[i][k])k++;
            k--;
            h[l[i][j]]+=k-j+1;
            f[l[i][j]]=INF;
            upd(1,l[i][j]);
            j=k;
        }
    }
    if(t[1].M>=INF)cout<<"-1"<<endl;
    else cout<<t[1].M<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}