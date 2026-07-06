#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
//f[i]=min{f[j]+max[j+1->i]}
int n,m,a[N],b[N],f[N],sum[N],lazy[N];
struct node
{
    int l,r,minval,f;
}t[N*4];
void pushdown(int k)
{
    if(lazy[k])
    {
        lazy[k*2]=lazy[k*2+1]=lazy[k];
        t[k*2].minval=t[k*2].f+lazy[k];
        t[k*2+1].minval=t[k*2+1].f+lazy[k];
        lazy[k]=0;
    }
}
void pushup(int k)
{
    t[k].minval=min(t[k*2].minval,t[k*2+1].minval);
    t[k].f=min(t[k*2].f,t[k*2+1].f);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].minval=1e10;
        t[k].f=1e10;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
} 
void add_f(int k,int x,int d)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        t[k].f=d;
        return;
    }
    pushdown(k);
    add_f(k*2,x,d);
    add_f(k*2+1,x,d);
    pushup(k);
}
void modify_m(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        lazy[k]=d;
        t[k].minval=t[k].f+d;
        return;
    }
    pushdown(k);
    modify_m(k*2,l,r,d);
    modify_m(k*2+1,l,r,d);
    pushup(k);
}
int MIN(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 1e10;
    if(l<=t[k].l&&t[k].r<=r)return t[k].minval;
    pushdown(k);
    return min(MIN(k*2,l,r),MIN(k*2+1,l,r));
}
int S(int l,int r)
{
    return sum[r]-sum[l-1];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum[i]=sum[i-1]+a[i];
    build(1,0,n);
    stack<int> st;
    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&a[st.top()]<=a[i])st.pop();
        if(st.empty())b[i]=0;
        else b[i]=st.top();
        st.push(i);
    }
    int l=1;
    // for(int i=1;i<=n;i++)
    //     cout<<b[i]<<" ";
    // cout<<endl;
    add_f(1,0,0);
    for(int i=1;i<=n;i++)
    {
        modify_m(1,b[i],i-1,a[i]);
        while(l<=i&&S(l,i)>m)l++;
        f[i]=MIN(1,l-1,i-1);
        add_f(1,i,f[i]);
    }
    // for(int i=1;i<=n;i++)
    //     cout<<f[i]<<" ";
    cout<<f[n];
    return 0;
}
/*
4 6
1 3 3 1
*/