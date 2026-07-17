#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3005,mod=998244353;
int n,cnt,ans;
int head[N],to[N],nxt[N],dep[N],dp[N][N];
void add(int x,int y)
{
    to[++cnt]=y;
    nxt[cnt]=head[x];
    head[x]=cnt;
}
void dfs(int x)
{
    for(int i=head[x];i;i=nxt[i])
    {
        int y=to[i];
        dep[y]=dep[x]+1;
        dfs(y);
    }
    if(x==n)return;
    int s=0;
    for(int i=1;i<=dep[x];i++)
    {
        int res=1;
        for(int j=head[x];j;j=nxt[j])
            res=res*dp[to[j]][i+1]%mod;
        s=(s+res)%mod;
        dp[x][i]=s;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("reflection.in","r",stdin);
    freopen("reflection.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x<y)swap(x,y);
        add(x,y);
    }
    dep[n]=1;
    dfs(n);
    ans=1;
    for(int i=head[n];i;i=nxt[i])
        ans=ans*dp[to[i]][1]%mod;
    cout<<ans<<endl;
    return 0;
}
