#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e3 + 10;
const double eps = 1e-7;
int n;
double a[N][N];
void gauss()
{
    for (int j = 1; j <= n; j++)
    {
        for (int i = j; i <= n; i++)
            if (a[i][j])
            {
                swap(a[i], a[j]);
                break;
            }
        if (fabs(a[j][j]) < eps)
        {
            cout << "No Solution";
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == j)
                continue;
            double t = a[i][j] / a[j][j];
            for (int k = 1; k <= n + 1; k++)
                a[i][k] -= a[j][k] * t;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%.2lf\n",a[i][n + 1] / a[i][i]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            cin >> a[i][j];
    gauss();
    return 0;
}