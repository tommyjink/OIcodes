#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2600,P=1e9+7;
int n,m,X,Y,fa[N][21],val[N],dp[N][N],f[N][N];
int tot,head[N],k,rt[N],dep[N];
vector<int> h[N];
struct node1{int sum,cnt,val;};
vector<node1> a[N],d[N];
bool cmp(node1 x,node1 y)
{
    return x.val<y.val;
}
struct node
{
    int to,next,val;
}e[N*2];
void add(int x,int y,int val)
{
    e[++tot]=(node){y,head[x],val};
    head[x]=tot;
}
struct DSU
{
    int fa[N];
    int getfa(int x)
    {
        if(x==fa[x])return x;
        return fa[x]=getfa(fa[x]);
    }
    void merge(int x,int y)
    {
        x=getfa(x),y=getfa(y);
        fa[x]=y;
    }
    void init()
    {
        for(int i=1;i<=n;i++)fa[i]=i;
    }
}t;
void dfs(int x,int f,vector<int> &h)
{
    h.push_back(x);
    dep[x]=dep[f]+1;
    fa[x][0]=f;
    for(int i=1;i<=20;i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==f)continue;
        val[v]=val[x]+e[i].val;
        dfs(v,x,h);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int dis(int x,int y)
{
    int o=lca(x,y);
    return val[x]+val[y]-2*val[o];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>X>>Y;
    t.init();
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
        t.merge(x,y);
    }
    for(int i=1;i<=n;i++)
        if(i==t.fa[i])
            rt[++k]=i;
    int lim=max(0ll,Y-k*X);
    for(int i=1;i<=k;i++)
    {
        dfs(rt[i],0,h[i]);
        for(int x:h[i])
            for(int y:h[i])
                if(x<y)
                {
                    int tmp=dis(x,y);
                    d[i].push_back({tmp,1,min(lim,tmp)});
                }
        sort(d[i].begin(),d[i].end(),cmp);
        for(int j=0;j<d[i].size();j++)
        {
            int jj=j,sum=0,cnt=0;
            while(jj<d[i].size()&&d[i][j].val==d[i][jj].val)
            {
                sum+=d[i][jj].sum;
                cnt+=d[i][jj].cnt;
                jj++;
            }
            a[i].push_back({sum,cnt,d[i][j].val});
            j=jj-1;
        }
    }
    f[0][0]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=lim;j++)
        {
            for(auto [sum,cnt,val]:a[i])
            {
                int tmp=min(lim,j+val);
                f[i][tmp]=(f[i][tmp]+f[i-1][j]*cnt%P)%P;
                dp[i][tmp]=(dp[i][tmp]+dp[i-1][j]*cnt%P+f[i-1][j]*sum%P)%P;
            }
        }
    }
    int ans=(dp[k][lim]+f[k][lim]*(k*X%P)%P)%P;
    for(int i=1;i<k;i++)ans=ans*i%P*2%P;
    cout<<ans<<endl;
    return 0;
}