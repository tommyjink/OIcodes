#include <bits/stdc++.h>
#define int long long
#define pii pair<int, string>
#define endl "\n"
using namespace std;
int n, m, k, tot = 0, cnt = 0;
vector<pii> ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    if (k > 4 * n * m - 2 * n - 2 * m)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if(m==1)
    {
        if(tot+n-1<=k)
        {
            tot+=n-1;
            ans.push_back(pii(n-1,"D"));
        }
        else if(tot<k)ans.push_back(pii(k-tot,"D")),tot=k;
        if(tot+n-1<=k)
        {
            tot+=n-1;
            ans.push_back(pii(n-1,"U"));
        }
        else if(tot<k)ans.push_back(pii(k-tot,"U")),tot=k;
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i.first << " " << i.second << endl;
        return 0;
    }
    for (cnt = 1; cnt <= n - 1; cnt++)
    {
        if (tot + (m - 1) * 4 + 1 > k)
            break;
        tot += (m - 1) * 4 + 1;
        ans.push_back(pii(m - 1, "RDU"));
        ans.push_back(pii(m - 1, "L"));
        ans.push_back(pii(1, "D"));
    }
    if(cnt<n)
    {
        for(int i=1;i<=m-1;i++)
        {
            if(tot+3>k)
            {
                if(tot+1>k)break;
                tot++;
                ans.push_back(pii(1,"R"));
                break;
            }
            tot+=3;
            ans.push_back(pii(1,"RDU"));
        }
        for(int i=1;i<=m-1;i++)
        {
            if(tot+1>k)break;
            tot++;
            ans.push_back(pii(1,"L"));
        }
    }
    else
    {
        for(int i=1;i<=m-1;i++)
        {
            if(tot+1>k)break;
            tot++;
            ans.push_back(pii(1,"R"));
        }
        for(int i=1;i<=m-1;i++)
        {
            if(tot+1>k)break;
            tot++;
            ans.push_back(pii(1,"L"));
        }
        if (tot < k)
            ans.push_back(pii(k - tot, "U"));
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;
    return 0;
}