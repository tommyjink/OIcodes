#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1005,P=1e9+7;
int n,m,a[N][N],fa[N*N],cnt[N*N];
int f(int x,int y)
{
    return x*m+y;
}
int getfa(int x)
{
    if(x==fa[x])return fa[x];
    return fa[x]=getfa(fa[x]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
            if(s[j-1]=='.')a[i][j]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cnt[f(i,j)]=1,fa[f(i,j)]=f(i,j);
    for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++)
            if(a[i][j]&&a[i][j+1])
            {
                int x=getfa(f(i,j));
                int y=getfa(f(i,j+1));
                if(x!=y)fa[x]=y;
            }
    for(int i=n-1;i>=1;i--)
    {   
        for(int j=1;j<=m;j++)
        {
            // cout<<a[i][j]<<" ";
            if(!a[i][j])continue;
            if(a[i+1][j])
            {
                int x=getfa(f(i,j)),y=getfa(f(i+1,j));
                // cout<<x<<","<<y<<endl;
                if(x!=y)
                {
                    fa[y]=x;
                    cnt[x]=cnt[x]*cnt[y]%P;
                }
            }
        }
        // cout<<endl;
        for(int j=1;j<=m;j++)
            if(a[i][j]&&f(i,j)==getfa(f(i,j)))
                cnt[f(i,j)]=(cnt[f(i,j)]+1)%P;
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //         cout<<cnt[f(i,j)]<<" ";
    //     cout<<endl;
    // }
    int ans=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(getfa(f(i,j))==f(i,j))ans=(ans*cnt[f(i,j)])%P;
    cout<<ans<<endl;
    return 0;
}