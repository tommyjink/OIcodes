#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int, int>
using namespace std;
const int N = 1e6 + 10;
int n, m, tot = 0, head[N], vis[N],tag[N],vism[N*2];
struct node
{
    int to, next, from;
} e[N * 2];
void init()
{
    for (int i = 1; i <= 2*n; i++)
        head[i] = vis[i] =tag[i]= 0;
    tot = 0;
}
void add(int x, int y)
{
    e[++tot] = (node){y, head[x], x};
    head[x] = tot;
}
bool dfs(int x, int fa, int rt)
{
    // printf("x:%lld,rt:%lld\n",x,rt);
    tag[x]=true;
    for (int i = head[x]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        if (v == rt || (!tag[v]&&dfs(v, x, rt)))
        {
            // cout<<x<<"!UUUUUUU"<<v<<endl;
            vis[x] = true;
            vism[i]=true;
            return true;
        }
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    for (int i = 1; i <= n; i++)
    {
        for(int i=1;i<=tot;i++)
            tag[i]=vis[i]=vism[i]=0;
        if (dfs(i, i, i))
        {
            vector<int> tmp;
            for (int j = head[i]; j; j = e[j].next)
                if (!vis[e[j].to])
                    tmp.push_back(j);
            if (tmp.size() >= 2)
            {
                vism[tmp[0]]=vism[tmp[1]]=true;
                cout << "YES"<< endl;
                vector<int> ans;
                for (int k = 1; k <= tot; k ++)
                    if (vism[k])
                        ans.push_back(k);
                cout << ans.size() << endl;
                for (auto x : ans)
                    cout << e[x].from << " " << e[x].to << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
3
7 8
1 2
2 3
3 4
4 1
4 5
4 6
4 2
6 7


7 7
6 7
1 2
2 3
3 4
4 1
1 3
3 5

4 4
1 3
3 4
4 1
1 2
*/