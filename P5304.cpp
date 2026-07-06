#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 100, INF = 1e15;
int T, n, m, k, b[N], dis[N], done[N];
vector<pair<int, int> > e[N];

struct point {
    int num, dis;
};

bool operator <(point x, point y) {
    return x.dis > y.dis;
}

priority_queue<point> q;

// 快读函数
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

// 快写函数
inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

void dijkstra(int s) {
    memset(dis, 127, (n + 100) * sizeof(int));
    memset(done, 0, (n + 100) * sizeof(int));
    dis[s] = 0;
    q.push((point) {s, 0});
    while (!q.empty()) {
        point t = q.top();
        q.pop();
        if (done[t.num])
            continue;
        done[t.num] = true;
        for (auto i : e[t.num]) {
            int v = i.first;
            if (t.dis + i.second < dis[v]) {
                dis[v] = t.dis + i.second;
                q.push((point) {v, dis[v]});
            }
        }
    }
}

signed main() {
    T = read();
    while (T--) {
        n = read();
        m = read();
        k = read();
        int ans = INF, s = n + 1, t = n + 2;
        for (int i = 1; i <= m; i++) {
            int x = read(), y = read(), z = read();
            e[x].push_back(make_pair(y, z));
        }
        for (int i = 1; i <= k; i++)
            b[i] = read();
        for (int i = 0; i <= 20; i++) {
            e[s].clear();
            e[t].clear();
            for (int j = 1; j <= k; j++) {
                if (j & (1ll << i))
                    e[s].push_back(make_pair(b[j], 0));
                else
                    e[b[j]].push_back(make_pair(t, 0));
            }
            dijkstra(s);
            for (int j = 1; j <= k; j++) {
                if (j & (1ll << i))
                    e[s].pop_back();
                else
                    e[b[j]].pop_back();
            }
            ans = min(ans, dis[t]);
        }
        for (int i = 0; i <= 20; i++) {
            e[s].clear();
            e[t].clear();
            for (int j = 1; j <= k; j++) {
                if (!(j & (1ll << i)))
                    e[s].push_back(make_pair(b[j], 0));
                else
                    e[b[j]].push_back(make_pair(t, 0));
            }
            dijkstra(s);
            for (int j = 1; j <= k; j++) {
                if (!(j & (1ll << i)))
                    e[s].pop_back();
                else
                    e[b[j]].pop_back();
            }
            ans = min(ans, dis[t]);
        }
        write(ans);
        putchar('\n');
        for (int i = 1; i <= n + 100; i++)
            e[i].clear();
    }
    return 0;
}    