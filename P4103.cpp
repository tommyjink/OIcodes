#include<bits/stdc++.h>
#define endl "\n"
#define pii pair<int,int>
using namespace std;

const int N = 1e6 + 10;
const long long INF = 1e16; 


int n, head[N], tot, q, lg[N * 2], tag[N];
int dep[N], st[N * 2][22], dfn[N], cnt, c[N * 2]; 
vector<pii> g[N];


long long ans_sum, ans_min, ans_max;
int total_k;
long long sz[N], min_dp[N], max_dp[N];

struct node {
    int to, next;
} e[N * 2];

void add(int x, int y) {
    e[++tot] = (node){y, head[x]};
    head[x] = tot;
}

void dfs(int x, int fa) {
    c[++cnt] = x, dfn[x] = cnt;
    dep[x] = dep[fa] + 1;
    for (int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v, x);
        c[++cnt] = x;
    }
}

void init() {
    lg[1] = 0;
    
    for (int i = 2; i <= cnt; i++)
        lg[i] = lg[i / 2] + 1;
        
    for (int i = 1; i <= cnt; i++)
        st[i][0] = c[i];
        
    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j + (1 << i) - 1 <= cnt; j++) {
            if (dep[st[j][i - 1]] < dep[st[j + (1 << (i - 1))][i - 1]])
                st[j][i] = st[j][i - 1];
            else 
                st[j][i] = st[j + (1 << (i - 1))][i - 1];
        }
    }
}

int query(int l, int r) {
    int len = lg[r - l + 1];
    if (dep[st[l][len]] < dep[st[r - (1 << len) + 1][len]])
        return st[l][len];
    return st[r - (1 << len) + 1][len];
}

int lca(int x, int y) {
    if (dfn[x] > dfn[y]) swap(x, y);
    return query(dfn[x], dfn[y]);
}

void conn(int x, int y) {
    int val = dep[x] + dep[y] - 2 * dep[lca(x, y)];
    g[x].push_back(pii(y, val));
    g[y].push_back(pii(x, val));
}

void clear(vector<int> &a) {
    for (auto i : a) {
        g[i].clear();
        tag[i] = 0;
    }
    a.clear();
}

bool cmp(int x, int y) {
    return dfn[x] < dfn[y];
}

void tree(vector<int> &a) {
    sort(a.begin(), a.end(), cmp);
    int k = a.size();
    for (int i = 1; i < k; i++)
        a.push_back(lca(a[i - 1], a[i]));
    sort(a.begin(), a.end(), cmp);
    a.erase(unique(a.begin(), a.end()), a.end());
    k = a.size();
    for (int i = 1; i < k; i++)
        conn(lca(a[i - 1], a[i]), a[i]);
}

void dfs_dp(int u, int fa) {
    sz[u] = tag[u];
    min_dp[u] = tag[u] ? 0 : INF;
    max_dp[u] = tag[u] ? 0 : -INF;

    for (auto edge : g[u]) {
        int v = edge.first;
        long long w = edge.second; 
        if (v == fa) continue;
        
        dfs_dp(v, u);
        
        ans_sum += w * sz[v] * (total_k - sz[v]);
        
        if (sz[u] > 0 && sz[v] > 0) {
            ans_min = min(ans_min, min_dp[u] + min_dp[v] + w);
            ans_max = max(ans_max, max_dp[u] + max_dp[v] + w);
        }
        
        sz[u] += sz[v];
        min_dp[u] = min(min_dp[u], min_dp[v] + w);
        max_dp[u] = max(max_dp[u], max_dp[v] + w);
    }
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    
    dfs(1, 0);
    init();
    
    cin >> q;
    while (q--) {
        vector<int> a;
        int k;
        cin >> k;
        total_k = k;
        
        for (int i = 1; i <= k; i++) {
            int x;
            cin >> x;
            tag[x] = true;
            a.push_back(x);
        }
        
        tree(a);
        
        ans_sum = 0;
        ans_min = INF;
        ans_max = -INF;
        
        dfs_dp(a[0], 0);
        
        cout << ans_sum << " " << ans_min << " " << ans_max << endl;
        
        clear(a);
    }
    
    return 0;
}