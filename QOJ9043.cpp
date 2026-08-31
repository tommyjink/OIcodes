#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,INF=4e18;
int n,a[N],b[N],c[N],T;
struct node{double l,r;}d[N];
bool cmp(node x,node y)
{
    if(x.r==y.r)return x.l<y.l;
    return x.r<y.r;
}
int check(int mid)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0&&b[i]>=mid)d[i]={-INF,INF};
        else if(a[i]==0)d[i]={INF,INF};
        else if(a[i]<0)d[i]={-INF,(1.0*mid-b[i])/a[i]};
        else d[i]={(1.0*mid-b[i])/a[i],INF};
    }
    sort(d+1,d+1+n,cmp);
    int p=1,cnt=0;
    for(int i=1;i<=n;i++)
    {
        while(p<=n&&c[p]*1.0<d[i].l)p++;
        if(p<=n&&c[p]*1.0<=d[i].r)p++,cnt++;
    }
    return cnt>=(n+1)/2;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    sort(c+1,c+1+n);
    int l=-2e18,r=2e18;
    while(l<r)
    {
        int mid=l+(r-l+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)solve();
    return 0;
}