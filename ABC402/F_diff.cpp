#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll mod;
ll a[25][25];
ll n10[45];

ll ans = 0; // 答案

set<ll> st; // 存第一部分搜到的所有走法贡献

// 折半查找 往左上角走（倒着走）
void dfs1(int x, int y, ll sum)
{
    if(x == 1 && y == 1) // 到达 (1, 1)，记录这种方案的贡献
    {
        st.insert(sum);
        return;
    }
    if(x > 1) // 往上走
        dfs1(x - 1, y, (sum + a[x - 1][y]) % mod);
    if(y > 1) // 往左走
        dfs1(x, y - 1, (sum + a[x][y - 1]) % mod);
}

// 折半查找 往右下角走
void dfs2(int x, int y, ll sum)
{
    if(x == n && y == n) // 到达 (n, n)，分类讨论求最大答案 
    {
        auto it = st.lower_bound(mod - sum); // 第一种情况，先二分找 >= mod-sum 的最小值
        if(it != st.begin())
        {
            it--; // 想要的数字是 <mod-sum 的最大值，所以要获得前一个位置，指针左移
            ans = max(ans, sum + (*it));
        }
        it = --st.end(); // 第二种情况，取 set 内的最大值，直接取 set 的尾指针前一个位置
        ans = max(ans, (sum + (*it)) % mod);
        return;
    }
    if(x < n) // 往下走
        dfs2(x + 1, y, (sum + a[x + 1][y]) % mod);
    if(y < n) // 往右走
        dfs2(x, y + 1, (sum + a[x][y + 1]) % mod);
}

int main()
{
    freopen("test.in","r",stdin);
    freopen("test2.out","w",stdout);
    cin >> n >> mod;
    
    n10[0] = 1;
    for(int i = 1; i <= 2 * n; i++)
        n10[i] = n10[i - 1] * 10 % mod; // n10[i] 存 10^i % mod 的结果
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            int pw = 2 * n - (i + j); // 走到右下角还有多少步
            a[i][j] = a[i][j] * n10[pw] % mod; // a[i][j] 改为该位置对答案的贡献
        }
    
    for(int i = 1; i <= n; i++)
    {
        // 枚举主对角线上的每一个位置 (i, n-i+1)
        // 假设当前方案一定会经过这个格子
        int j = n - i + 1;
        st.clear(); // 清空集合
        dfs1(i, j, a[i][j]); // 第一部分，搜索左上角到该位置的所有方案，a[i][j] 放任意一边均可
        dfs2(i, j, 0); // 第二部分，搜索该位置到右下角的所有方案
    }
    
    cout << ans;
    
    return 0;
}