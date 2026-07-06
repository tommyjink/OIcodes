#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll (k<<1)
#define rr (k<<1|1)
#define mid ((l+r)>>1)
int _, n, q, a[300005];
struct tree {
	int l, r, ls, rs, mx, sum;
} t[1500005];
inline void pushup(int k) {
	t[k].sum = t[ll].sum + t[rr].sum;
	t[k].ls = max(t[ll].ls, t[ll].sum + t[rr].ls);
	t[k].rs = max(t[rr].rs, t[rr].sum + t[ll].rs);
	t[k].mx = max({t[ll].rs + t[rr].ls, t[ll].mx, t[rr].mx});
	return ;
}
void build(int k, int l, int r) {
	t[k].l = l, t[k].r = r;
	if (l == r) {
		t[k].ls = t[k].rs = t[k].mx = t[k].sum = -1;
		return ;
	}
	build(ll, l, mid);
	build(rr, mid + 1, r);
	pushup(k);
	return ;
}
void update(int k, int c, int p) {
	if (t[k].l > c || t[k].r < c) return ;
	if (t[k].l == t[k].r) {
		t[k].ls = t[k].rs = t[k].mx = t[k].sum = p;
		return ;
	}
	update(ll, c, p);
	update(rr, c, p);
	pushup(k);
	return ;
}
struct node {
	int a, b, c;
};
vector<node> qs[300005];
vector<int> add[300005], del[300005];
multiset<int> bst;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> _;
	while (_--) {
		cin >> n >> q;
		build(1, 1, n);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			qs[a[i]].push_back({1, i, 1});
			bst.insert(-1);
		}
		for (int d = 1; d <= q; d++) {
			int i, x;
			cin >> i >> x;
			qs[a[i]].push_back({d, i, -1});
			qs[a[i] = x].push_back({d, i, 1});
		}
		for (int x = 1; x <= n; x++) {
			for (auto [d, i, k] : qs[x]) {
				del[d].push_back(t[1].mx);
				update(1, i, k);
				add[d].push_back(t[1].mx);
			}
			for (auto [d, i, k] : qs[x])
				update(1, i, -1);
		}
		for (int i = 1; i <= q; i++) {
			for (int x : add[i]) bst.insert(x);
			for (int x : del[i]) bst.erase(bst.lower_bound(x));
			cout << (*bst.rbegin() >> 1) << " ";
		}
		cout << "\n";
		bst.clear();
		for (int i = 1; i <= max(n, q); i++) {
			del[i].clear();
			add[i].clear();
			qs[i].clear();
		}
	}
	return 0;
}