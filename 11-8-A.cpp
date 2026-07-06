#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXM = 5005;

int n, m;
int f[2][MAXM], g[2][MAXM];
int fuPoly[MAXM], guPoly[MAXM];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m; i++) {
        scanf("%d", &f[0][i]);
    }
    for (int i = 0; i <= m; i++) {
        scanf("%d", &g[0][i]);
    }
    
    int cur = 0;
    for (int t = 1; t <= n; t++) {
        int nxt = cur ^ 1;
        for (int i = 0; i <= m; i++) {
            f[nxt][i] = g[cur][i];
            if (i < m) {
                f[nxt][i] = (f[nxt][i] + 1LL * (i + 1) * g[cur][i + 1]) % MOD;
            }
            
            g[nxt][i] = f[cur][i];
            if (i < m) {
                g[nxt][i] = (g[nxt][i] - 1LL * (i + 1) * f[cur][i + 1] % MOD + MOD) % MOD;
            }
        }
        cur = nxt;
    }
    
    for (int i = 0; i <= m; i++) {
        printf("%d ", f[cur][i]);
    }
    printf("\n");
    for (int i = 0; i <= m; i++) {
        printf("%d ", g[cur][i]);
    }
    printf("\n");
    
    return 0;
}