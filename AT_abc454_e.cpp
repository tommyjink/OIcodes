#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, a, b;
    
void solve()
{   
    cin >> n >> a >> b;
    if ((n & 1) || a % 2 == b % 2) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;

    
    int r1 = (a - 1) / 2 * 2 + 1;
    int r2 = r1 + 1;

    
    for (int i = 1; i <= r1 - 1; i++) {
        for (int j = 1; j <= n - 1; j++) {
            if (i & 1) cout << 'R';
            else cout << 'L';
        }
        cout << 'D';
    }

    
    if (a == r1) { 
        
        cout << 'D';
        for (int i = 1; i <= b / 2 - 1; i++) cout << "RURD";
        cout << 'R';
        for (int i = 1; i <= (n - b) / 2; i++) cout << "RURD";
    } else { 
        
        for (int i = 1; i <= (b - 1) / 2; i++) cout << "DRUR";
        cout << 'R';
        for (int i = 1; i <= (n - b - 1) / 2; i++) cout << "DRUR";
        cout << 'D';
    }

    
    for (int i = 1; i <= n - r2; i++) {
        cout << 'D';
        for (int j = 1; j <= n - 1; j++) {
            if (i & 1) cout << 'L';
            else cout << 'R';
        }
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}