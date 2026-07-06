#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 3e6 + 10;
int n, m, head[N], tot = 0, dfn[N], low[N], num = 0;
int col[N], cnt = 0,stk[N],sc=0;
struct node
{
    int to, next;
} e[N * 2];
void add(int x, int y)
{
    e[++tot] = (node){y, head[x]};
    head[x] = tot;
}
void tarjan(int x)
{
    dfn[x] = low[x] = ++num;
    stk[sc++]=x;
    for (int i = head[x]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!dfn[v])
            tarjan(v), low[x] = min(low[x], low[v]);
        else if (!col[v])
            low[x] = min(low[x], dfn[v]);
    }
    if (dfn[x] == low[x])
    {
        ++cnt;
        while (1)
        {
            int t=stk[--sc];
            col[t] = cnt;
            if (t == x)
                break;
        }
    }
}
bool TwoSAT()
{
    for(int i=1;i<=2*n;i++)
        if(!dfn[i])tarjan(i);
    // for(int i=1;i<=2*n;i++)
    //     cout<<col[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
        if(col[i]==col[i+n])
            return false;
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, vx, y, vy;
        cin >> x >> vx >> y >> vy;
        add(x + (vx ^ 1) * n, y + vy * n);
        add(y + (vy ^ 1) * n, x + vx * n);
    }
    if(TwoSAT())
    {
        cout<<"POSSIBLE"<<endl;
        for(int i=1;i<=n;i++)
            cout<<(col[i+n]<col[i])<<" ";
        cout<<endl;
        return 0;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}