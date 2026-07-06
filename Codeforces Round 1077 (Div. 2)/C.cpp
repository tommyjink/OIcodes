#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,fa[N],b[N];
struct xy
{
    int x,y;
}a[N];
bool cmp(xy x,xy y)
{
    return x.x<y.x;
}
int getfa(int x)
{
    if(x==fa[x])return fa[x];
    else return (fa[x]=getfa(fa[x]));
}
void add(int x,int y)
{
    int fx=getfa(x),fy=getfa(y);
    if(fx==fy)return;
    fa[fx]=fy;
}
bool check(int mid)
{
    for(int i=1;i<=n;i++)
        if(a[i].x!=b[i]&&abs(a[i].x-a[1].x)<mid&&abs(a[i].x-a[n].x)<mid)
            return false;
    return true;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x,a[i].y=i,b[i]=a[i].x;
    sort(a+1,a+1+n,cmp);
    int l=0,r=1e13;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    if(l<1e13)
        cout<<l<<endl;
    else cout<<"-1"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}