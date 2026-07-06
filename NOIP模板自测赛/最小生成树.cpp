#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,fa[N];
struct node
{
    int x,y,val;
}e[N*2];
bool operator <(const node &x,const node &y)
{
    return x.val<y.val;
}
int getfa(int x,int *fa)
{
    if(x==fa[x])return x;
    else return (fa[x]=getfa(fa[x],fa));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
        cin>>e[i].x>>e[i].y>>e[i].val;
    sort(e+1,e+1+m);
    int ans=0,cnt=0;
    for(int i=1;i<=m;i++)
    {
        int x=getfa(e[i].x,fa);
        int y=getfa(e[i].y,fa);
        if(x==y)continue;
        fa[x]=y;
        ans+=e[i].val;
        cnt++;
    }
    if(cnt==n-1)cout<<ans<<endl;
    else cout<<"orz"<<endl;
    return 0;
}