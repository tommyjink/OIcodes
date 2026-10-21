#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,p[N],a[N],b[N];
struct node
{
    int l,r,mn,pos;
}t[N*4];
void pushup(int k)
{
    if(t[k*2].mn<=t[k*2+1].mn)
    {
        t[k].mn=t[k*2].mn;
        t[k].pos=t[k*2].pos;
    }
    else
    {
        t[k].mn=t[k*2+1].mn;
        t[k].pos=t[k*2+1].pos;
    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].mn=a[l];
        t[k].pos=l;
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
        t[k].mn=d;
        return;
    }
    modify(k*2,x,d);
    modify(k*2+1,x,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)a[i]=b[p[i]];
    stack<int> s;
    int lst=0;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&p[s.top()]<p[i])s.pop();
        if(!s.empty())lst=s.top();
        else lst=1;

        s.push(i);
    }
    return 0;
}