#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=25,P=1e9+7;
int T,n1,n2,m,k,inv[N],vis[N];
pii a[N*N];
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
int C(int n,int m)
{
    if(m<0||n<0||m>n)return 0;
    int res=1;
    for(int i=1;i<=m;i++)
        res=res*((n-m+i)%P)%P*inv[i]%P;
    return res;
}
void solve()
{
    cin>>n1>>n2>>m>>k;
    bool fl=true;
    for(int i=1;i<=m;i++)
        vis[i]=false;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i].first>>a[i].second;
        if(a[i].first!=a[i].second)fl=false;
        else vis[a[i].first]=true;
    }
    if(fl)
    {
        int cnt=0,ans=0;
        for(int i=1;i<=m;i++)
            cnt+=vis[i];
        for(int s=cnt;s<=min(n1,m);s++)
        {
            int w1=C(m-cnt,s-cnt)*C(n1-1,s-1)%P;
            for(int t=cnt;t<=min(n2,m);t++)
            {
                int w2=C(m-cnt,t-cnt)*C(n2-1,t-1)%P;
                ans=(ans+w1*w2)%P;
            }
        }
        cout<<ans<<endl;
        return;
    }
    int ans=0;
    int lim=(1ll<<m);
    for(int s=0;s<lim;s++)
    {
        int c1=__builtin_popcountll(s);
        if(c1>n1)continue;
        int w1=C(n1-1,c1-1);
        if(!w1)continue;
        for(int t=0;t<lim;t++)
        {
            int c2=__builtin_popcountll(t);
            if(c2>n2)continue;
            int w2=C(n2-1,c2-1);
            if(!w2)continue;
            bool ok=true;
            for(int i=1;i<=k;i++)
            {
                int x=a[i].first-1,y=a[i].second-1;
                if(!(((s>>x)&1)&&((t>>y)&1)||(((t>>x)&1)&&((s>>y)&1))))
                {
                    ok=false;
                    break;
                }
            }
            if(ok)ans=(ans+w1*w2)%P;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<N;i++)
        inv[i]=qpow(i,P-2);
    cin>>T;
    while(T--)
        solve();
    return 0;
}