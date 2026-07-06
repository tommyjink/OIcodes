#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=205;


const int INF = 1e16; 

int n,sx,sy,m,k,a[N][N],f[N][N],ans=0;
struct node{int pos,val;};

void solve(int x,int y,int dx,int dy,int len)
{
    int now=0;
    deque<node> q;
    while(x>=1&&x<=n&&y>=1&&y<=m)
    {
        if(a[x][y]) {
            q.clear();
        } else {
            int val = f[x][y] - now;
            while(!q.empty() && val >= q.back().val) q.pop_back();
            q.push_back({now, val});
            while(!q.empty() && q.front().pos < now - len) q.pop_front();
            f[x][y] = q.front().val + now;
            ans = max(ans, f[x][y]);
        }
        x += dx, y += dy, now++;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>sx>>sy>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) 
            f[i][j] = -INF; 
    f[sx][sy] = 0;
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        for(int j=1;j<=m;j++)
            if(s[j-1]=='x')a[i][j]=1;
    }
    for(int i=1;i<=k;i++)
    {
        int l,r,d;
        cin>>l>>r>>d;
        int len = r - l + 1; 
        if(d==1)for(int i=1;i<=m;i++)solve(n,i,-1,0,len);
        if(d==2)for(int i=1;i<=m;i++)solve(1,i,1,0,len);
        if(d==3)for(int i=1;i<=n;i++)solve(i,m,0,-1,len);
        if(d==4)for(int i=1;i<=n;i++)solve(i,1,0,1,len);
    }
    cout<<ans<<endl;
    return 0;
}