#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m;
struct node
{
    int l,r,ans;
    double maxa;
}t[N*4];
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r){return;}
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
}
int query(int k,double now)
{
    if(t[k].maxa<=now)return 0;
    if(t[k].l==t[k].r)return 1;
    if(t[k*2].maxa<=now)return query(k*2+1,now);
    else return query(k*2,now)+t[k].ans-t[k*2].ans;
}
void change(int k,int x,double d)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r){t[k].maxa=d,t[k].ans=1;return;}
    change(k*2,x,d);
    change(k*2+1,x,d);
    t[k].maxa=max(t[k*2].maxa,t[k*2+1].maxa);
    t[k].ans=t[k*2].ans+query(k*2+1,t[k*2].maxa);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    build(1,1,n);
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        change(1,x,double(y)/double(x));
        cout<<t[1].ans<<endl;
    }
    return 0;
}
/*
3 4
2 4
3 6
1 1000000000
1 1
*/