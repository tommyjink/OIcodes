#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005,M=50000;
int n,a[N],prime[M],tot,vis[M];
int b[N][N],c[N][N];
vector<int> v[M];
void eular()
{
    for(int i=2;i<M;i++)
    {
        if(!vis[i])prime[++tot]=i;
        for(int j=1;j<=tot;j++)
        {
            int x=prime[j]*i;
            if(x>=M)break;
            vis[x]=true;
            if(i%prime[j]==0)break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int mx=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            b[i][j]=c[i][j]=a[i]+a[j];
    eular();
    int lim=sqrt(2*mx);
    for(int i=1;i<=tot&&prime[i]<=lim;i++)
    {
        int p=prime[i];
        vector<int> sav;
        for(int j=1;j<=n;j++)
            v[a[j]%p].push_back(j),sav.push_back(a[j]%p);
        for(int j=0;j<=p/2;j++)
        {
            if(j==0||j+j==p)
            {
                for(int x:v[j])for(int y:v[j])
                {
                    if(x<=y)
                    {
                        b[x][y]=b[x][y]*(p-1)/p;
                        while(c[x][y]%p==0)c[x][y]/=p;
                    }
                }
            }
            else
            {
                for(int x:v[j])
                    for(int y:v[p-j])
                    {
                        int xx=min(x,y),yy=max(x,y);
                        b[xx][yy]=b[xx][yy]*(p-1)/p;
                        while(c[xx][yy]%p==0)c[xx][yy]/=p;
                    }
            }
        }
        for(int j:sav)v[j].clear();
    }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(c[i][j]>1)b[i][j]=b[i][j]*(c[i][j]-1)/c[i][j];
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            ans+=b[i][j];
    cout<<ans<<endl;
    return 0;
}