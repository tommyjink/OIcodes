#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e6 + 10;
int n, m, nxt[N];
string s;
void solve()
{
    cin >> n >> m >> s;
    for (int i = 0; i <= 2 * m; i++)
        nxt[i] = 0;
    if (n == 0)
    {
        cout << "-1" << endl;
        return;
    }
    else if (n == 1)
    {
        s = " " + s;
        for (int i = 2, j = 0; i <= m; i++)
        {
            while (j && s[i] != s[j + 1])
                j = nxt[j];
            if (s[i] == s[j + 1])
                j++;
            nxt[i] = j;
        }
        if(nxt[m])cout << nxt[m] << endl;
        else cout<<"-1"<<endl;
        return;
    }
    else
    {
        s = " " + s + s;
        for (int i = 2, j = 0; i <= 2 * m; i++)
        {
            while (j && s[i] != s[j + 1])
                j = nxt[j];
            if (s[i] == s[j + 1])
                j++;
            nxt[i] = j;
        }
        if((n-2)*m+nxt[2*m]==0)cout<<"-1"<<endl;
        else cout<<(n-2)*m+nxt[2*m]<<endl;
        return;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*

PHTUOTBSJBP PHTUOTBSJBP PHTUOTBSJBP


输入
10
1 3 LKL
2 5 QCOEJ
3 11 PHTUOTBSJBP
4 3 CRN
5 3 XXX
6 10 HTHTHTHTHT
7 5 OVEZO
8 5 DYIDY
9 6 ULTULT
10 4 UUKD


1
5
22
9
14
58
30
35
51
36


HT!HTHTHTHT HTHTHTHTHT HTHTHTHTHT HTHTHTHTHT HTHTHTHTHT HTHTHTHT!HT

HTHTHTHTHT HTHTHTHTHT
58
*/