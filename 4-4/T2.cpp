#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,c[N],a[N],u[N],v[N],fa[N],dep[N],vis[N],tot;
int st[N],top,t1[N],t2[N],cnt1,cnt2;
int gcd(int x,int y)
{
    while(y)
    {
        int t=x%y;
        x=y;
        y=t;
    }
    return x;
}
signed main()
{
    cin>>n>>c[1];
    fa[1]=0;
    dep[1]=1;
    for(int i=2;i<=n;i++)
    {
        cin>>a[i]>>u[i]>>v[i];
        tot++;
        for(int j=u[i];j;j=fa[j])vis[j]=tot;
        int p=v[i];
        while(vis[p]!=tot)p=fa[p];
        int lca=p;
        cnt1=cnt2=0;
        for(int j=u[i];j!=lca;j=fa[j])t1[++cnt1]=j;
        t1[++cnt1]=lca;
        for(int j=v[i];j!=lca;j=fa[j])t2[++cnt2]=j;
        int now=a[i];
        for(int j=1;j<=cnt1;j++)now/=gcd(now,c[t1[j]]);
        for(int j=cnt2;j>=1;j--)now/=gcd(now,c[t2[j]]);
        c[i]=now;
        fa[i]=v[i];
        dep[i]=dep[v[i]]+1;
    }
    for(int i=1;i<=n;i++)
        cout<<c[i]<<endl;
    return 0;
}
