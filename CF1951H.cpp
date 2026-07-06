#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=2e6+10;
int K,n,a[N],b[N],c[N];
struct node
{
    int l,r;
}t[N*4];
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
}
int dfs(int k,int T,int val)
{
    if(T==0)return (c[t[k].r]-c[t[k].l-1])==0;
    int res1=dfs(k*2,T-1,val>>1);
    int res2=dfs(k*2+1,T-1,val>>1);
    return max({res1+res2-1,val-c[t[k].r]+c[t[k].l-1],0});
}
bool check(int T,int mid)
{
    for(int i=1;i<=n;i++)
        b[i]=(a[i]>=mid),c[i]=c[i-1]+b[i];
    if(dfs(1,T,1<<T))
        return false;
    return true;
}
void solve()
{
    cin>>K;
    n=(1<<K);
    build(1,1,n);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int T=1;T<=K;T++)
    {

        int l=1,r=n;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(check(T,mid))l=mid;
            else r=mid-1;
        }
        cout<<l<<" ";
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}