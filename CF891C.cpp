
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n, m, q;
int fa[N];
struct Edge {
	int u, v, w, id;
	int tu, tv;
	bool operator < (const Edge &rhs) const {
		return w < rhs.w;
	}
} e[N];

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
	return x * f;
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unite(int x, int y) { fa[find(x)] = find(y); }

bool cmp_id(const Edge &a, const Edge &b) { return a.id < b.id; }

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		e[i].u = read(); e[i].v = read(); e[i].w = read(); e[i].id = i;
	}
	sort(e + 1, e + m + 1);
	e[0].w = -1;
	for (int i = 1; i <= m;) {
		int j = i;
		do {
			e[j].tu = find(e[j].u);
			e[j].tv = find(e[j].v);
			++j;
		} while (j <= m && e[j].w == e[j - 1].w);
		while (i < j) {
			while (find(e[i].u) == find(e[i].v) && i < j) ++i;
			if (i < j) unite(e[i].u, e[i].v);
		}
	}
	q = read();
	sort(e + 1, e + m + 1, cmp_id);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	while (q--) {
		int k = read();
		vector<Edge> v;
		for (int i = 1; i <= k; ++i) {
			int a = read();
			v.push_back({e[a].tu, e[a].tv, e[a].w});
		}
		sort(v.begin(), v.end());
		bool ok = 1;
		for (int i = 0, sz = v.size() - 1; i <= sz && ok;) {
			if (v[i].u == v[i].v) { ok = 0; break; }
			unite(v[i].u, v[i].v);
			int j = i + 1;
			while (j <= sz && v[j].w == v[i].w) {
				if (find(v[j].u) == find(v[j].v)) { ok = 0; break; }
				unite(v[j].u, v[j].v); ++j;
			}
			while (i < j) fa[v[i].u] = v[i].u, fa[v[i].v] = v[i].v, ++i;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
