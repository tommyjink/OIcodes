#include <bits/stdc++.h>
using namespace std;

using u8 = unsigned char;

const int MOD = 998244353;
const int G = 3;
const long long LIM = 200000;

int qpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return (int)r;
}

int ceil_pow2(int n) {
    int x = 0;
    while ((1 << x) < n) x++;
    return x;
}

int bsf(unsigned int x) {
    return __builtin_ctz(x);
}

void butterfly(vector<int>& a) {
    int n = (int)a.size();
    int h = ceil_pow2(n);

    static bool first = true;
    static int sum_e[30];

    if (first) {
        first = false;

        int es[30], ies[30];
        int cnt2 = bsf(MOD - 1);

        int e = qpow(G, (MOD - 1) >> cnt2);
        int ie = qpow(e, MOD - 2);

        for (int i = cnt2; i >= 2; i--) {
            es[i - 2] = e;
            ies[i - 2] = ie;
            e = (long long)e * e % MOD;
            ie = (long long)ie * ie % MOD;
        }

        long long now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_e[i] = now * es[i] % MOD;
            now = now * ies[i] % MOD;
        }
    }

    for (int ph = 1; ph <= h; ph++) {
        int w = 1 << (ph - 1);
        int p = 1 << (h - ph);

        long long now = 1;

        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);

            for (int i = 0; i < p; i++) {
                int l = a[offset + i];
                int r = (int)(a[offset + i + p] * now % MOD);

                int x = l + r;
                if (x >= MOD) x -= MOD;

                int y = l - r;
                if (y < 0) y += MOD;

                a[offset + i] = x;
                a[offset + i + p] = y;
            }

            now = now * sum_e[bsf(~(unsigned int)s)] % MOD;
        }
    }
}

void butterfly_inv(vector<int>& a) {
    int n = (int)a.size();
    int h = ceil_pow2(n);

    static bool first = true;
    static int sum_ie[30];

    if (first) {
        first = false;

        int es[30], ies[30];
        int cnt2 = bsf(MOD - 1);

        int e = qpow(G, (MOD - 1) >> cnt2);
        int ie = qpow(e, MOD - 2);

        for (int i = cnt2; i >= 2; i--) {
            es[i - 2] = e;
            ies[i - 2] = ie;
            e = (long long)e * e % MOD;
            ie = (long long)ie * ie % MOD;
        }

        long long now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_ie[i] = now * ies[i] % MOD;
            now = now * es[i] % MOD;
        }
    }

    for (int ph = h; ph >= 1; ph--) {
        int w = 1 << (ph - 1);
        int p = 1 << (h - ph);

        long long inow = 1;

        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);

            for (int i = 0; i < p; i++) {
                int l = a[offset + i];
                int r = a[offset + i + p];

                int x = l + r;
                if (x >= MOD) x -= MOD;

                int y = l - r;
                if (y < 0) y += MOD;

                a[offset + i] = x;
                a[offset + i + p] = (int)(y * inow % MOD);
            }

            inow = inow * sum_ie[bsf(~(unsigned int)s)] % MOD;
        }
    }
}

vector<int> conv(vector<int> a, vector<int> b) {
    int need = (int)a.size() + (int)b.size() - 1;
    int z = 1;
    while (z < need) z <<= 1;

    a.resize(z);
    b.resize(z);

    butterfly(a);
    butterfly(b);

    for (int i = 0; i < z; i++) {
        a[i] = (int)((long long)a[i] * b[i] % MOD);
    }

    butterfly_inv(a);

    int iz = qpow(z, MOD - 2);
    a.resize(need);

    for (int& x : a) {
        x = (int)((long long)x * iz % MOD);
    }

    return a;
}

u8 cm[4][4];

vector<u8> mul(const vector<u8>& A, const vector<u8>& B) {
    int n = (int)A.size();
    int m = (int)B.size();

    if (n == 1 && A[0] == 1) return B;
    if (m == 1 && B[0] == 1) return A;

    vector<u8> C(n + m - 1, 0);

    if (1LL * n * m <= LIM) {
        for (int i = 0; i < n; i++) {
            u8 ai = A[i];
            for (int j = 0; j < m; j++) {
                C[i + j] |= cm[ai][B[j]];
            }
        }
        return C;
    }

    vector<int> Ap(n), Am(n), Bp(m), Bm(m);

    for (int i = 0; i < n; i++) {
        int b0 = A[i] & 1;
        int b1 = (A[i] >> 1) & 1;

        Ap[i] = b0 + b1;

        int x = b0 - b1;
        if (x < 0) x += MOD;
        Am[i] = x;
    }

    for (int i = 0; i < m; i++) {
        int b0 = B[i] & 1;
        int b1 = (B[i] >> 1) & 1;

        Bp[i] = b0 + b1;

        int x = b0 - b1;
        if (x < 0) x += MOD;
        Bm[i] = x;
    }

    vector<int> T = conv(Ap, Bp);
    vector<int> D = conv(Am, Bm);

    int len = n + m - 1;

    for (int i = 0; i < len; i++) {
        int tv = T[i];
        int dv = D[i];

        if (dv > MOD / 2) dv -= MOD;

        int c0 = (tv + dv) / 2;
        int c1 = (tv - dv) / 2;

        C[i] = (c0 > 0 ? 1 : 0) | (c1 > 0 ? 2 : 0);
    }

    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            u8 r = 0;

            for (int x = 0; x < 2; x++) {
                if (!((a >> x) & 1)) continue;

                for (int y = 0; y < 2; y++) {
                    if ((b >> y) & 1) {
                        r |= (u8)(1 << (x ^ y));
                    }
                }
            }

            cm[a][b] = r;
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1), p(n + 1), sx(n + 1), sz(n + 1, 1);
        vector<vector<int>> ch(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sx[i] = a[i];
        }

        for (int i = 2; i <= n; i++) {
            cin >> p[i];
            ch[p[i]].push_back(i);
        }

        for (int i = n; i >= 2; i--) {
            sz[p[i]] += sz[i];
            sx[p[i]] ^= sx[i];
        }

        vector<vector<u8>> dp(n + 1);

        for (int v = n; v >= 1; v--) {
            vector<u8> cur;

            if (ch[v].empty()) {
                cur.assign(1, 1);
            } else if (ch[v].size() == 1) {
                cur = move(dp[ch[v][0]]);
            } else {
                vector<vector<u8>> pool;
                pool.reserve(ch[v].size() * 2);

                priority_queue<
                    pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>
                > pq;

                for (int u : ch[v]) {
                    int id = (int)pool.size();
                    pool.push_back(move(dp[u]));
                    pq.push({(int)pool[id].size(), id});
                }

                while (pq.size() > 1) {
                    auto [s1, i1] = pq.top();
                    pq.pop();

                    auto [s2, i2] = pq.top();
                    pq.pop();

                    vector<u8> prod = mul(pool[i1], pool[i2]);

                    vector<u8>().swap(pool[i1]);
                    vector<u8>().swap(pool[i2]);

                    int id = (int)pool.size();
                    pool.push_back(move(prod));
                    pq.push({(int)pool[id].size(), id});
                }

                cur = move(pool[pq.top().second]);
            }

            cur.push_back((u8)(1 << sx[v]));
            dp[v] = move(cur);
        }

        for (int k = 1; k <= n; k++) {
            u8 mask = dp[1][k];

            int ans;
            if (mask == 1) ans = 0;
            else if (mask == 2) ans = 1;
            else ans = 2;

            cout << ans << " \n"[k == n];
        }
    }

    return 0;
}