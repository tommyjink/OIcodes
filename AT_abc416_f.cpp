#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=200005,K=6;
const ll inf=-1e18;

int n,k,tot;
int head[N];
ll a[N],dp[N][K][3],tmp[K][3];
struct edge{int nxt,to;}e[N<<1];

void add(int u,int v){
    e[++tot]={head[u],v};
    head[u]=tot;
}

void dfs(int u,int fa){
    dp[u][0][0]=0;
    dp[u][1][1]=dp[u][1][2]=a[u];
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        for(int j=0;j<=k;j++) tmp[j][0]=tmp[j][1]=tmp[j][2]=inf;
        for(int ku=0;ku<=k;ku++)
            for(int kv=0;kv<=k;kv++){
                ll vm=max({dp[v][kv][0],dp[v][kv][1],dp[v][kv][2]});
                int kt=ku+kv;
                if(kt<=k){
                    tmp[kt][0]=max(tmp[kt][0],dp[u][ku][0]+vm);
                    tmp[kt][1]=max(tmp[kt][1],dp[u][ku][1]+vm);
                    tmp[kt][2]=max(tmp[kt][2],dp[u][ku][2]+vm);
                }
                kt=ku+kv;
                if(kt<=k) tmp[kt][1]=max(tmp[kt][1],dp[u][ku][0]+dp[v][kv][1]+a[u]);
                kt=ku+kv-1;
                if(kt>=0&&kt<=k) tmp[kt][2]=max(tmp[kt][2],dp[u][ku][1]+dp[v][kv][1]);
            }
        for(int j=0;j<=k;j++){
            dp[u][j][0]=tmp[j][0];
            dp[u][j][1]=tmp[j][1];
            dp[u][j][2]=tmp[j][2];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=inf;
    dfs(1,0);
    ll ans=0;
    for(int i=0;i<=k;i++)
        ans=max({ans,dp[1][i][0],dp[1][i][1],dp[1][i][2]});
    cout<<ans;
    return 0;
}
