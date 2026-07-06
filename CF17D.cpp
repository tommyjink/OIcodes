#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int M = 25;
int n, m, P, nxt[M], g[M][M];
string A;
struct node
{
    int m[M][M];
} G, a;
node operator*(node x, node y)
{
    node res;
    memset(res.m, 0, sizeof(res.m));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < M; k++)
                res.m[i][j] = (res.m[i][j] + x.m[i][k]%P * y.m[k][j]%P)%P;
    return res;
}
node qpow(node x, int y)
{
    node res;
    memset(res.m,0,sizeof(res.m));
    for (int i = 0; i < M; i++)
        res.m[i][i] = 1;
    while (y)
    {
        if (y & 1)
            res = res * x;
        y >>= 1;
        x = x * x;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> P >> A;
    A = " " + A;
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && A[i] != A[j + 1])
            j = nxt[j];
        if (A[i] == A[j + 1])
            j++;
        nxt[i] = j;
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            int jj = i;
            while (jj && A[jj + 1] != j + '0')
                jj = nxt[jj];
            if (A[jj + 1] == j + '0')
                jj++;
            G.m[i][jj]++;
            // printf("g[%lld][%lld]=%lld\n",i,jj,g[i][jj]);
        }
    }
    for(int i=0;i<=m;i++)
        G.m[m][i]=G.m[i][m]=0;
    a.m[0][0]=1ll;
    a=a*qpow(G,n);
    int ans=0;
    for(int i=0;i<=m-1;i++)
        ans=(ans+a.m[0][i])%P;
    // for(int i=0;i<M;i++)
    // {
    //     for(int j=0;j<M;j++)
    //         cout<<a.m[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<ans<<endl;
    return 0;
}