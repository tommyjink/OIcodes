#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,head[N],tot,a[N];
int fa[N][21],val[N],g[N][21];
int d[N],c[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x)
{
    val[x]=val[fa[x][0]]+a[x];
    g[x][0]=val[fa[x][0]];
    // cout<<g[x][0]<<"!"<<endl;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa[x][0])continue;
        dfs(v);
    }
}
void init()
{
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fa[j][i]=fa[fa[j][i-1]][i-1];
            g[j][i]=min(g[j][i-1],g[fa[j][i-1]][i-1]);
        }
    }
}
int fd(int x)
{
    // cout<<"find:"<<x<<",val:"<<val[x]<<",";
    int v=val[x];
    for(int i=20;i>=0;i--)
        if(g[x][i]>v)x=fa[x][i];
    // x=fa[x][0];
    // cout<<x<<"!!"<<val[x]<<endl;
    if(val[fa[x][0]]==v)return x;
    else return -1;
}
void dfs1(int x)
{
    d[x]+=d[fa[x][0]];
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa[x][0])continue;
        dfs1(v);
    }
}
void print(int *a)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
signed main()
{
    // freopen("pathseq.in","r",stdin);
    // freopen("pathseq.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    string s;cin>>s;
    for(int i=1;i<=n;i++)
        if(s[i-1]=='(')a[i]=1;
        else a[i]=-1;
    for(int i=2;i<=n;i++)
    {
        int x;cin>>x;
        fa[i][0]=x;
        add(x,i);
        add(i,x);
    }
    dfs(1);
    init();
    // print(val);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        // if(val[i]<0)continue;
        int res=fd(i);
        // cout<<"i:"<<i<<":"<<res<<endl;
        if(~res)d[i]=d[fa[res][0]]+1;
    }
    dfs1(1);
    for(int i=1;i<=n;i++)
        ans^=(i*d[i]);
    cout<<ans<<endl;
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<d[i]<<" ";
    // cout<<endl;
    return 0;
}