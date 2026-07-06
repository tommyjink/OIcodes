#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e9;
int g[25][250][250][250];
void solve(string s, int T) {
    int n = s.length();
    s=" "+s;

}
signed main() {
    //freopen("rana.in","r",stdin);
    //freopen("rana.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int T;
    while (cin >> s) {
        cin >> T;
        if (T == -1) break;
        solve(s, T);
    }
    return 0;
}/*
032089
5
333
9
00
-1
*/