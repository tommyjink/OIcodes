#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,P=998244353,INF=1e16;
int n,m,a[N],b[N],k,c[N];
int dp[N],cnt[N],A[N],maxa[N];
void solve()
{
    cin>>n>>m;
    for(int i=0;i<=m+1;i++)maxa[i]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i],maxa[b[i]]=max(maxa[b[i]],a[i]);
    cin>>k;
    for(int i=1;i<=k;i++)cin>>c[i];
    int L=0,ans=INF,anscnt=0;
    for(int i=1;i<=n;i++)L=max(L,a[i]+b[i]);
    A[m+1]=0;
    for(int i=m;i>=0;i--)A[i]=max(A[i+1],maxa[i+1]);
    for(int s=L;s<=L+2*k-2;s++)
    {
        for(int i=0;i<=s;i++)dp[i]=INF,cnt[i]=0;
        dp[0]=0,cnt[0]=1;
        for(int u=0;u<=s;u++)
        {
            if(dp[u]>=INF)continue;
            int R=k;
            if(u>m)R=min(R,s-u);
            else R=min(R,s-A[u]-u);
            for(int d=1;d<=R;d++)
            {
                int tmp=dp[u]+c[d];
                if(dp[u+d]>tmp)cnt[u+d]=cnt[u],dp[u+d]=tmp;
                else if(dp[u+d]==tmp)cnt[u+d]=(cnt[u+d]+cnt[u])%P;
            }
        }
        if(dp[s]<ans)ans=dp[s],anscnt=cnt[s];
        else if(dp[s]==ans)anscnt=(anscnt+cnt[s])%P;
    }
    cout<<ans<<" "<<anscnt<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t;cin>>_t;
    while(_t--)solve();
    return 0;
}