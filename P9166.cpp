
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll n, m, x;
ll mini = INT_MAX, maxi = 0;
bool v[N];
struct Node {
	ll l, r;
} a[N];
bool cmp(Node a, Node b) {
	if (a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}
int main() {
	cin >> m >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].r;
		if (a[i].l <= x && x <= a[i].r) {
			mini = min(mini, a[i].l);
			maxi = max(maxi, a[i].r);
			v[a[i].l] = v[a[i].r] = 1;
		}
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) if (a[i].l >= mini && a[i].l <= maxi) maxi = max(maxi, a[i].r);
	for (int i = n; i >= 1; i--) if (a[i].r >= mini && a[i].r <= maxi) mini = min(mini, a[i].l);
	for (int i = 1; i <= n; i++) {
		if (a[i].l < mini || a[i].r > maxi) continue;
		if (a[i].r < x) v[a[i].l] = 1;
		else v[a[i].r] = 1;
	}
	for (int i = 1; i <= m; i++) if (v[i] && i != x) cout << i << " ";
	return 0;
}

