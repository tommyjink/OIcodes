#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6e6 + 10;
struct Node {
	int id, nxt, pre;
	int tag;
} lk[N];
int cnt, head, idx[N];
int n, q, a[N], fa[N];
int stk[N], top;
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) fa[fy] = fx;
}
void add(int x) {
	lk[++cnt].id = x;
	lk[cnt].nxt = head;
	lk[head].pre = cnt;
	head = cnt;
}
void del(int x) {
	lk[lk[x].pre].nxt = lk[x].nxt;
	lk[lk[x].nxt].pre = lk[x].pre;
}

signed main() {
	scanf("%lld%lld", &n, &q);
	iota(fa + 1, fa + n + 1, 1);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	stk[top = 1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] < a[stk[top]]) merge(stk[top], i);
		else stk[++top] = i;
	}
	for (int i = n; i >= 1; i--) if (find(i) == i) add(i), idx[i] = cnt;
	while (q--) {
		int op, x, y;
		scanf("%lld%lld%lld", &op, &x, &y);
		if (op == 2) {
			if (find(y) >= x) puts("0");
			else printf("%lld\n", abs(x - find(x)));
		} else {
			x = find(x);
			int root = x, tag = -y;
			x = lk[idx[x]].nxt;
			for (; x; x = lk[x].nxt) {
				tag += lk[x].tag;
				if (a[lk[x].id] + tag < a[root]) del(x), merge(root, lk[x].id);
				else break;
			}
			if (x) lk[x].tag += tag - lk[x].tag;
		}
	}
	return 0;
}
