#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define endl "\n"
using namespace std;
const int N=2e6+100;
int n,a[N],t[N],ans[N];
struct node
{
    int l,r,num;
}v[N];
bool cmp(node x,node y)
{
    return x.r==y.r?x.l<y.l:x.r<y.r;
}
void add(int x,int d)
{
    for(int i=x;i<=2*n;i+=lowbit(i))
        t[i]+=d;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
int query(int l,int r)
{
    if(l>r)return 0;
    return sum(r)-sum(l-1);
}
void solve()
{
    int cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i<=a[i])
            v[++cnt]={i,a[i],a[i]},
            v[++cnt]={i+n,a[i]+n,a[i]};
        else v[++cnt]={i,a[i]+n,a[i]};
    }
    for(int i=1;i<=2*n;i++)t[i]=0;
    sort(v+1,v+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
    {
        ans[v[i].num]=v[i].r-v[i].l-query(v[i].l,v[i].r);
        add(v[i].l,1);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}