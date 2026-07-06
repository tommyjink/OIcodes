#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N=5005,M=10005,S=32,INF=4e18;
int n,m,k,q,head[N],tot,dis[N][S],vis[N][S],o[N];
struct edge{int to,nxt,w;}e[M];
struct node{int u,d,s;};

inline void add(int u,int v,int w){
    e[++tot]={v,head[u],w};
    head[u]=tot;
}

inline bool operator<(node a,node b){
    return a.d>b.d;
}

void dijkstra(int s,int *p){
    priority_queue<node> q;
    for(int i=1;i<=n;i++)
        for(int j=0;j<S;j++)
            dis[i][j]=INF,vis[i][j]=0;
    dis[s][0]=0;
    q.push({s,0,0});
    while(!q.empty()){
        node t=q.top();
        q.pop();
        if(vis[t.u][t.s])continue;
        vis[t.u][t.s]=1;
        for(int i=head[t.u];i;i=e[i].nxt){
            int v=e[i].to;
            if(t.d+e[i].w<dis[v][t.s]){
                dis[v][t.s]=t.d+e[i].w;
                q.push({v,dis[v][t.s],t.s});
            }
            for(int j=1;j<=5;j++){
                if(p[j]==-1)continue;
                if(t.s&(1ll<<(j-1)))continue;
                int ns=t.s|(1ll<<(j-1));
                int nd=t.d+e[i].w*(10-j)/10+p[j];
                if(nd<dis[v][ns]){
                    dis[v][ns]=nd;
                    q.push({v,nd,ns});
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        cin>>o[i];
        o[i]++;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u++,v++;
        add(u,v,w);
    }
    cin>>q;
    while(q--){
        int s,p[6]={0};
        cin>>s>>p[1]>>p[2]>>p[3]>>p[4]>>p[5];
        s++;
        dijkstra(s,p);
        int ans=INF;
        for(int i=1;i<=k;i++)
            for(int j=0;j<S;j++)
                ans=min(ans,dis[o[i]][j]);
        if(ans==INF)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
