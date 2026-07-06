#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 5e5 + 10;
int n, a[N * 2], sum[N * 2], tmax = -1e11, tl, tr,ll,rr;
int b[N * 2], tot = 0, cmax = -1e11, c[N * 2], totc = 0, tmin = 1e11;
deque<int> dq;
signed main()
{
    // freopen("test.in","r",stdin);
    // freopen("test1.out","w",stdout);
    // freopen("P1121_4.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i + n] = a[i];
    for (int i = 1; i <= 2 * n; i++)
        sum[i] = sum[i - 1] + a[i];
    for (int i = 0; i <= 2 * n; i++)
    {
        while (!dq.empty() && dq.front() < i - n)
            dq.pop_front();
        if (!dq.empty() && sum[i] - sum[dq.front()] > tmax)
            tmax = sum[i] - sum[dq.front()], tl = dq.front() + 1, tr = i;
        while (!dq.empty() && sum[dq.back()] >= sum[i])
            dq.pop_back();
        dq.push_back(i);
    }
    // cout << tmax << " " << tl << " " << tr << endl;
    for (int i = tl; i <= tr; i++)
        c[++totc] = a[i];
    ll=tl,rr=tr;
    if ((tl > n && tr > n) || (tl <= n && tr <= n))
    {
        if (tl > n)
            tl -= n;
        if (tr > n)
            tr -= n;
        for (int i = tr + 1; i <= n; i++)
            b[++tot] = a[i];
        for (int i = 1; i <= tl - 1; i++)
            b[++tot] = a[i];
    }
    else
    {
        if (tl > n)
            tl -= n;
        if (tr > n)
            tr -= n;
        for (int i = tr + 1; i <= tl - 1; i++)
            b[++tot] = a[i];
    }
    for (int i = 1; i <= tot; i++)
        sum[i] = sum[i - 1] + b[i];
    // for(int i=1;i<=tot;i++)
    //     cout<<sum[i]<<" ";
    // cout<<endl;
    while (!dq.empty())
        dq.pop_back();
    for (int i = 0; i <= tot; i++)
    {
        while (!dq.empty() && dq.front() < i - n)
            dq.pop_front();
        if (!dq.empty() && sum[i] - sum[dq.front()] > cmax)
            cmax = sum[i] - sum[dq.front()];
        while (!dq.empty() && sum[dq.back()] >= sum[i])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int i = 1; i <= totc; i++)
        sum[i] = sum[i - 1] + c[i];
    // cout<<endl;
    while (!dq.empty())
        dq.pop_back();
    for (int i = 0; i <= totc; i++)
    {
        while (!dq.empty() && dq.front() < i - n)
            dq.pop_front();
        if (!dq.empty() && sum[i] - sum[dq.front()] < tmin)
            tmin = sum[i] - sum[dq.front()];
        while (!dq.empty() && sum[dq.back()] <= sum[i])
            dq.pop_back();
        dq.push_back(i);
    }
    // cout<<cmax<<" "<<tmax<<" "<<tl<<" "<<tr<<endl;
    if(rr==ll)
        tmin=1e11;
    if (tot == 0 || (cmax < 0 && tmax > 0 && rr-ll>=1))
        cout << max(tmax,tmax-tmin) << endl;
    else
        cout << max(cmax + tmax,tmax-tmin)<< endl;
    return 0;
}
/*
10
-1 -1 -1 -1 -1 -1 -1 -1 -1 20

10
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1

10
1 2 3 4 5 6 7 8 9 10
*/