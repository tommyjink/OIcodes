#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010, maxm = 500010;
int n, m, k, fa[maxn], ans[maxm], siz[maxn];
long long V;
struct edge{
    int u, v;
    long long w;
}e[maxm];
struct query{
    int u, v;
}q[maxm];
int getfa(int x){
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
void merge(int u, int v){
    u = getfa(u);
    v = getfa(v);
    if(u == v) return;
    if(siz[u] > siz[v]) fa[v] = u;
    else fa[u] = v;
}
void check(long long val){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
        siz[i] = 1;
    }
    for(int i = 1; i <= m; i++){
        if((e[i].w & val) == val) merge(e[i].u, e[i].v);
    }
    for(int i = 1; i <= k; i++){
        if(!ans[i] && getfa(q[i].u) == getfa(q[i].v)) ans[i] = 1;
    }
}
void solve(){
    cin >> n >> m >> k >> V;
    for(int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
    for(int i = 1; i <= k; i++) cin >> q[i].u >> q[i].v;
    check(V);
    long long now = 0;
    for(int i = 59; i >= 0; i--){
        now |= 1ll << i;
        if(!(V >> i & 1)){
            check(now);
            now ^= 1ll << i;
        }
    }
    for(int i = 1; i <= k; i++) cout << (ans[i] ? "Yes" : "No") << '\n';
}
int main(){
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}