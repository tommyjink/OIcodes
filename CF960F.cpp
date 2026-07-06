#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,ntot=0,root[N];
struct node
{
    int l,r,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=max(t[t[k].l].val,t[t[k].r].val);
}
void update(int &k,int l,int r,int x,int d)
{
    if(x<l||x>r)return;
    if(!k)k=++ntot;
    if(l==r)
    {
        t[k].val=max(t[k].val,d);
        return;
    }
    int mid=(l+r)>>1;
    update(t[k].l,l,mid,x,d);
    update(t[k].r,mid+1,r,x,d);
    pushup(k);
}
int query(int &k,int ll,int rr,int l,int r)
{
    if(ll>r||rr<l)return 0;
    if(l<=ll&&rr<=r)return t[k].val;
    int mid=(ll+rr)>>1;
    return max(query(t[k].l,ll,mid,l,r),query(t[k].r,mid+1,rr,l,r));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        update(root[i],1,N,1,0);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        z+=2;
        int tmp=query(root[x],1,N,1,z-1);
        update(root[y],1,N,z,tmp+1);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,query(root[i],1,N,1,N));
    cout<<ans<<endl;
    return 0;
}