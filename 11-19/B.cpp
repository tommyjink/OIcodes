#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
void solve()
{
    int qand, qor, qxor, ans = 1;
    cin >> qand >> qor >> qxor;
    for (int i = 0; i <= 60; i++)
    {
        int res=0;
        for (int a = 0; a <= 1; a++)
        {
            for (int b = 0; b <= 1; b++)
            {
                if (qand == -1 || (a & b) == bool(qand & (1ll << i)))
                    if (qor == -1 || (a | b) == bool(qor & (1ll << i)))
                        if (qxor == -1 || (a ^ b) == bool(qxor & (1ll << i)))
                            res++;
            }
        }
        ans*=res;
        if(ans>1e18)
        {
            cout<<"inf"<<endl;
            return;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    // freopen("bit.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
/*


输入
3
20 1015 995
921 661 -1
-1 375 -1
输出
128
0
2187


*/