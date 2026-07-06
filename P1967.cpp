#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 300000;
ll n, m, k;
ll u[MAXN], v[MAXN], w[MAXN], edge_w[MAXN], from[MAXN], to[MAXN], nxt[MAXN], last[MAXN];
ll up[MAXN][18], max_edge[MAXN][18], depth[MAXN], bfs_queue[MAXN];
bool visited[MAXN];
int parent[MAXN];

ll find_set(ll x) {
    if (parent[x] != x) parent[x] = find_set(parent[x]);
    return parent[x];
}

void quick_sort(int l, int r) {
    int i = l, j = r, pivot = w[(l + r) / 2];
    while (i <= j) {
        while (w[i] < pivot) i++;
        while (w[j] > pivot) j--;
        if (i <= j) {
            swap(w[i], w[j]);
            swap(u[i], u[j]);
            swap(v[i], v[j]);
            i++, j--;
        }
    }
    if (l < j) quick_sort(l, j);
    if (i < r) quick_sort(i, r);
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++) parent[i] = i;
    quick_sort(1, m);
    for (int i = 1; i <= m; i++) {
        if (find_set(u[i]) != find_set(v[i])) {
            parent[find_set(u[i])] = find_set(v[i]);
            edge_w[++k] = w[i];
            edge_w[k + n - 1] = w[i];
            from[k] = u[i];
            from[k + n - 1] = v[i];
            to[k] = v[i];
            to[k + n - 1] = u[i];
            nxt[k] = last[u[i]];
            nxt[k + n - 1] = last[v[i]];
            last[u[i]] = k;
            last[v[i]] = k + n - 1;
        }
    }

    for (int j = 1; j <= n; j++) {
        if (!visited[j]) {
            int l = 1, r = 1;
            bfs_queue[1] = j;
            depth[j] = 1;
            visited[j] = true;
            while (l <= r) {
                int i = last[bfs_queue[l]];
                while (i) {
                    if (!visited[to[i]]) {
                        depth[to[i]] = depth[from[i]] + 1;
                        up[to[i]][0] = from[i];
                        max_edge[to[i]][0] = edge_w[i];
                        bfs_queue[++r] = to[i];
                        visited[to[i]] = true;
                    }
                    i = nxt[i];
                }
                l++;
            }
        }
    }

    for (int j = 1; j <= 17; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
            max_edge[i][j] = max(max_edge[i][j - 1], max_edge[up[i][j - 1]][j - 1]);
        }
    }

    cin >> m;
    // Queries
    while (m--) {
        ll u, v, ans = 0;
        cin >> u >> v;

        if (find_set(u) != find_set(v)) {
            cout << "impossible\n";
            continue;
        }

        // LCA
        if (depth[u] < depth[v]) swap(u, v);
        for (int j = 17; j >= 0; j--) {
            if (depth[up[u][j]] >= depth[v]) {
                ans = max(ans, max_edge[u][j]);
                u = up[u][j];
            }
        }
        if (u == v) {
            cout << ans << "\n";
            continue;
        }
        for (int j = 17; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                ans = max({ans, max_edge[u][j], max_edge[v][j]});
                u = up[u][j];
                v = up[v][j];
            }
        }
        ans = max({ans, max_edge[u][0], max_edge[v][0]});
        cout << ans << "\n";
    }

    return 0;
}

