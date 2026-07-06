#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=2e6+100;
int n,m;
struct node
{
    int l,r,lx,rx,mx,val;
}t[N*4];
void pushup(int k)
{
    t[k].lx=t[k*2].lx,t[k].rx=t[k*2+1].rx;
    if(t[k*2].lx==t[k*2].val)t[k].lx=t[k*2].val+t[k*2+1].lx;
    if(t[k*2+1].rx==t[k*2+1].val)t[k].rx=t[k*2+1].val+t[k*2].rx;
    t[k].mx=max({t[k*2].mx,t[k*2+1].mx,t[k*2].rx+t[k*2+1].lx});
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    t[k].val=r-l+1;
    if(l==r)
    {
        t[k].lx=t[k].rx=t[k].mx=1;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int x,int d)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        t[k].lx=t[k].rx=t[k].mx=d;
        // cout<<t[k].l<<","<<d<<endl;
        return;
    }
    modify(k*2,x,d);
    modify(k*2+1,x,d);
    pushup(k);
    // cout<<k<<"!"<<t[k].lx<<","<<t[k].rx<<","<<t[k].mx<<endl;
}
int query(int k,int l,int r,int d)
{
    if(t[k].l==t[k].r)return t[k].l;
    if(t[k*2].mx>=d)return query(k*2,l,r,d);
    if(t[k*2].rx+t[k*2+1].lx>=d)return t[k*2].r-t[k*2].rx+1;
    if(t[k*2+1].mx>=d)return query(k*2+1,l,r,d);
    return -1;
}
void solve()
{
    set<int> s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        modify(1,x,0);
        s.insert(x);
    }
    cin>>m;
    while(m--)
    {
        char op;
        int x;
        cin>>op>>x;
        if(op=='+')
        {
            s.insert(x);
            modify(1,x,0);
        }
        else if(op=='-')
        {
            s.erase(x);
            modify(1,x,1);
        }
        else
        {
            if(x>t[1].mx)
                cout<<t[1].r-t[1].rx+1<<endl;
                else
            cout<<query(1,1,N-10,x)<<endl;
        }
    }
    for(auto i:s)modify(1,i,1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    build(1,1,N-10);
    while(T--)
        solve();
    return 0;
}