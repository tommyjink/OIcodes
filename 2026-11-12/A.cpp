#include<bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x&(-x))
typedef long long ll;
using namespace std;
const int N=2e5+10,M=23,L=(1<<22)+1,P=998244353;
const ll INF=1e18;
int n,m,w[N],a[N][M],p[N],lg[L];
int g[N],r[N],ban[L],h[L];
int dp[L];
ll f[L],num=0,ans=INF,val[L];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=2;i<L;i++)
        lg[i]=lg[i/2]+1;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
            a[i][j+1]=s[j]-'0';
    }
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=m;i++)
    {
        for(int t=1;t<n;t++)
        {
            int x=p[t],y=p[t+1];
            if(a[x][i]==0&&a[y][i]==1)
                g[t]|=(1<<(i-1));
            if(a[x][i]==1&&a[y][i]==0)
                r[t]|=(1<<(i-1));
        }
    }
    // for(int i=1;i<n;i++)
    //     cout<<i<<":"<<g[i]<<","<<r[i]<<endl;
    for(int i=1;i<n;i++)
    {
        ban[g[i]]|=r[i];
        if(p[i]>p[i+1])
            h[g[i]]=1;
    }
    for(int i=1;i<=m;i++)
    {
        for(int s=0;s<(1<<m);s++)
        {
            if(s&(1<<(i-1)))continue;
            ban[s|(1<<(i-1))]|=ban[s];
            h[s|(1<<(i-1))]|=h[s];
        }
    }
    for(int s=1;s<(1<<m);s++)
    {
        int d=lowbit(s),pos=lg[d]+1;
        val[s]=val[s^d]+w[pos];
    }
    dp[0]=1;
    f[0]=1;
    int full=(1<<m)-1;
    for(int s=0;s<(1<<m);s++)
    {
        if(!dp[s])continue;
        int t=full&(~s);
        if(!h[t])
        {
            if(val[s]<ans)
            {
                ans=val[s];
                num=f[s];
            }
            else if(val[s]==ans)
            {
                num=(num+f[s])%P;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(s&(1<<(i-1)))continue;
            if(ban[t]&(1<<(i-1)))continue;
            int k=s|(1<<(i-1));
            dp[k]=1;
            f[k]=(f[k]+f[s])%P;
        }
    }
    if(ans==INF)cout<<"-1 0"<<endl;
    else cout<<ans<<" "<<num<<endl;
    return 0;
}