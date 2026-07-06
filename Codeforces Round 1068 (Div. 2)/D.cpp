#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define popcount(x) __builtin_popcountll(x)
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N=50;
int n,k,dp[N][N],f[N][N],a[N];
void print(int x)
{
    vector<int> v;
    while(x)
    {
        v.push_back(x&1);
        x>>=1;
    }
    reverse(v.begin(),v.end());
    for(auto i:v)cout<<i;
    cout<<endl;
}
inline int cal(int x)
{
    // cout<<popcount(n)<<","<<popcount(x+n)<<endl;
    return popcount(n)-popcount(x+n)+1;
}
void solve()
{
    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));
    cin>>n>>k;
    // print(n);
    int mpos=0,mmpos=40;
    for(int i=1;i<=40;i++)
    {
        a[i]=n&(1ll<<(i-1));
        if(a[i])mpos=max(mpos,i),mmpos=min(mmpos,i);
    }
    int cnt=0;
    for(int i=mmpos;i<=mpos;i++)
        if(!a[i])cnt++;
    int res=0;
    dp[0][0]=-1e9;
    for(int i=1;i<=40;i++)
    {
        dp[i][0]=-1e9;
        if(a[i])dp[i][1]=1;
        else dp[i][2]=1;
        for(int j=1;j<=min(40ll,k);j++)
        {
            if(a[i])dp[i][j]=max({dp[i][j],f[i-1][j-1]+1,dp[i-1][j]+1});
            else
            {
                if(j>1) dp[i][j]=max(dp[i][j],f[i-1][j-2]+1);
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            } 
            f[i][j]=max({f[i-1][j],dp[i-1][j]});
            res=max(res,f[i][j]);
            res=max(res,dp[i][j]);
            // printf("dp[%lld][%lld]=%lld\n",i,j,dp[i][j]);
        }
    }
    if(k<=cnt)
        cout<<res<<endl;
    else 
    {
        int ans=0;
        while(popcount(n)>1&&k)ans+=cal(lowbit(n)),n+=lowbit(n),k--;
        cout<<ans+k<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}