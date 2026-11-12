#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=10,M=23,mod=998244353;
int n,m,w[M],p[N],a[N][M];
void solve3()
{
    unordered_map<int,int> f,g;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    int st=0,ed=0;
    for(int i=1;i<=n;i++)
    {
        st|=(i-1)<<(3*(i-1));
        ed|=(p[i]-1)<<(3*(i-1));
    }
    f[st]=0;g[st]=1;q.push({0,st});
    while(!q.empty())
    {
        int dis=q.top().first,s=q.top().second;
        q.pop();
        if(dis!=f[s])continue;
        if(s==ed)
        {
            cout<<dis<<" "<<g[s]<<endl;
            return;
        }
        for(int j=1;j<=m;j++)
        {
            int t=0,k=0;
            for(int v=0;v<=1;v++)
                for(int i=0;i<n;i++)
                {
                    int x=(s>>(3*i))&7;
                    if(a[x+1][j]==v)t|=x<<(3*k++);
                }
            int val=dis+w[j];
            if(!f.count(t)||val<f[t])
            {
                f[t]=val;g[t]=g[s];
                q.push({val,t});
            }
            else if(val==f[t])g[t]=(g[t]+g[s])%mod;
        }
    }
    cout<<"-1 0"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        s=" "+s;
        for(int j=1;j<=m;j++)
            a[i][j]=s[j]-'0';
    }
    for(int i=1;i<=n;i++)
        cin>>p[i];
    solve3();
    return 0;
}
