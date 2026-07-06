#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N = 5010;    // 最大点数
const int M = 100010;  // 最大边数 (注意建双向边，要开两倍 m 以上)
const int inf = 1e16;  // 配合你的 inf

int n, m, s, t;
int head[N], tot = 1;

// 边的结构体：w 是容量(残量)，c 是费用
struct node {
    int to, nxt, w, c;
} e[M];

// 加边函数：正向边容量为 w，费用为 c；反向边容量为 0，费用为 -c
void add(int u, int v, int w, int c) {
    e[++tot] = {v, head[u], w, c};
    head[u] = tot;
    e[++tot] = {u, head[v], 0, -c};
    head[v] = tot;
}

// ================== 你提供的模板部分 开始 ==================
int dis[N],in[N],now[N];queue<int> q;
bool spfa(){
    for(int i=1;i<=n;i++) dis[i]=inf,now[i]=head[i];
    dis[s]=0,in[s]=1; q.push(s);
    while(!q.empty())
    {
        int u=q.front(); in[u]=0;q.pop();
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].to; 
            if(e[i].w&&dis[v]>dis[u]+e[i].c)
            {
                dis[v]=dis[u]+e[i].c;
                if(!in[v]) in[v]=1,q.push(v);
            }
        }
    }
    return dis[t]!=inf;
}
int dfs(int u,int sum){
    if(u==t) return sum;
    in[u]=1; int res=0;
    for(int i=now[u];i&&sum;i=e[i].nxt)
    {
        now[u]=i; int v=e[i].to;
        if(e[i].w&&dis[v]==dis[u]+e[i].c&&!in[v])
        {
            int k=dfs(v,min(e[i].w,sum));
            e[i].w-=k,e[i^1].w+=k,sum-=k,res+=k;
        }
    }
    in[u]=0;return res;
}
// ================== 你提供的模板部分 结束 ==================

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        add(u, v, w, c);
    }

    int maxflow = 0, mincost = 0;
    
    // 把你的 SPFA 和 DFS 组合起来
    while (spfa()) {
        int flow = dfs(s, inf);
        maxflow += flow;
        mincost += flow * dis[t]; // 增加的费用 = 增加的流量 * 最短路费用
    }

    cout << maxflow << " " << mincost << endl;
    return 0;
}