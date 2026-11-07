#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,D,K,a[N];
int lazy[N*4];
vector<int> b;
struct node
{
    int l,r,mx;
}t[N*4];
void pushup(int k)
{
    t[k].mx=max(t[k*2].mx,t[k*2+1].mx);
}
void pushdown(int k)
{
    if(lazy[k])
    {
        lazy[k*2]+=lazy[k];
        lazy[k*2+1]+=lazy[k];
        t[k*2].mx+=lazy[k];
        t[k*2+1].mx+=lazy[k];
        lazy[k]=0;
    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy[k]=0;
    if(l==r)
    {
        t[k].mx=0;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,r);
    build(k*2+1,l,r);
    pushup(k);
}
void add(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return ;
    if(l<=t[k].l&&t[k].r<=r)
    {
        lazy[k]+=d;
        t[k].mx+=d;
        return;
    }
    pushdown(k);
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}
void solve()
{
    cin>>n>>D>>K;
    for(int i=1;i<=n;i++)
        cin>>a[i],b.push_back(a[i]);
    b.push_back(0);
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin();
    int ans=0,l=1;
    deque<int> q1,q2;
    for(int r=1;r<=n;r++)
    {
        while(!q2.empty()&&q2.front()<=r-D)q2.pop_front();
        while(!q2.empty()&&a[q2.back()]>=a[r])q2.pop_back();
        q2.push_back(r);
        if(r-l+1==D)
        while(!check())
        {
            l++;
        }
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