#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,c,h[N],f[N],g[N],q[N],p[N];
int w(int x,int y)
{
    return (h[x]-h[y])*(h[x]-h[y])+c;
}
int cal(int x,int y)
{
    return g[x]-2*h[x]*y;
}
bool check(int x,int y,int z)
{
    return (__int128)(g[y]-g[x])*(h[z]-h[y])>=(__int128)(g[z]-g[y])*(h[y]-h[x]);
}
void solve(int L,int R,int l,int r)
{
    if(L>R)return;
    int mid=(L+R)>>1;p[mid]=l;
    for(int i=l;i<=r;i++)
        if(w(i,mid)<w(p[l],mid))p[l]=i;
    solve(L,mid-1,l,p[l]);
    solve(mid+1,R,p[l],r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>c;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    int l=1,r=1;
    q[1]=1;
    g[1]=h[1]*h[1];
    for(int i=2;i<=n;i++)
    {
        while(l<r&&cal(q[l],h[i])>=cal(q[l+1],h[i]))l++;
        f[i]=h[i]*h[i]+c+cal(q[l],h[i]);
        g[i]=f[i]+h[i]*h[i];
        while(l<r&&check(q[r-1],q[r],i))r--;
        q[++r]=i;
    }
    cout<<f[n]<<endl;
    return 0;
}
