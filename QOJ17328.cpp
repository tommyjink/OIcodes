#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],f[N],A[N],B[N];
struct line
{
    int k=0,b=0;
    int get(int x){return k*x+b;}
}t1[N*4],t2[N*4];
void insert(line *t,int k,int l,int r,line d)
{
    int mid=(l+r)>>1;
    if(d.get(mid)>t[k].get(mid))swap(d,t[k]);
    if(l==r)return;
    if(d.get(l)>t[k].get(l))insert(t,k*2,l,mid,d);
    if(d.get(r)>t[k].get(r))insert(t,k*2+1,mid+1,r,d);
}
int query(line *t,int k,int l,int r,int x)
{
    int res=t[k].get(x);
    if(l==r)return res;
    int mid=(l+r)>>1;
    if(x<=mid)res=max(res,query(t,k*2,l,mid,x));
    else res=max(res,query(t,k*2+1,mid+1,r,x));
    return res;
}
int cal(int st)
{
    for(int i=st;i<st+n;i++)
        a[i-st+1]=A[i],b[i-st+1]=B[i];
    for(int i=1;i<=n;i++)
        f[i]=0;
    memset(t1,0,sizeof(t1));
    memset(t2,0,sizeof(t2));
    int mx1=a[1]*b[1],mx2=0;
    insert(t1,1,1,N,{a[1],0});
    insert(t2,1,1,N,{b[1],0});
    for(int i=1;i<=n;i++)
    {
        f[i]=max({mx1,mx2+a[i]*b[i],query(t1,1,1,N,b[i]),query(t2,1,1,N,a[i])});
        if(i==n)continue;
        mx1=max(mx1,f[i]+a[i+1]*b[i+1]);
        mx2=max(mx2,f[i]);
        insert(t1,1,1,N,{a[i+1],f[i]});
        insert(t2,1,1,N,{b[i+1],f[i]});
    }
    return f[n];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int p=1;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i]>>B[i],A[i+n]=A[i],B[i+n]=B[i];
        if(A[i]>A[p])p=i;
    }
    cout<<max(cal(p),cal(p+1))<<endl;
    return 0;
}