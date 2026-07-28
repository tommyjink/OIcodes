#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4010,mod=998244353;
int m,n,k,ans;
int x[N],y[N],col[N];
bitset<N> g[N];

void dfs(int u)
{
    if(u>n)
    {
        ans++;
        if(ans>=mod)ans-=mod;
        return;
    }
    for(int i=1;i<=m;i++)
    {
        bool fl=true;
        for(int j=1;j<u;j++)
            if(g[u][j]&&col[j]==i)
            {
                fl=false;
                break;
            }
        if(fl)
        {
            col[u]=i;
            dfs(u+1);
            col[u]=0;
        }
    }
}

void solve1()
{
    ans=1;
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(!col[i])
        {
            ans=ans*2%mod;
            col[i]=1;
            q.push(i);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int v=1;v<=n;v++)
                    if(g[u][v])
                    {
                        if(!col[v])
                        {
                            col[v]=3-col[u];
                            q.push(v);
                        }
                        else if(col[v]==col[u])
                        {
                            cout<<0<<endl;
                            return;
                        }
                    }
            }
        }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("history.in","r",stdin);
    freopen("history.out","w",stdout);
    cin>>m>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(abs(x[i]-x[j])>k||abs(y[i]-y[j])>k)
                g[i][j]=g[j][i]=1;
    if(n<=14)
    {
        dfs(1);
        cout<<ans<<endl;
    }
    else if(m==2)solve1();
    else cout<<0<<endl;
    return 0;
}
