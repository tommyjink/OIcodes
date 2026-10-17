#include<bits/stdc++.h>
#define endl "\n"
#define pop(x) __builtin_popcount(x)
using namespace std;
const int N=1e5+10,M=1025;
int n,a[N],best[M][M][11],f[N],k[N];
int lst[N];
int H(int x)
{
    return x>>10;
}
int L(int x)
{
    return x&((1ll<<10)-1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>k[i];
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        for(int h=0;h<1ll<<10;h++)
        {
            int need=k[i]-pop(h&H(a[i]));
            if(need<0||need>10)continue;
            int tmp=f[best[h][L(a[i])][k[i]-pop(h&H(a[i]))]]+1;
            if(tmp>f[i])
            {
                f[i]=tmp;
                lst[i]=best[h][L(a[i])][k[i]-pop(h&H(a[i]))];
            }
        }
        for(int y=0;y<1ll<<10;y++)
        {
            if(f[i]>f[best[H(a[i])][y][pop(L(a[i]&y))]])
                best[H(a[i])][y][pop(L(a[i]&y))]=i;
        }
    }
    int now=n;
    for(int i=1;i<=n;i++)
        if(f[i]>=f[now])now=i;
    cout<<f[now]<<endl;
    vector<int> ans;
    while(now)
    {
        ans.push_back(now);
        now=lst[now];
    }
    reverse(ans.begin(),ans.end());
    for(int i:ans)cout<<i<<" ";
    return 0;
}