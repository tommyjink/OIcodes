#include <bits/stdc++.h>

// using fread
#define INPUT_OPTIMIZE

// using fwrite
// #define OUTPUT_OPTIMIZE

namespace IO {
//	by R_i.
}

using namespace IO;

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 10;

struct node {
	int v, a, b, c, d, id;
	bool operator < (const node &rhs) const { return b < rhs.b; }
}; vector<node> g[MAXN]; set<node> ts[MAXN];

int t[MAXN]; queue<int> q;

priority_queue<node> y[MAXN][21];

inline 
void upd(int u, int x) {
	if (!t[u]) t[u] = x;
	else t[u] = min(t[u], x);
}

inline 
void insert(int u, node p) {
	for (int i = p.c; i; i--) {
		for (; !y[u][i].empty() && y[u][i].top().b >= p.d;) {
			node tmp = y[u][i].top();
			q.push(tmp.v), ts[u].insert(tmp);
			upd(tmp.v, tmp.d), y[u][i].pop();
		}
	}
}

int n, m;

void solve(int S) {
	for (int i = 1; i <= n; i++) {
		for (node x : g[i]) y[i][x.a].push(x);
	}
	for (node x : g[S]) {
		upd(x.v, x.d);
		q.push(x.v), insert(x.v, x);
	}
	for (int u; !q.empty();) {
		u = q.front(), q.pop();
		if (!t[u]) continue;
		for (node p : ts[u]) insert(p.v, p);
		ts[u].clear();
	}
}

int S, ans;

int main() {
	read(n, m, S);
	for (int i = 1, u, v, a, b, c, d; i <= m; i++) {
		read(u, v, a, b, c, d);
		g[u].push_back({ v, a, b, c, d, i });
	}
	solve(S);
	for (int i = 1; i <= n; i++) ans = max(ans, t[i]);
	write(ans);
}
