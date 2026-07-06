#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, k, cnt = 0;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o' && i < n - 1)
            s[i + 1] = '.';
        if (s[i + 1] == 'o')
            s[i] = '.';
        if (s[i] == 'o')
            k--;
    }
    for (int i = 0; i < n;)
    {
        if (s[i] != '?')
        {
            i++;
            continue;
        }
        int l = i;
        while (s[i] == '?' && i < n)
            i++;
        cnt += (i - l + 1) / 2;
    }
    // cout<<s<<endl;
    if (cnt == k)
    {
        for (int i = 0; i < n;)
        {
            if (s[i] != '?')
            {
                i++;
                continue;
            }
            int l = i;
            while (s[i] == '?' && i < n)
                i++;
            // cout<<l<<" "<<i<<endl;
            int t = (i - l);
            // cout<<t<<endl;
            if (t % 2 == 1)
                for (int j = l; j < i; j++)
                {
                    if ((j - l) & 1)
                        s[j] = '.';
                    else
                        s[j] = 'o';
                }
        }
    }
    if(!k)
        for(int i=0;i<n;i++)
            s[i]=(s[i]=='?'?'.':s[i]);
    cout << s << endl;
    return 0;
}