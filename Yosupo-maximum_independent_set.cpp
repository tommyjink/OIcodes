#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pp(x) __builtin_popcount(x)
using namespace std;
const int N=50,M=1000,L=2e6;
int n,m,f[N][N],k,g[L],vis[N];
vector<int> e[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    k=n/2;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        x++,y++;
        f[x][y]=f[y][x]=1;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    memset(vis,-1,sizeof(vis));
    for(int i=0;i<(1ll<<(n-k));i++)
    {
        int tmp=1;
        for(int j=1;j<=n-k;j++)
        {
            if(i&(1ll<<(j-1)))
            {
                if(vis[k+j]==i){tmp=0;break;}
                for(int v:e[k+j])vis[v]=i;
            }
        }
        if(tmp)g[i]=i;
    }
    for(int i=1;i<=n-k;i++)
    {
        for(int j=0;j<(1ll<<(n-k));j++)
        {
            if(!(j&(1ll<<(i-1))))continue;
            int now=j^(1ll<<(i-1));
            if(pp(g[j])<pp(g[now]))
            {
                g[j]=g[now];
            }
        }
    }
    memset(vis,-1,sizeof(vis));
    int ans=0,a=0,b=0;
    for(int i=0;i<(1ll<<k);i++)
    {
        int tmp=1;
        for(int j=1;j<=k;j++)
        {
            if(i&(1ll<<(j-1)))
            {
                if(vis[j]==i){tmp=0;break;}
                for(int v:e[j])vis[v]=i;
            }
        }
        if(!tmp)continue;
        int now=0;
        for(int j=1;j<=n-k;j++)
            if(vis[j+k]!=i)now^=(1ll<<(j-1));
        int res=1ll*pp(g[now])+1ll*pp(i);
        if(res>ans)
        {
            ans=res;
            a=i,b=g[now];
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=k;i++)
        if(a&(1ll<<(i-1)))cout<<i-1<<" ";
    for(int i=1;i<=n-k;i++)
        if(b&(1ll<<(i-1)))cout<<i+k-1<<" ";
    return 0;
}