#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,M=23,mod=998244353,inf=4e18;
int n,m,w[M],p[N],a[N][M],d[N],b[N],mn[N],cnt[N],ans=inf,res;
void solve1()
{
    fill(mn,mn+n+1,inf);
    for(int j=1;j<=m;j++)
    {
        int x=0;
        while(x<n&&!a[p[x+1]][j])x++;
        if(w[j]<mn[x])mn[x]=w[j],cnt[x]=1;
        else if(w[j]==mn[x])cnt[x]++;
    }
    int ans=0,res=1,k=0;
    for(int i=1;i<n;i++)
        if(p[i]>p[i+1])
        {
            if(mn[i]==inf)
            {
                cout<<"-1 0"<<endl;
                return;
            }
            ans+=mn[i];
            res=res*cnt[i]%mod;
            res=res*(++k)%mod;
        }
    cout<<ans<<" "<<res<<endl;
}
void dfs(int s,int sum)
{
    if(sum>ans)return;
    int bad=0,tag=1;
    for(int i=1;i<n;i++)
        if(!(d[i]&s))
        {
            bad|=b[i];
            if(p[i]>p[i+1])tag=0;
        }
    if(tag)
    {
        if(sum<ans)ans=sum,res=0;
        res=(res+1)%mod;
        return;
    }
    for(int j=1;j<=m;j++)
        if(!((s|bad)>>(j-1)&1))
            dfs(s|(1<<(j-1)),sum+w[j]);
}
void solve2()
{
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[p[i]][j]!=a[p[i+1]][j])d[i]|=1<<(j-1);
            if(a[p[i]][j]>a[p[i+1]][j])b[i]|=1<<(j-1);
        }
    dfs(0,0);
    if(ans==inf)cout<<"-1 0"<<endl;
    else cout<<ans<<" "<<res<<endl;
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
    int tag=1;
    for(int j=1;j<=m;j++)
        for(int i=2;i<=n;i++)
            if(a[p[i]][j]<a[p[i-1]][j])tag=0;
    if(tag)solve1();
    else if(m<=9)solve2();
    else cout<<"-1 0"<<endl;
    return 0;
}
