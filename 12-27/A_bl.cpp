#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500005;
int a[MAXN];
bool vis[MAXN];

int main() {
    int id, n;
    if (!(cin >> id >> n)) return 0;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int cnt = 0, day = 0;
    while (cnt < n) {
        day++;
        int last_cnt = cnt;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && cnt >= a[i]) {
                vis[i] = true;
                cnt++;
            }
        }
        if (cnt == last_cnt) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << day << endl;
    return 0;
}