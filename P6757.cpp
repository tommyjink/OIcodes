#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 4e3 + 10;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n, m, a[N][N], ans = 0;
struct node
{
    int x, y;
};
queue<node> q[3];
void bfs()
{
    int now = a[1][1];
    a[1][1] = 0;
    q[now].push((node){1, 1});
    while (!(q[1].empty() && q[2].empty()))
    {
        ans++;
        while (!q[now].empty())
        {
            node t = q[now].front();
            q[now].pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = t.x + dx[i];
                int yy = t.y + dy[i];
                if (!a[xx][yy])
                    continue;
                q[a[xx][yy]].push((node){xx, yy});
                a[xx][yy] = 0;
            }
        }
        now = (now == 1 ? 2 : 1);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            if (s[j - 1] == 'F')
                a[i][j] = 1;
            if (s[j - 1] == 'R')
                a[i][j] = 2;
        }
    }
    bfs();
    cout << ans << endl;
    return 0;
}
/*
5 6
FFRFRF
RFFRFR
FRFFRF
RFRFFR
FRFRFF

RRRFRF
RRRRFR
FRRRRF
RFRRRR
FRFRRR

FFFFRF
FFFFFR
FFFFFF
RFFFFF
FRFFFF

RRRRRF
RRRRRR
RRRRRR
RRRRRR
FRRRRR

FFFFFF
FFFFFF
FFFFFF
FFFFFF
FFFFFF
*/