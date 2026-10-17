#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=510,INF=1e18;
int n,m,h1,h2,w1,w2,c,a[N][N],sum[N],pre[N],q[N],ans=-INF;
signed main()
{
    freopen("window.in","r",stdin);
    freopen("window.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>h1>>h2>>w1>>w2>>c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x;cin>>x;
            if(n<=m)a[i][j]=x-c;
            else a[j][i]=x-c;
        }
    if(n>m)swap(n,m),swap(h1,w1),swap(h2,w2);
    for(int l=1;l<=n;l++)
    {
        for(int j=1;j<=m;j++)sum[j]=0;
        for(int r=l;r<=n&&r-l+1<=h2;r++)
        {
            for(int j=1;j<=m;j++)sum[j]+=a[r][j];
            if(r-l+1<h1)continue;
            pre[0]=0;
            for(int j=1;j<=m;j++)pre[j]=pre[j-1]+sum[j];
            int L=1,R=0;
            for(int j=w1;j<=m;j++)
            {
                int x=j-w1;
                while(L<=R&&pre[q[R]]>=pre[x])R--;
                q[++R]=x;
                while(q[L]<j-w2)L++;
                ans=max(ans,pre[j]-pre[q[L]]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
