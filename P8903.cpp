#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005;
int n,A,B,P[N],C[N],X[N],id[N];
int f[N][N],g[N][N],CC[N],XX[N],PP[N];
bool cmp(int x,int y)
{
    if(XX[x]==XX[y])return PP[x]>PP[y];
    return XX[x]<XX[y];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>A>>B;
    for(int i=1;i<=n;i++)
        cin>>PP[i]>>CC[i]>>XX[i],id[i]=i;
    sort(id+1,id+1+n,cmp);
    for(int i=1;i<=n;i++)
        X[i]=XX[id[i]],P[i]=PP[id[i]],C[i]=CC[id[i]];
    for(int i=n;i>=1;i--)
    {
        for(int j=A;j>=0;j--)
        {
            f[i][j]=f[i+1][j];
            if(j>=C[i])f[i][j]=max(f[i][j],f[i+1][j-C[i]]+P[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=B;j>=0;j--)
        {
            g[i][j]=g[i-1][j];
            if(j>=X[i]*C[i])g[i][j]=max(g[i][j],g[i-1][j-X[i]*C[i]]+P[i]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j*X[i]<=B&&j<=C[i];j++)
        {
            ans=max(ans,g[i-1][B-j*X[i]]+P[i]+f[i+1][A-(C[i]-j)]);
        }
    }
    cout<<ans<<endl;
    return 0;
}