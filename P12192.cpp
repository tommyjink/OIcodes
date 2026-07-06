#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, a[1000000],tot=0;
signed main()
{
    memset(a,127,sizeof(a));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int t = 2;
    while (t--)
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            a[i] = min(a[i], x);
        }
    for(int i=1;i<=n;i++)
       tot+=a[i];
    cout<<tot<<endl; 
    return 0;
}