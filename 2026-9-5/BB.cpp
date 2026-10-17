#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,head[N],tot=0,now,dis[N];
int vis[N],in[N],ans=0,mx=0;
vector<int> x[N],v[N];
struct node
{
    int to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    // cout<<x<<","<<y<<","<<z<<endl;
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
bool cmp(int xx,int yy)
{
    return x[xx][now]>x[yy][now];
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void dfs(int x)
{
    vis[x]=in[x]=true;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(in[v])ans=gcd(ans,abs(dis[x]-dis[v]+e[i].val));
        else if(!vis[v])dis[v]=dis[x]+e[i].val,dfs(v);
        if(ans)return;
    }
    in[x]=false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        x[i].resize(n+1);
        for(int j=1;j<=n;j++)
        {
            cin>>x[i][j];
            mx=max(mx,x[i][j]);
            if(x[i][j])
                v[j].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        now=i;
        sort(v[i].begin(),v[i].end(),cmp);
        int len=v[i].size();
        for(int xx=0;xx<len-1;xx++)
        {
            int yy=xx+1;
            add(v[i][xx],v[i][yy],x[v[i][xx]][i]-x[v[i][yy]][i]);
            add(v[i][xx],v[i][yy],-x[v[i][xx]][i]+x[v[i][yy]][i]);
        }
    }
    for(int i=1;i<=m;i++)
        if(!vis[i])dfs(i);
    int cnt=0,res=0;
    for(int i=1;i*i<=ans;i++)
        if(ans%i==0)
        {
            if(i>mx)cnt++,res=i;
            if(i*i!=ans&&ans/i>mx)cnt++,res=ans/i;
        }
    if(cnt==1)cout<<res<<endl;
    else cout<<-1<<endl;
    return 0;
}