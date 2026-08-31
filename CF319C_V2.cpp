#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,M=1e9,INF=1e18;
int n,f[N],a[N],b[N],tot,rt,ls[N],rs[N];
struct Line
{
    int k,b;
    int get(int x){return k*x+b;}
}t[N*16];
void insert(int &k,int l,int r,Line d)
{
    if(!k)k=++tot,t[k]={0,INF};
    int mid=(l+r)>>1;
    // cout<<k<<" "<<l<<" "<<r<<" "<<d.get(mid)<<"!"<<d.k<<endl;
    if(d.get(mid)<t[k].get(mid))swap(t[k],d);
    if(l==r)return;
    if(d.get(l)<t[k].get(l))insert(ls[k],l,mid,d);
    else if(d.get(r)<t[k].get(r))insert(rs[k],mid+1,r,d);
}
int query(int k,int l,int r,int x)
{
    if(!k)return INF;
    // cout<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<t[k].k<<" "<<t[k].b<<endl;
    int mid=(l+r)>>1,res=t[k].get(x);
    if(l==r)return res;
    if(x<=mid)res=min(res,query(ls[k],l,mid,x));
    else res=min(res,query(rs[k],mid+1,r,x));
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    insert(rt,0,M,{b[1],0});
    for(int i=2;i<=n;i++)
    {
        f[i]=query(rt,0,M,a[i]);
        // cout<<f[i]<<endl;
        insert(rt,0,M,{b[i],f[i]});
    }
    cout<<f[n]<<endl;
    return 0;
}