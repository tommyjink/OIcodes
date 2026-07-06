#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e3+10;
const int dx[]={1,1,-1,-1};
const int dy[]={1,-1,1,-1};
int n,m,h[N][N],a[N][N];
void bfs()
{
    queue<pii> q;
    for(int i=1;i<=m;i++)
        q.push(pii(1,i)),
        q.push(pii(n,i));
    for(int i=1;i<=n;i++)
        q.push(pii(i,1)),
        q.push(pii(i,m));
    while(!q.empty())
    {
        pii t=q.front();
    }
}   
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>h[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=1e18;
    return 0;
}