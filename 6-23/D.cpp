#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N = 5e5 + 10;
int n, q, a[N],c[65][N];
vector<int> b[65],d[65];
void solve1()
{
    for (int i = 1; i <= 60; i++)
    {
        int lst = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] & (1ll << (i - 1)))
            {
                if(lst<j-1)
                    b[i].push_back(lst+1),
                    d[i].push_back(j-1);
                lst = j;
            }
        }
    }
    for(int i=1;i<=60;i++)
        for(int j=0;j<(int)b[i].size();j++)
            c[i][j+1]=c[i][j]+(d[i][j]-b[i][j]+1)*(d[i][j]-b[i][j]+2)/2;
    while(q--)
    {
        int op,ans=0;
        cin >> op;
        if(op==1)
            continue;
        if(op==2)
        {
            int l,r;
            cin>>l>>r;
            for(int i=1;i<=60;i++)
            {
                int res=(r-l+1)*(r-l+2)/2;
                int pl=lower_bound(b[i].begin(),b[i].end(),l)-b[i].begin()+1;
                int pr=upper_bound(d[i].begin(),d[i].end(),r)-d[i].begin()+1;
                if(pl<=pr-1)res-=c[i][pr-1]-c[i][pl-1];
                if(b[i][pl-1]<=l&&l<=d[i][pl-1])res-=(d[i][pl-1]-l+1+1)*(d[i][pl-1]-l+1)/2;
                if(b[i][pr-2]<=r&&r<=d[i][pr-2])res-=(r-b[i][pr-2]+1+1)*(r-b[i][pr-2]+1)/2;
                if(res&1)ans|=(1ll<<(i-1));
            }
            cout<<ans<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n > 5000)
    {
        solve1();
        return 0;
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            for (int i = l; i <= r; i++)
                a[i] ^= x;
        }
        if (op == 2)
        {
            int l, r, ans = 0;
            cin >> l >> r;
            for (int i = 1; i <= 60; i++)
            {
                int lst = l - 1, res = (r - l + 1 + 1) * (r - l + 1) / 2;
                for (int j = l; j <= r; j++)
                {
                    if (a[j] & (1ll << (i - 1)))
                    {
                        res -= (j - lst - 1 + 1) * (j - lst - 1) / 2;
                        lst = j;
                    }
                }
                res -= (r + 1 - lst - 1 + 1) * (r + 1 - lst - 1) / 2;
                if (res & 1)
                    ans |= (1ll << (i - 1));
            }
            cout << ans << endl;
        }
    }
    return 0;
}
/*
5 5
0 6 7 2 6
2 1 1
2 2 4
2 1 1
1 1 5 2
2 2 3
*/