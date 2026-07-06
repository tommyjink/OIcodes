#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],c[N],m=0,ans=0;
vector<int> v;
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
        t[k].val=c[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 1e15;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    return min(query(k*2,l,r),query(k*2+1,l,r));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n-1;i++)
        cin>>c[i],c[i]=i-c[i];
    build(1,1,n-1);
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i];
        if(a[i])
        {
            m=max(m,i);
            v.push_back(i);
        }
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        int cnt=0,x=v[i],y,z=x;
        if(i==0)y=0;
        else y=v[i-1];
        while(x>y)x=query(1,x,z),cnt++;
        ans+=cnt;
    }
    cout<<ans<<endl;
    return 0;
}