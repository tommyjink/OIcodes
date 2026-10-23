#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=20;
int n,a[N],g[N][N],in[N],b[N],c[N];
void dfs(int x,int cnt)
{
    in[x]=1;
    b[cnt]=x;
    c[x]=cnt;
    for(int i=1;i<=n;i++)
    {
        if(!g[x][i])continue;
        if(!in[i])dfs(i,cnt+1);
        else
        {
            
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int p=1;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
            if(a[j]==i)p=j;
        }
        for(int j=1;j<=p;j++)
            g[a[j]][i]=1;
    }
    return 0;
}