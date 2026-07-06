#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct query { int x, y, res = 0; };
void solve() {
	int n, k, s, q, x, y;
	cin >> n >> k >> s >> q;
	vector<vector<int>> g(n + 10);
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> cnt(n + 10);
	vector<unordered_map<int, bool>> col(n + 10);
	for (int i = 1; i <= s; i++) {
		cin >> x >> y;
		col[x][y] = true;
		cnt[x]++;
	}
	int tot = 0;
	vector<vector<int>> a(n + 10);
	vector<unordered_map<int, int>> cid(n + 10);
	vector<unordered_map<int, bool>> pid(n + 10);
	function<void(int, int)> dfs1 = [&] (int p, int fa) -> void {
		for (auto &[c, v] : col[p]) {
			if (fa == 0 || col[fa].find(c) == col[fa].end()) 
				a[p].push_back(++tot), cid[p][c] = tot, pid[p][tot] = true;
			else a[p].push_back(cid[fa][c]), cid[p][c] = cid[fa][c], pid[p][cid[fa][c]] = true;
		}
		for (int ed : g[p])
			if (ed != fa)
				dfs1(ed, p);
	};
	dfs1(1, 0);
	for (int i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end());
	vector<query> qs(q + 10);
	vector<vector<pair<int, int>>> tp(n + 10);
	const int B = sqrt(1ll * s * (n + s) / q);
	for (int i = 1; i <= q; i++) {
		cin >> qs[i].x >> qs[i].y;
		int X = qs[i].x, Y = qs[i].y;
		if (cnt[X] <= B && cnt[Y] <= B) {
			int px = 0, py = 0;
			while (px < cnt[X] && py < cnt[Y]) {
				if (a[X][px] == a[Y][py]) qs[i].res++, px++, py++;
				else if (a[X][px] < a[Y][py]) px++;
				else py++;
			}
		}
		else {
			if (cnt[X] >= B) tp[X].push_back({i, Y});
			else tp[Y].push_back({i, X});
		}
	}
	vector<int> mp(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (!tp[i].empty()) {
			for (auto &[qid, other] : tp[i]) {
				if (~mp[other]) { qs[qid].res = mp[other]; continue; }
				for (int c : a[other])
					qs[qid].res += pid[i].count(c);
				mp[other] = qs[qid].res;
			}
			for (auto &[qid, other] : tp[i]) mp[other] = -1;
		}
	}
	for (int i = 1; i <= q; i++)
		cout << qs[i].res << ' ';
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
