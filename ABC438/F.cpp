#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,cnt[N],l=1,r=1,dep[N];
int head[N],tot=0,f[N][30],ans=0;
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    cnt[x]=1;
    f[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        cnt[x]+=cnt[v];
    }
    if(x==1)
    {
        ans++;
        int sum=cnt[1];
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            sum-=cnt[v];
            ans+=cnt[v]*sum;
            cout<<cnt[v]<<","<<sum<<endl;
        }
    }
}
void init()
{
    for(int j=1;j<=29;j++)
        for(int i=1;i<=n;i++)
            f[i][j]=f[f[i][j-1]][j-1];
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=29;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])x=f[x][i];
    if(x==y)return x;
    for(int i=29;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;x++,y++;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    init();
    // for(int i=1;i<=n;i++)
    //     cout<<cnt[i]<<" ";
    // cout<<endl;
    for(int i=2;i<=n;i++)
    {
        int o1=lca(i,l),o2=lca(i,r);
        cout<<o1<<":"<<o2<<endl;
        if(o1==i||o2==i)ans+=cnt[l]*cnt[r];
        else if(o1==l)l=i,ans+=cnt[l]*cnt[r];
        else if(o2==r)r=i,ans+=cnt[l]*cnt[r];
        else break;
    }
    cout<<ans<<endl;
    return 0;
}