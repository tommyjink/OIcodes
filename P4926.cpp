
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, k;
double s[N];

struct edge {
	int to, nxt;
	double w;
} e[N << 1];
int head[N], tot;

struct node {
	int op, u, v;
	double w;
} a[N];

double dis[N];
int inq[N];
bool vis[N];

inline void add(int u, int v, double w) {
	e[++tot].to = v;
	e[tot].w = w;
	e[tot].nxt = head[u];
	head[u] = tot;
}

inline double Min(double a, double b) { return a < b ? a : b; }

bool spfa(double t) {
	memset(head, -1, sizeof(head));
	memset(e, 0, sizeof(e));
	tot = 0;
	for (int i = 1; i <= m; ++i) {
		if (a[i].op == 1) add(a[i].v, a[i].u, a[i].w - t);
		else add(a[i].v, a[i].u, 1.0 / (a[i].w + t));
	}
	for (int i = 1; i <= n; ++i) {
		if (s[i]) add(0, i, s[i]), add(i, 0, 1.0 / s[i]);
	}
	queue<int> q;
	memset(inq, 0, sizeof(inq));
	memset(vis, 0, sizeof(vis));
	vis[0] = 1, inq[0] = 1;
	for (int i = 0; i <= n; ++i) dis[i] = 1, q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; ~i; i = e[i].nxt) {
			int v = e[i].to;
			if (dis[v] < dis[u] * e[i].w) {
				dis[v] = dis[u] * e[i].w;
				if (!vis[v]) {
					vis[v] = 1;
					q.push(v);
					inq[v]++;
					if (inq[v] > n + 1) return 0;
				}
			}
		}
		vis[u] = 0;
	}
	return 1;
}

int main() {
	double t = -1, l = 1e-6, r = 1e7;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d%lf", &a[i].op, &a[i].u, &a[i].v, &a[i].w);
		if (a[i].op == 1) r = Min(r, a[i].w);
	}
	for (int i = 1; i <= k; ++i) {
		int id; double val;
		scanf("%d%lf", &id, &val);
		s[id] = val;
	}
	const double eps = 1e-12;
	while (l + eps < r) {
		double mid = (l + r) / 2;
		if (!spfa(mid)) t = l = mid;
		else r = mid;
	}
	if (t == -1) puts("-1");
	else printf("%.10lf\n", t);
	return 0;
}
