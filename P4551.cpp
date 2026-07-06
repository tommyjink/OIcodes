#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 5;
int n, head[N], tot,a[N],ch[N][2],cnt=1,ans;
struct node
{
    int to, next, val;
} e[N * 2];
void add(int x, int y, int val = 0)
{
    e[++tot].to = y;
    e[tot].next = head[x];
    e[tot].val = val;
    head[x] = tot;
}
void insert(int x)
{
    int u=1;
    for(int i=30;i>=0;i--)
    {
        int t=(x>>i)&1ll;
        if(!ch[u][t])ch[u][t]=++cnt;
        u=ch[u][t];
    }
}
int get(int x)
{
    int u=1,res=0;
    for(int i=30;i>=0;i--)
    {
        int t=(x>>i)&1ll;
        if(ch[u][t^1])
        {
            res|=(1ll<<i);
            u=ch[u][t^1];
        }
        else
            u=ch[u][t];
    }
    return res;
}
void dfs(int x, int fa)
{
    insert(a[x]);
    ans=max(ans,get(a[x]));
    for (int i = head[x]; i; i = e[i].next)
    {
        int y = e[i].to;
        if (y == fa)
            continue;
        a[y]=a[x]^e[i].val;
        dfs(y, x);
    }
}
signed main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}