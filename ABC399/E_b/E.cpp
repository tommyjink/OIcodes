#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 2;

int n;
string s, t;
int exi[300];
int nxt[N], ans;
int vis[300], mark[300];
int inl[300];
int stk[N], top;

void dfs(int u) {
    vis[u] = mark[u] = 1;
    stk[++top] = u;
    if (nxt[u] && nxt[u] != u) {
        ans++;
        if (!vis[nxt[u]]) dfs(nxt[u]);
        else if (mark[nxt[u]]) {
            int flag = 1;
            for (int i = top; i >= 1; i--) {
                int v = stk[i];
                inl[v] = 1;
                if (v == nxt[u]) break;
            }
            int tar = 0;
            for (int i = top; i >= 1; i--) {
                int v = stk[i];
                for (int j = 'a'; j <= 'z'; j++) if (j != v && !inl[j] && nxt[j] == v) flag = 0;
                tar = i - 1;
                if (v == nxt[u]) break;
            }
            top = tar;
            ans += flag;
        }
    }
    if (stk[top] == u) top--;
    mark[u] = 0;
}

bool check() {
    return s == t;
}

void solve() {
    cin >> n >> s >> t;
    if (check()) {
        cout << "0" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (nxt[s[i]] && nxt[s[i]] != t[i]) {
            cout << "-1" << endl;
            return;
        }
        nxt[s[i]] = t[i];
        exi[s[i]] = 1;
    }
    for (int i = 'a'; i <= 'z'; i++) if (exi[i] && !vis[i]) dfs(i);
    int all_inl = 1;
    for (int i = 'a'; i <= 'z'; i++) all_inl &= inl[i] || i == nxt[i];
    cout << (all_inl ? -1 : ans) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
    return 0;
}