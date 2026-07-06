#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N = 1e6 + 10;
int n, tot = 0, Root = 0, num = 0, ans = 0;

struct node {
    int val, num;
} a[N];

bool cmp(node x, node y) {
    return x.val == y.val ? x.num < y.num : x.val > y.val;
}

struct Node {
    int ch[2], val, size, fa;
} t[N * 2];

void update(int id) {
    t[id].size = t[t[id].ch[0]].size + t[t[id].ch[1]].size + 1;
}

int NewNode(int val) {
    t[++tot].size = 1;
    t[tot].val = val;
    t[tot].fa = 0;
    return tot;
}

void rotate(int x) {
    int y = t[x].fa, z = t[y].fa;
    int d = (t[y].ch[1] == x);
    t[y].ch[d] = t[x].ch[d ^ 1];
    if (t[x].ch[d ^ 1]) t[t[x].ch[d ^ 1]].fa = y;
    t[x].ch[d ^ 1] = y;
    t[y].fa = x;
    t[x].fa = z;
    if (z) t[z].ch[t[z].ch[1] == y] = x;
    update(y); update(x);
}

void splay(int x, int goal) {
    while (t[x].fa != goal) {
        int y = t[x].fa, z = t[y].fa;
        if (z != goal) {
            if ((t[y].ch[1] == x) == (t[z].ch[1] == y)) rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    if (!goal) Root = x;
}

void insert(int val) {
    ++num;
    int x = Root, y = 0;
    while (x) {
        y = x;
        if (t[x].val == val) return;
        x = t[x].ch[t[x].val < val];
    }
    int id = NewNode(val);
    if (!y) {
        Root = id;
        return;
    }
    t[y].ch[t[y].val < val] = id;
    t[id].fa = y;
    splay(id, 0);
}

int Rank(int val) {
    int x = Root, res = 0;
    while (x) {
        if (t[x].val == val) {
            res += t[t[x].ch[0]].size + 1;
            splay(x, 0);
            return res;
        } else if (t[x].val < val) {
            res += t[t[x].ch[0]].size + 1;
            x = t[x].ch[1];
        } else {
            x = t[x].ch[0];
        }
    }
    return 0;
}

int kth(int id, int k) {
    while (1) {
        int lsize = t[t[id].ch[0]].size;
        if (lsize + 1 == k) return t[id].val;
        else if (lsize >= k) id = t[id].ch[0];
        else id = t[id].ch[1], k -= (lsize + 1);
    }
}

int lst(int val) {
    int rk = Rank(val);
    if (rk == 1) return 1;
    else return kth(Root, rk - 1) + 1;
}

int nxt(int val) {
    int rk = Rank(val);
    if (rk == num) return n;
    else return kth(Root, rk + 1) - 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].num = i;
    }
    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        int l = 1, r = n;
        insert(a[i].num);
        l = lst(a[i].num);
        r = nxt(a[i].num);
        ans += (r - a[i].num + 1) * (a[i].num - l + 1) * a[i].val;
    }

    Root = 0;
    num = 0;
    for (int i = n; i >= 1; i--) {
        int l = 1, r = n;
        insert(a[i].num);
        l = lst(a[i].num);
        r = nxt(a[i].num);
        ans -= (r - a[i].num + 1) * (a[i].num - l + 1) * a[i].val;
    }

    cout << ans;
    return 0;
}
