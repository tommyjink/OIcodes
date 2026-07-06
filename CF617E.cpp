#include<bits/stdc++.h>
#define endl "\n"
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
const int N=1e6+10;
int n,m,k,a[N],t[N*10],id[N],len=0;
long long ans[N],now=0;
struct node
{
    int l,r,id;
}q[N];
inline bool cmp(node &x,node &y)
{
    if(id[x.l]!=id[y.l])return id[x.l]<id[y.l];
    if(id[x.l]&1)return x.r>y.r;
    return x.r<y.r;
}
inline void add(int x)
{
    now+=t[k^a[x]];
    t[a[x]]++;
}
inline void del(int x)
{
    t[a[x]]--;
    now-=t[k^a[x]];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    len=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i],a[i]^=a[i-1];
        id[i]=(i-1)/len+1;
    }
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=m;i++)
        cin>>q[i].l>>q[i].r,q[i].id=i;
    for(int i=1;i<=m;i++)
        q[i].l--;
    sort(q+1,q+1+m,cmp);
    int l=1,r=0;
    // add(0);
    for(int i=1;i<=m;i++)
    {
        // cout<<"i:"<<i<<endl;
        while(l<q[i].l)del(l++);
        while(l>q[i].l)add(--l);
        while(r<q[i].r)add(++r);
        while(r>q[i].r)del(r--);
        ans[q[i].id]=now;
        // if(a[q[i].l]==k)ans
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}
/*
50 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
17 35

2 1 0
0 0 
1 2
*/