
#include <cstdio>
using namespace std;
const int MOD = 1e9 + 7, INV = 500000004;
int l, r;
struct mat {
    long long a[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,1,0,0},
        {0,0,0,0,0,1,0,1,0,0},
        {0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,1,0,1,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0},
        {0,1,2,1,2,2,2,2,2,1}
    };
};
mat operator * (mat x, mat y) {
    mat res;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++) {
            res.a[i][j] = 0;
            for (int k = 1; k <= 9; k++) res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j] % MOD) % MOD;
        }
    return res;
}
mat qpow(mat res, int p) {
    mat x;
    while (p) {
        if (p & 1) res = x * res;
        x = x * x;
        p >>= 1;
    }
    return res;
}
long long getAns(int x) {
    if (x == 0) return 0;
    if (x == 1) return 4;
    mat ans;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            ans.a[i][j] = 0;
    for (int i = 1; i <= 8; i++) ans.a[i][1] = 1;
    ans.a[9][1] = 12;
    ans = qpow(ans, x - 2);
    return ans.a[9][1];
}
int main() {
    scanf("%d%d", &l, &r);
    long long suml = (getAns(l - 1) + getAns(l / 2)) % MOD * INV % MOD;
    long long sumr = (getAns(r) + getAns((r + 1) / 2)) % MOD * INV % MOD;
    printf("%lld\n", (sumr - suml + MOD) % MOD);
    return 0;
}
