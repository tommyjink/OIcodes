#include <bits/stdc++.h>
using namespace std;
const int ksfnrm = 1e6;
int T, n, q;
long long a[300005], pre[300005], pre2[300005];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            pre[i] = pre[i - 1] + a[i];
            pre2[i] = pre2[i - 1] + (a[i] == 0 ? 0 : 1);
        }
        while (q--) {
            // cout<<"!"<<endl;
            int l, r;
            scanf("%d%d", &l, &r);
            long long sum = pre[r] - pre[l - 1];
            long long cnt = pre2[r] - pre2[l - 1];
            if (sum == 0) {
                printf("0\n");
                continue;
            }
            if (cnt == 1) {
                printf("-1\n");
                continue;
            }
            if (cnt == 2) {
                long long mx = 0;
                for (int i = l; i <= r; i++) {
                    if (a[i] > 0) mx = max(mx, a[i]);
                }
                if (mx == 1) printf("-1\n");
                else printf("%lld\n", sum - 1);
                continue;
            }
            printf("%lld\n", sum - cnt + 1);
        }
    }
    return 0;
}