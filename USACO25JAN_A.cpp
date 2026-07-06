#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
vector<int> A, B, P, Q;
vector<vector<int> > D;
vector<vector<int> > S;
ll ans = 0;
void init()
{
    for (int i = 1; i <= N; ++i) {
        P[i]=P[i-1];
        if(A[i]==B[i])P[i]++;
    }
    for (int i = N; i >= 1; --i) {
        Q[i] = Q[i + 1];
        if(A[i]==B[i])Q[i]++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N + 1);
    B.resize(N + 1);
    D.resize(N + 1);
    P.resize(N + 1);
    Q.resize(N + 2);
    S.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> B[i];
        D[B[i]].push_back(i);
    }

    init();

    for (int i = 1; i <= N; ++i) {
        if (!D[i].empty()) {
            S[i] = D[i];
            for (int j = 1; j < D[i].size(); ++j) {
                S[i][j] += S[i][j - 1];
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (D[A[i]].empty()) continue;

        int m = D[A[i]].size();
        int idx1 = lower_bound(D[A[i]].begin(), D[A[i]].end(), i) - D[A[i]].begin();

        ll part1 = (m - idx1) * i;
        if (idx1 > 0) {
            part1 += S[A[i]][idx1 - 1];
        }

        int idx2 = upper_bound(D[A[i]].begin(), D[A[i]].end(), N - i + 1) - D[A[i]].begin();

        ll part2 = (m - idx2) * (i - N) + S[A[i]][m - 1] + idx2;
        if (idx2 > 0) {
            part2 -= S[A[i]][idx2 - 1];
        }

        ll part3 = m;
        ll tmp = part1 - part2 + part3;
        ans += tmp;
    }

    for (int i = 1; i <= N; ++i) {
        ll add1 = (N - i) * P[i];
        ll add2 = (i - 1) * Q[i];
        ans += add1 + add2;
    }

    cout << ans << '\n';
    return 0;
}