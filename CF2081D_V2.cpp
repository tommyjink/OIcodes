#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,p[N],fa[N];
struct node
{
    int x,y,z;
}e[N*10];
bool check(node a,node b)
{
    return a.z<b.z;
}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
bool merge(int x,int y)
{
    x=getfa(x);
    y=getfa(y);
    if(x==y)return false;
    fa[x]=y;
    return true;
}
void solve()
{
    int cnt=0,mx=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i],mx=max(mx,p[i]);
    sort(p+1,p+1+n);
    n=unique(p+1,p+1+n)-p-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=p[i];j<=mx;j+=p[i])
        {
            int l=lower_bound(p+1,p+1+n,j)-p;
            if(j==p[i])l++;
            if(l<=n)e[++cnt]={i,l,p[l]-j};
        }
    }
    sort(e+1,e+1+cnt,check);
    int ans=0;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=cnt;i++)
        if(merge(e[i].x,e[i].y))
            ans+=e[i].z;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}