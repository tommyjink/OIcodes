#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 110, P = 1e9 + 7;
int n, X, t[N], f[N], sum = 1;
struct node
{
    int m[N][N];
} A, B;
node operator*(node x, node y)
{
    node res;
    memset(res.m, 0, sizeof(res.m));
    for (int i = 1; i <= 105; i++)
        for (int j = 1; j <= 105; j++)
            for (int k = 1; k <= 105; k++)
                res.m[i][j] = (res.m[i][j] + x.m[i][k] * y.m[k][j] % P) % P;
    return res;
}
node qpow(node xx, int y)
{
    node res, x = xx;
    memset(res.m, 0, sizeof(res.m));
    for (int i = 1; i <= 105; i++)
        res.m[i][i] = 1;
    while (y)
    {
        if (y & 1)
            res = res * x;
        y >>= 1;
        x = x * x;
    }
    return res;
}
void print(node x)
{
    for (int i = 1; i <= 101; i++)
    {
        for (int j = 1; j <= 101; j++)
            cout << x.m[i][j] << " ";
        cout << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(A.m, 0, sizeof(A.m));
    memset(B.m, 0, sizeof(B.m));
    cin >> n >> X;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        t[x]++;
    }
    f[0] = 1;
    for (int i = 1; i <= min(X, 100ll); i++)
    {
        for (int j = 1; j <= i; j++)
            f[i] = (f[i] + f[i - j] * t[j]) % P;
        sum = (sum + f[i]) % P;
    }
    for (int i = 0; i <= 99; i++)
        A.m[i + 1][1] = f[i];
    A.m[101][1] = f[0];
    for (int i = 1; i <= 99; i++)
        B.m[i][i + 1] = 1;
    for (int i = 1; i <= 100; i++)
        B.m[100][i] = t[100-i+1];
    B.m[101][2] = B.m[101][101] = 1;
    // print(B*B*A);
    A = qpow(B, X) * A;
    cout << A.m[101][1] << endl;
    return 0;
}
/*

10 100000
1 2 3 4 5 6 7 8 9 10
*/