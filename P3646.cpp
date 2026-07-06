
#include <bits/stdc++.h>
using namespace std;
#define N 2200
#define inf 0x7f7f7f7f
typedef long long ll;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

int n, A, B, a[N];
ll sum, s[N];
bool f[N][N];
int g[N];

void dp1() {
    int kk = log2(sum); ll tmp = 0;
    for (int p = 1; p <= kk + 1; ++p) {
        memset(f, 0, sizeof(f)); tmp += 1LL << (kk - p + 1);
        for (int i = 1; i <= n; ++i) if (!(s[i] & tmp)) f[i][1] = 1;
        bool flag = 0;
        for (int j = 2; j <= B; ++j) {
            for (int i = j; i <= n; ++i) {
                for (int k = j - 1; k < i; ++k) {
                    if (!((s[i] - s[k]) & tmp) && f[k][j - 1]) f[i][j] = 1;
                }
            }
            if (j >= A && j <= B) if (!flag && f[n][j]) flag = 1;
        }
        if (f[n][1]) flag = 1;
        if (!flag) tmp -= 1LL << (kk - p + 1);
    }
    printf("%lld", (1LL << (kk + 1)) - tmp - 1);
}

void dp2() {
    int kk = log2(sum); ll tmp = 0;
    for (int p = 1; p <= kk + 1; ++p) {
        for (int i = 1; i <= n; ++i) g[i] = inf;
        tmp += 1LL << (kk - p + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!((s[i] - s[j]) & tmp)) {
                    g[i] = min(g[i], g[j] + 1);
                }
            }
        }
        if (g[n] > B) tmp -= 1LL << (kk - p + 1);
    }
    printf("%lld", (1LL << (kk + 1)) - tmp - 1);
}

int main() {
    n = read(); A = read(); B = read();
    for (int i = 1; i <= n; ++i) a[i] = read(), sum += a[i];
    if (!sum) { puts("0"); return 0; }
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    if (A != 1) dp1(); else dp2();
    return 0;
}
