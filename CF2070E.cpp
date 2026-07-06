#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 3e5 + 10;
const int OFFSET = 3e5 * 3 + 10;
const int SIZE = OFFSET * 2 + 10;

char s[MAXN];
int tr[SIZE];
int pre[MAXN];
int n;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    x += OFFSET;
    for (; x < SIZE; x += lowbit(x)) {
        tr[x] += v;
    }
}

ll query(int x) {
    x += OFFSET;
    ll res = 0;
    for (; x > 0; x -= lowbit(x)) {
        res += tr[x];
    }
    return res;
}

int main() {
    scanf("%d%s", &n, s + 1);
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + (s[i] == '0' ? 1 : -3);
    }
    add(pre[0], 1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += query(pre[i] - 2);
        ans += query(pre[i] + 1) - query(pre[i]);
        add(pre[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}