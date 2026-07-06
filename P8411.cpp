#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef unsigned int uint;
inline uint get_next(uint &seed)
{
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed;
}
const int N = 1e7 + 10;
uint seed;
long long n, in[N], head[N], tot = 0, ans,now,a[N];
struct node1
{
    int from, to, next;
} e[N];
void add(int x, int y)
{
    e[++tot] = (node1){x, y, head[x]};
    head[x] = tot;
}
struct node
{
    long long num, val;
};
bool operator<(node x, node y)
{
    return x.val < y.val;
}
priority_queue<node> q;
void topo()
{
    ans=now=a[1];
    for (int i = head[1]; i; i = e[i].next)
    {
        int v = e[i].to;
        in[v]--;
        if(in[v]==0)
            q.push((node){v,a[v]});
    }
    while(!q.empty())
    {
        node t=q.top();q.pop();
        now=min(now,t.val);
        ans+=now;
        for(int i=head[t.num];i;i=e[i].next)
        {
            int v=e[i].to;
            in[v]--;
            if(in[v]==0)
                q.push((node){v,a[v]});
        }
    }

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> seed;
    for (int i = 1; i <= n; i++)
    {
        a[i] = get_next(seed);
    }
    for (int i = 2; i <= n; i++)
    {
        int x = get_next(seed) % (i - 1) + 1;
        add(x, i), in[i]++;
    }
    topo();
    cout<<ans<<endl;
    return 0;
}