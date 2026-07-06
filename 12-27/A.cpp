#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int id,n,a[N];
struct node
{
    int l,r,val;
}t[N*4];

void pushup(int k)
{
    t[k].val=min(t[k*2].val,t[k*2+1].val);
}

void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=a[l];
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
        t[k].val=d;
        return;
    }
    modify(k*2,x,d);
    modify(k*2+1,x,d);
    pushup(k);
}

int query(int k,int l,int r,int d)
{
    if(l>t[k].r||r<t[k].l)return -1;
    if(l<=t[k].l&&t[k].r<=r)
    {
        if(t[k].l==t[k].r) return t[k].val<=d ? t[k].l : -1;
        if(t[k*2].val<=d) return query(k*2,l,r,d);
        if(t[k*2+1].val<=d) return query(k*2+1,l,r,d);
        return -1;
    }
    int res1=query(k*2,l,r,d);
    if(res1!=-1) return res1;
    return query(k*2+1,l,r,d);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>id>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    int day=1,idx=1,cnt=0;
    while(cnt<n)
    {
        int p=query(1,idx,n,cnt);
        if(p==-1)
        {
            if(idx==1) break;
            day++;
            idx=1;
            continue;
        }
        modify(1,p,1e9);
        cnt++;
        if(cnt==n) break;
        idx=p+1;
    }
    if(cnt<n) cout<<-1<<endl;
    else cout<<day<<endl;
    return 0;
}