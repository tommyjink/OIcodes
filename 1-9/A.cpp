#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+5;
int n,m,a[N],lazy[N*4];
struct node
{
    int l,r,max_val,min_val;
}t[N*4];

inline int get_log(int x)
{
    if(x<=1)return 0;
    return 63-__builtin_clzll(x);
}

void pushdown(int k)
{
    if(lazy[k])
    {
        lazy[k*2]+=lazy[k];
        lazy[k*2+1]+=lazy[k];
        t[k*2].max_val+=lazy[k];
        t[k*2].min_val+=lazy[k];
        t[k*2+1].max_val+=lazy[k];
        t[k*2+1].min_val+=lazy[k];
        lazy[k]=0;
    }
}

void pushup(int k)
{
    t[k].max_val=max(t[k*2].max_val,t[k*2+1].max_val);
    t[k].min_val=min(t[k*2].min_val,t[k*2+1].min_val);
}

void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy[k]=0;
    if(l==r)
    {
        t[k].max_val=a[l];
        t[k].min_val=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}

void update(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        int log_max=get_log(t[k].max_val);
        int log_min=get_log(t[k].min_val);
        if(log_max==log_min)
        {
            t[k].max_val+=log_max;
            t[k].min_val+=log_max;
            lazy[k]+=log_max;
            return;
        }
    }
    pushdown(k);
    update(k*2,l,r);
    update(k*2+1,l,r);
    pushup(k);
}

void print_res(int k)
{
    if(t[k].l==t[k].r)
    {
        cout<<t[k].max_val;
        return;
    }
    pushdown(k);
    print_res(k*2);
    cout<<" ";
    print_res(k*2+1);
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        update(1,l,r);
    }
    print_res(1);
    cout<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}