#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10;
int n,q,lg[N];
int h[N];
signed g[N][19];
struct rmq
{
    signed f[N][19];
    int a[N];
    void init(bool tag=false)
    {
        for(int i=1;i<=n;i++){
            f[i][0]=i;
            if(tag)g[i][0]=i;
        }
        for(int i=1;(1<<i)<=n;i++)
            for(int j=1;j+(1<<i)-1<=n;j++){
                if(a[f[j][i-1]]>=a[f[j+(1<<(i-1))][i-1]])
                    f[j][i]=f[j][i-1];
                else f[j][i]=f[j+(1<<(i-1))][i-1];
                if(!tag)continue;
                if(a[g[j][i-1]]>a[g[j+(1<<(i-1))][i-1]])
                    g[j][i]=g[j][i-1];
                else g[j][i]=g[j+(1<<(i-1))][i-1];
            }
    }
    int queryl(int l,int r)
    {
        if(l>r)return -1;
        int len=r-l+1,k=lg[len];
        if(a[f[l][k]]>=a[f[r-(1<<k)+1][k]])  
            return f[l][k];
        else return f[r-(1<<k)+1][k];
    }
    int queryr(int l,int r)
    {
        if(l>r)return -1;
        int len=r-l+1,k=lg[len];
        if(a[g[l][k]]>a[g[r-(1<<k)+1][k]])  
            return g[l][k];
        else return g[r-(1<<k)+1][k];
    }
}U,V,H;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=2;i<=n;i++)
        lg[i]=lg[i/2]+1;
    for(int i=1;i<=n;i++)
        cin>>h[i],H.a[i]=h[i];
    stack<int> s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&h[s.top()]<h[i])s.pop();
        if(!s.empty()&&h[s.top()]==h[i])V.a[i]=(i-s.top())*h[i];
        else s.push(i);
    }
    while(!s.empty())s.pop();
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&h[s.top()]<h[i])s.pop();
        if(!s.empty()&&h[s.top()]==h[i])U.a[i]=(s.top()-i)*h[i];
        else s.push(i);
    }
    V.init();
    U.init();
    H.init(true);
    int l=0,r=0,z=0;
    int ans=0;
    for(int now=1;now<=q;now++)
    {
        if(now==1)cin>>l>>r;
        else
        {
            int x=(l+37*z)%n+1;
            int y=(l+r+53*z)%n+1;
            l=min(x,y);
            r=max(x,y);
        }
        int x=H.queryl(l,r);
        int y=H.queryr(l,r);
        z=(y-x)*h[x];
        if(l<x)z=max(z,U.a[U.queryl(l,x-1)]);
        if(y<r)z=max(z,V.a[V.queryl(y+1,r)]);
        ans^=(z+now);
    }
    cout<<ans<<endl;
    return 0;
}