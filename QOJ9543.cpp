#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q,a[N],b[N],g[N];
struct node{int l,r,val;}t[N*4];
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
void pushup(int k){t[k].val=gcd(t[k*2].val,t[k*2+1].val);}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r){t[k].val=b[l];return;}
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int x,int d)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r){t[k].val=d;return;}
    modify(k*2,x,d);
    modify(k*2+1,x,d);
    pushup(k);
}
void upd(int x)
{
    if(x<n&&a[x]>a[x+1])b[x]=x;
    else if(x<n) b[x]=0;
    if(x>1&&a[x]<a[x-1])b[x-1]=x-1;
    else if(x>1) b[x-1]=0;
    if(x<n)modify(1,x,b[x]);
    if(x>1)modify(1,x-1,b[x-1]);
}
void print()
{
    if(t[1].val==0)cout<<n<<endl;
    else cout<<g[t[1].val]<<endl;
}
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=0;
    for(int i=1;i<n;i++)if(a[i]>a[i+1])b[i]=i;
    build(1,1,n);
    print();
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        a[x]=y;
        upd(x);
        print();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i)
            g[j]++;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}