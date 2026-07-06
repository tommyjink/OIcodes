#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,fa[N],mx[N],mn[N];
struct node
{
    int x,y,z;
}e[N*2];
bool cmp(node x,node y)
{
    return x.z<y.z;
}
void init()
{
    for(int i=1;i<=n;i++)
        fa[i]=i,mx[i]=-1e15,mn[i]=1e15;
}
int getfa(int x)
{
    if(x==fa[x])return fa[x];
    else return fa[x]=getfa(fa[x]);
}
void merge(int x,int y)
{
    int fx=getfa(x),fy=getfa(y);
    if(fx==fy)return;
    mx[fx]=max(mx[fx],mx[fy]);
    mn[fx]=min(mn[fx],mn[fy]);
    fa[fy]=fx;
}
void solve()
{
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)
        cin>>e[i].x>>e[i].y>>e[i].z;
    sort(e+1,e+1+m,cmp);
    int ans=1e15;
    for(int i=1;i<=m;i++)
    {
        // cout<<e[i].x<<" "<<e[i].y<<":"<<e[i].z<<endl;
        merge(e[i].x,e[i].y);
        int f=getfa(e[i].x);
        mx[f]=max(mx[f],e[i].z);
        mn[f]=min(mn[f],e[i].z);
        if(getfa(1)==getfa(n))
        {
            ans=min(ans,mx[getfa(1)]+mn[getfa(1)]);
            // cout<<mx[getfa(1)]<<"!"<<mn[getfa(1)]<<endl;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}