#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=155,M=5005;
int n,x,d,a[N],w[N],c[N],dp[N*M];

struct node{int a,w,b;}v[N];

bool cmp(node x,node y){return x.b<y.b;}

void solve()
{
    cin>>n>>x>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)v[i]={a[i],w[i],(a[i]+c[i]-1)/c[i]};
    sort(v+1,v+1+n,cmp);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0; 
    int ans = 0,sum = 0; 
    for(int i=1;i<=n;i++)
    {
        sum+=v[i].a;
        for(int j=sum;j>=v[i].a;j--)
        {
            if(dp[j-v[i].a]!=-1) {
                dp[j]=max(dp[j],dp[j-v[i].a]+v[i].w);
            }
        }
        for(int j=0;j<=sum;j++)
        {
            if(dp[j]!=-1) {
                int y=max(v[i].b,(j+x-1)/x);
                ans=max(ans,dp[j]-y*d);
            }
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}