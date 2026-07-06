#include <bits/stdc++.h>
using namespace std;

double ans, total;
int n, x0;
long long sum_v[1010], dp[1010][1010][2];
struct Egg
{
    int x, y, v;
} eggs[1010];

bool cmp_x(Egg a, Egg b)
{
    return a.x < b.x;
}

int main()
{
    cin >> n >> x0;
    for (int i = 1; i <= n; i++)
        cin >> eggs[i].x;
    for (int i = 1; i <= n; i++)
    {
        cin >> eggs[i].y;
        total += eggs[i].y;
    }
    for (int i = 1; i <= n; i++)
        cin >> eggs[i].v;
    sort(eggs + 1, eggs + n + 1, cmp_x);
    for (int i = 1; i <= n; i++)
        sum_v[i] = sum_v[i - 1] + eggs[i].v;
    if (x0 <= eggs[1].x)
    {
        for (int i = 1; i <= n; i++)
            ans += (double)(eggs[i].y - eggs[i].v * (eggs[i].x - x0));
        printf("%.3f", ans / 1000.0);
    }
    else if (x0 >= eggs[n].x)
    {
        for (int i = n; i >= 1; i--)
            ans += (double)(eggs[i].y - eggs[i].v * (x0 - eggs[i].x));
        printf("%.3f", ans / 1000.0);
    }
    else
    {
        float dp1, dp2;
        int left_ = 1, right_ = n, mid_;
        while (left_ < right_ - 1)
        {
            mid_ = (left_ + right_) >> 1;
            if (eggs[mid_].x < x0)
                left_ = mid_;
            else
                right_ = mid_;
        }
        dp[left_][left_][0] = dp[left_][left_][1] = sum_v[n] * (x0 - eggs[left_].x);
        dp[right_][right_][0] = dp[right_][right_][1] = sum_v[n] * (eggs[right_].x - x0);
        for (int i = 1; i <= n; i++)
            if (i != left_ and i != right_)
                dp[i][i][0] = dp[i][i][1] = 1e18;
        for (int length = 1; length <= n - 1; length++)
            for (int i = 1; i <= n - length; i++)
            {
                int j = i + length;
                dp[i][j][0] = min(dp[i + 1][j][0] + (eggs[i + 1].x - eggs[i].x) * (sum_v[n] - sum_v[j] + sum_v[i]),
                                  dp[i + 1][j][1] + (eggs[j].x - eggs[i].x) * (sum_v[n] - sum_v[j] + sum_v[i]));
                dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][0] + (eggs[j].x - eggs[i].x) * (sum_v[n] - sum_v[j - 1] + sum_v[i - 1] + sum_v[n] - sum_v[j] + sum_v[i - 1]));
                dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][1] + (eggs[j].x - eggs[j - 1].x) * (sum_v[n] - sum_v[j - 1] + sum_v[i - 1]) + (eggs[j].x - eggs[i].x) * (sum_v[n] - sum_v[j] + sum_v[i - 1]));
                dp[i][j][1] = min(dp[i + 1][j][0] + (eggs[j].x - eggs[i].x) * (sum_v[n] - sum_v[j] + sum_v[i - 1]) + (eggs[i + 1].x - eggs[i].x) * (sum_v[n] - sum_v[j] + sum_v[i]),
                                  dp[i + 1][j][1] + (eggs[j].x - eggs[i].x) * (sum_v[n] - sum_v[j] + sum_v[i] + sum_v[n] - sum_v[j] + sum_v[i - 1]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + (eggs[j].x - eggs[i].x) * (sum_v[n] - sum_v[j - 1] + sum_v[i - 1]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + (eggs[j].x - eggs[j - 1].x) * (sum_v[n] - sum_v[j - 1] + sum_v[i - 1]));
                // cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
            }
        printf("%.3f", (total - min(dp[1][n][0], dp[1][n][1])) / 1000.0);
    }
    return 0;
}