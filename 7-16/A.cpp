#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int T, P;
void solve()
{
    int A, B;
    cin >> A >> B; // A=x+y,B=x&y
    int C = A - 2 * B;
    if (C <= 0 || C & B)
    {
        cout << "0" << endl;
        return;
    }
    int p = 0, cnt = 0;
    for (int i = 0; i <= 60; i++)
        if (C & (1ll << i))
            p = i, cnt++;
    cout << ((1ll << p) % P) * ((1ll << (cnt - 1)) % P) % P << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> P;
    while (T--)
        solve();
    return 0;
}
/*
5 992362009
248232552654965455 563160474979616
553521216364206023 14357560845404368
668113789984338832 146840018434951169
620025528908068087 506797735136774536
522926854352266209 860580850297773973

3 23
8 1
10 4
6 0

001,111.   011,101.
110

100
10

1000


10 4

100,110
010
10

6,0
110
100
10

*/