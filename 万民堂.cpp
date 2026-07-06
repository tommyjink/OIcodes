#include <bits/stdc++.h>
#define int long long
#define MOD 19260817
using namespace std;

struct Matrix {
    vector<vector<int> > mat;
    int n;

    Matrix(int size) : n(size) {
        mat.resize(n, vector<int>(n, 0));
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    vector<int> operator*(const vector<int>& vec) const {
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i] = (result[i] + mat[i][j] * vec[j]) % MOD;
            }
        }
        return result;
    }
};

Matrix matrix_pow(Matrix base, int exp) {
    Matrix result(base.n);
    for (int i = 0; i < base.n; ++i) {
        result.mat[i][i] = 1;
    }
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        exp /= 2;
    }
    return result;
}

int solve(int a, int b, int c, int f1, int f2, int n) {
    if (n == 1) return f1 % MOD;
    if (n == 2) return f2 % MOD;

    Matrix base(3);
    base.mat[0][0] = a;
    base.mat[0][1] = b;
    base.mat[0][2] = c;
    base.mat[1][0] = 1;
    base.mat[2][1] = 1;

    vector<int> initial = {f2, f1, 1};

    Matrix result = matrix_pow(base, n - 2);
    vector<int> fn = result * initial;

    return fn[0];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int a, b, c, f1, f2, n;
        cin >> a >> b >> c >> f1 >> f2 >> n;
        cout << solve(a, b, c, f1, f2, n) << endl;
    }

    return 0;
}