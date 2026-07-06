#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int n, a[N], b[N], now = 0, ans = 0,tag[N];
struct node
{
    int w,num;
};
bool operator <(node x,node y)
{
    return x.w<y.w;
}
priority_queue<node> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        now += a[i];
        if (now >= b[i])
        {
            now -= b[i];
            ans++;
            q.push((node){b[i],i});
            tag[i]=true;
        }
        else if (!q.empty()&&b[i] < q.top().w)
        {
            now += q.top().w;
            tag[q.top().num]=false;
            q.pop();
            now -= b[i];
            q.push((node){b[i],i});
            tag[i]=true;
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        if(tag[i])cout<<i<<" "; 
    return 0;
}