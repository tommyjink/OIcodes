#include <bits/stdc++.h>
using namespace std;
const int N=405;
const int M=N*N/2;
const int INF=0x3f3f3f3f;

struct Edge
{
    int u, v, w;
}e[M];
int g[N][N];
int f[N][N][N];
int n, m, q;
int ans[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        
        cin>>n>>m>>q;
        memset(g,0,sizeof g);
        for(int i=1,u,v,w;i<=m;i++){
            cin>>u>>v>>w;
            g[u][v]=g[v][u]=w;
            e[i]={u,v,w};
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[0][i][j]=g[i][j]?1:i==j?0:INF;
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    f[0][i][j]=min(f[0][i][j],f[0][i][k]+f[0][k][j]);
        sort(e+1,e+m+1,[](Edge x,Edge y){return x.w<y.w;});
        int del=0;
        for(int k=1;k<=m;k++){
            int u=e[k].u,v=e[k].v,w=e[k].w;
            if(f[del][u][v]==0)continue;
            ans[++del]=w;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    f[del][i][j]=f[del-1][i][j];
            f[del][u][v]=f[del][v][u]=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    f[del][i][j]=min(f[del][i][j],min(f[del-1][i][u]+f[del-1][v][j],f[del-1][i][v]+f[del-1][u][j]));
        }
        for(int i=1,a,b,k;i<=q;i++){
            cin>>a>>b>>k;
            int l=1,r=del;
            while(l<r){
                int mid=l+(r-l>>1);
                if(f[mid][a][b]<k)r=mid;
                else l=mid+1;
            }
            cout<<ans[l]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
