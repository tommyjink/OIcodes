#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2010,M=4010,INF=1e9;
int T,n,cnt,ans;
int head[N],to[M],nxt[M],deg[N];
int dis[N],q[N],num[N];
int mx[N];
signed dp[M][N],pos[M],vis[M],pre[N],suf[N],tim;
struct node
{
    signed x,id;
}p[N];
bool cmp(node a,node b)
{
    return a.x>b.x;
}
void add(int x,int y)
{
    to[++cnt]=y;
    nxt[cnt]=head[x];
    head[x]=cnt;
    deg[x]++;
}
void bfs(int s)
{
    num[0]=0;
    for(int i=1;i<=n;i++)
        dis[i]=-1,num[i]=0;
    int l=1,r=1;
    q[1]=s;
    dis[s]=0;
    while(l<=r)
    {
        int x=q[l++];
        for(int i=head[x];i;i=nxt[i])
        {
            int y=to[i];
            if(dis[y]!=-1)continue;
            dis[y]=dis[x]+1;
            q[++r]=y;
        }
    }
}
int calc1()
{
    ans=INF;
    for(int i=1;i<=n;i++)
    {
        bfs(i);
        int mx=0;
        for(int j=1;j<=n;j++)
            num[dis[j]]++;
        for(int j=0;j<n;j++)
            mx=max(mx,num[j]);
        ans=min(ans,mx);
    }
    return ans;
}
int calc2()
{
    for(int i=1;i<=n;i++)
        mx[i]=0;
    for(int i=2;i<=cnt;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INF;
    for(int i=2;i<=cnt;i++)
        dp[i][0]=0;
    for(int d=0;d<n;d++)
    {
        for(int x=1;x<=n;x++)
        {
            int tot=0;
            for(int i=head[x];i;i=nxt[i])
            {
                if(dp[i^1][d]>=INF)continue;
                p[++tot]=(node){dp[i^1][d],(signed)i};
            }
            if(!tot)continue;
            sort(p+1,p+tot+1,cmp);
            tim++;
            pre[0]=-INF;
            for(int i=1;i<=tot;i++)
            {
                pos[p[i].id]=i;
                vis[p[i].id]=tim;
                pre[i]=max(pre[i-1],(signed)(p[i].x+i-1));
            }
            suf[tot+1]=-INF;
            for(int i=tot;i>=1;i--)
                suf[i]=max(suf[i+1],(signed)(p[i].x+i-2));
            mx[x]=max(mx[x],(int)pre[tot]);
            if(d==n-1)continue;
            for(int i=head[x];i;i=nxt[i])
            {
                signed now;
                if(vis[i]==tim)now=max(pre[pos[i]-1],suf[pos[i]+1]);
                else now=pre[tot];
                if(now<0)now=INF;
                dp[i][d+1]=now;
            }
        }
    }
    ans=INF;
    for(int i=1;i<=n;i++)
        ans=min(ans,mx[i]+1);
    return ans;
}
void solve()
{
    cin>>n;
    cnt=1;
    for(int i=1;i<=n;i++)
        head[i]=deg[i]=0;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    int maxd=0,big=0;
    for(int i=1;i<=n;i++)
    {
        maxd=max(maxd,deg[i]);
        if(deg[i]>2)big++;
    }
    cout<<calc2()<<endl;
    // else if(big<=1)cout<<calc1()<<endl;
    // else cout<<calc1()<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("distance.in","r",stdin);
    freopen("distance.out","w",stdout);
    cin>>T;
    while(T--)solve();
    return 0;
}
