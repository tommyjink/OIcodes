#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=1e18,P=998244353;
int n,w[N],nxt[N][21],vis[N],in[N],tag[N];
vector<int> v[N];
void topo()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(!in[i])q.push(i);
    }
    while(!q.empty())
    {
        int t=q.front();q.pop();
        vis[t]=1;
        if(!--in[nxt[t][0]])q.push(nxt[t][0]);
    }
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)v[i].clear(),in[i]=vis[i]=tag[i]=0;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)cin>>nxt[i][0],in[nxt[i][0]]++;
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            nxt[j][i]=nxt[nxt[j][i-1]][i-1];
    int ans=0,cnt=1;
    for(int i=1;i<=n;i++)
        if(!in[i])vis[nxt[i][20]]=1,ans+=w[i],tag[i]=1;
    for(int i=1;i<=n;i++)
        v[nxt[i][20]].push_back(i);
    topo();
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        int mn=INF,num=0;
        for(int j:v[i])
        {
            if(w[j]<mn)mn=w[j],num=1;
            else if(w[j]==mn)num++;
            tag[j]=1;
        }
        ans+=mn;
        if(mn)cnt=cnt*num%P;
        else cnt=cnt*(qpow(2,num)-1+P)%P;
    }
    for(int i=1;i<=n;i++)
        if(!tag[i]&&!w[i])cnt=cnt*2%P;
    cout<<ans<<" "<<cnt<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
