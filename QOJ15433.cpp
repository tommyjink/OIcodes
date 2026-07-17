#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005;
int n,fa[N],siz[N],sum[N];
int tot,head[N],f[N][2*N][3],ans[2*N];
struct node
{
    int to,next,from,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],x,z};
    head[x]=tot;
}
void dfs(int x)
{
    siz[x]=1;
    sum[x]=0;
    memset(f[x],-1,sizeof(f[x]));
    f[x][0][0]=0;
    int cur=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to,w=e[i].val;
        if(v==fa[x])continue;
        fa[v]=x;
        dfs(v);
        sum[v]+=w;
        for(int j=cur;j>=0;j--)
        {
            for(int c=2;c>=0;c--)
            {
                if(f[x][j][c]==-1)continue;
                int now=f[x][j][c];
                f[x][j+2*siz[v]][c]
                    =max(f[x][j+2*siz[v]][c],now+2*sum[v]);
                if(c<2)
                {
                    for(int q=0;q<=2*siz[v]-2;q++)
                    {
                        int val=max(f[v][q][0],f[v][q][1]);
                        if(val==-1)continue;
                        f[x][j+q+1][c+1]
                            =max(f[x][j+q+1][c+1],now+val+w);
                    }
                }
            }
        }
        cur+=2*siz[v];
        siz[x]+=siz[v];
        sum[x]+=sum[v];
    }
    for(int j=0;j<=2*siz[x]-2;j++)
        for(int c=0;c<=2;c++)
            ans[j]=max(ans[j],f[x][j][c]);
}
void solve()
{
    cin>>n;
    tot=0;
    for(int i=1;i<=n;i++)
        head[i]=fa[i]=siz[i]=sum[i]=0;
    for(int i=0;i<=2*n-2;i++)
        ans[i]=0;
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1);
    int all=2*sum[1];
    for(int i=0;i<=2*n-2;i++)
        cout<<all-ans[i]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}