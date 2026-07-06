#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2 * 1e6 + 10;
int du[N];
vector<int> G[N];
bool del[N];

inline int read() {
    int f = 1, x = 0;
    int ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = read(), cnt;
    while (t--) {
        cnt = 0;
        int n = read(), m = read();
        for (int i = 0; i < m; ++i) {
            int x = read(), y = read();
            G[x].push_back(y + n);
            G[y + n].push_back(x);
            du[x]++, du[y + n]++;
        }
        queue<int> q;
        for (int i = 1; i <= 2 * n; ++i) {
            if (du[i] == 1)q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (del[u]) continue;
            del[u] = 1;
            cnt++;
            int id;
            for (int i = 0; i < (int)G[u].size(); ++i) {
                if (!del[G[u][i]]) {
                    id = G[u][i];
                    break;
                }
            }
            cnt++;
            del[id] = 1;
            for (int i = 0; i < (int)G[id].size(); ++i) {
                if ((--du[G[id][i]]) == 1) {
                    q.push(G[id][i]);
                }
            }
        }
        cout << (n * 2 == cnt? "Renko" : "Merry") << endl;
        for (int i = 1; i <= 2 * n; ++i) du[i] = del[i] = 0, G[i].clear();
    }
    return 0;
}