#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define intl long long
#define inf (0x3f3f3f3f3f3f3f3f)
#define For(i,a,b) for(intl i=a;i<=b;i++)
#define deo(i,a,b) for(intl i=a;i>=b;i--)
intl read() {
    intl x=0,k=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch == '-') k=-1;ch=getchar();}
    while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*k;
}
intl dp[N][N], tmp[N], sz[N], n, k, a[N];
vector<intl> g[N];
void dfs(intl u,intl fath) {
    dp[u][1] = a[u], dp[u][0] = 0, sz[u] = 1;
    for(auto v:g[u]) {
        if(v == fath) continue;
        dfs(v, u);
        For(i, 0, sz[u] + sz[v]) tmp[i] = -inf;
        For(i, 1, sz[u]) For(j, 0, sz[v]) if(i+j <= k) {
            tmp[i+j] = max(tmp[i+j], dp[u][i] + dp[v][j]); 
        }
        For(i,1,sz[u]+sz[v]) dp[u][i] = tmp[i];
        sz[u] += sz[v];
    }
}
int main() {
    // freopen("camp.in","r",stdin);
    // freopen("camp.out","w",stdout);
    n = read(), k = read();
    memset(dp, 128, sizeof dp);
    For(i,1,n) a[i] = read();
    For(i,2,n) {
        intl u = read(),v = read();
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, 0);
    intl ans = -inf;
//    For(i,1,n) For(j,1,k) cout << dp[i][j] << " \n"[j == k];
    For(i,1,n) ans = max(ans, dp[i][k]);
    printf("%lld\n", ans);
    return 0;
}
/*
7 4
5 -2 4 6 3 -5 8
1 2
1 3 
2 4
2 5
3 6
3 7
*/