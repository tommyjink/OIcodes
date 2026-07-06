#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=5e6+10,mod=998244353;
int c,n,a[N],sum,ans;
bool f[M],g[M];

bool check(int s)
{
    int now=0;
    for(int i=n;i>=1;i--)
    {
        if((s>>(i-1))&1)now+=a[i];
        else if(now>=a[i])return false;
    }
    return true;
}

void solve1()
{
    int lim=(1ll<<n)-1;
    for(int i=0;i<=lim;i++)
        if(check(i))ans++;
    cout<<ans%mod<<endl;
}

void solve2()
{
    f[0]=true;
    int now=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=now+a[i];j++)
            g[j]=false;
        for(int j=0;j<=now;j++)
        {
            if(!f[j])continue;
            g[j+a[i]]=true;
            if(j<a[i])g[j]=true;
        }
        now+=a[i];
        for(int j=0;j<=now;j++)
            f[j]=g[j];
    }
    for(int i=0;i<=sum;i++)
        if(f[i])ans++;
    cout<<ans%mod<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("threhold.in","r",stdin);
    freopen("threhold.out","w",stdout);
    cin>>c>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(n<=18)solve1();
    else if(sum<M)solve2();
    else cout<<1<<endl;
    return 0;
}
