#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e5 + 5;

int n;
int a[MAXN], x[MAXN];
int idx[MAXN];
bool used[MAXN];
vector<pair<int, int>> ans;

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        idx[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        if (x[i] != -1) x[i]--; // 转为0-based
    }
    
    // 按a值从小到大排序
    sort(idx, idx + n, cmp);
    
    ll total = 0;
    int step = 1;
    memset(used, 0, sizeof(used));
    
    for (int i = 0; i < n; ++i) {
        int u = idx[i];
        if (used[u]) continue;
        bool found = false;
        // 尝试匹配比u大的元素
        for (int j = i + 1; j < n; ++j) {
            int v = idx[j];
            if (used[v]) continue;
            if (x[u] == v || x[v] == u) continue; // 跳过禁止对
            // 匹配u和v
            used[u] = used[v] = true;
            total += (ll)a[u] * step; // a[u] < a[v]，min为a[u]
            ans.emplace_back(u + 1, v + 1); // 转回1-based
            step++;
            found = true;
            break;
        }
        if (!found) {
            printf("-1\n");
            return 0;
        }
    }
    
    printf("%lld\n", total);
    for (auto& p : ans) {
        printf("%d %d\n", p.first, p.second);
    }
    return 0;
}