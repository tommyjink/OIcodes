#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Node {
    int mask, val;
} seq[1<<20];
int cnt;

void vv(const string& sub, int k) {
    cnt = 0;
    int m = sub.size();
    for (int mask = 1; mask < (1 << m); ++mask) {
        if (__builtin_popcount(mask) != k) continue;
        int val = 0;
        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                val = (val << 1) | (sub[i] - '0');
            }
        }
        seq[cnt].mask = mask;
        seq[cnt].val = val;
        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        int m = r - l + 1;
        string sub = s.substr(l, m);

        vv(sub, k);
        int max_xor = 0;

        for (int i = 0; i < cnt; ++i) {
            for (int j = i + 1; j < cnt; ++j) {
                if ((seq[i].mask & seq[j].mask) == 0) {
                    max_xor = max(max_xor, seq[i].val ^ seq[j].val);
                }
            }
        }

        cout << (max_xor % MOD) << '\n';
    }

    return 0;
}

/*

10 5
0101001111
1 10 5
1 4 2
4 10 3
1 6 3
7 10 2


*/