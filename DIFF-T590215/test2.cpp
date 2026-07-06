#include <bits/stdc++.h>
using namespace std;

const int inf = 3e6 + 5;
int n, m, k, v;
int sum[1005][1005];
int vis[1005][1005];
int d[2][2] = {{0, 1}, {1, 0}};
vector<int> current_path, best_path;
int min_ans = INT_MAX;
int current_num, current_all;
int xz(const vector<int>& path) {
    int n = path.size();
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        if (path[(i + k) % n] == path[(j + k) % n]) k++;
        else {
            if (path[(i + k) % n] > path[(j + k) % n]) i += k + 1;
            else j += k + 1;
            if (i == j) i++;
            k = 0;
        }
    }
    return min(i, j);
}

void dfs(int x, int y) {
    if (x == n && y == m) {
        if (current_num == 0) return; 
        int ans = current_all / current_num;
        if (ans < min_ans || (ans == min_ans && current_path < best_path)) {
            min_ans = ans;
            best_path = current_path;
        }
        return;
    }

    for (int i = 0; i < 2; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny]) {
            vis[nx][ny] = 1;
            int prev_num = current_num;
            int prev_all = current_all;
            int gain = sum[nx][ny] / k;
            current_num += gain;
            current_all -= gain;
            int put = current_num / v;
            current_num -= put;
            current_all += put;

            current_path.push_back(sum[nx][ny]);
            dfs(nx, ny);
            current_path.pop_back();
            current_num = prev_num;
            current_all = prev_all;
            vis[nx][ny] = 0;
        }
    }
}

int main() {
    freopen("test.in","r",stdin);
    freopen("test2.out","w",stdout);
    cin >> n >> m >> k >> v;
    int total = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> sum[i][j];
            total += sum[i][j];
        }
    vis[1][1] = 1;
    current_num = sum[1][1] / k;
    current_all = total - sum[1][1] / k;
    int put = current_num / v;
    current_num -= put;
    current_all += put;

    current_path.push_back(sum[1][1]);
    dfs(1, 1);
    cout<<min_ans<<endl;
    if (!best_path.empty()) {
        int start = xz(best_path);
        for (int i = 0; i < best_path.size(); ++i) {
            cout << best_path[(start + i) % best_path.size()] << " ";
        }
    }
    return 0;
}