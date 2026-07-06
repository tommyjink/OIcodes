#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define F(x) ((x)*(x))
#define pii pair<int,int>
using namespace std;
const int N=55,INF=1e9;
int n,a[N],A,B,dp[N][N][N][N],Mx[N][N],Mn[N][N];
int v[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>A>>B;
    for(int i=1;i<=n;i++)
        cin>>a[i],v[i]=a[i];
    sort(v+1,v+1+n);
    int tot=unique(v+1,v+1+n)-v-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(v+1,v+1+tot,a[i])-v;
    memset(dp,1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            Mx[i][j]=-INF;
            Mn[i][j]=INF;
            for(int k=i;k<=j;k++)
            {
                Mx[i][j]=max(Mx[i][j],a[k]);
                Mn[i][j]=min(Mn[i][j],a[k]);
            }
        }
    }
    for(int i=1;i<=n;i++)
        dp[i][i][a[i]][a[i]]=A;
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            for(int mx=1;mx<=tot;mx++)
            {
                for(int mn=1;mn<=mx;mn++)
                {
                    for(int k=i;k<j;k++)
                    {
                        
                    }
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}