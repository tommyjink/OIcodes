#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=45,M=2010;
int n,ans,a[N],match[N];
bool notp[M],vis[N];

bool dfs(int x)
{
    for(int i=1;i<=n;i++)
        if((a[i]&1)&&!notp[a[x]+a[i]]&&!vis[i])
        {
            vis[i]=1;
            if(!match[i]||dfs(match[i]))
            {
                match[i]=x;
                return 1;
            }
        }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    notp[0]=notp[1]=1;
    for(int i=2;i<M;i++)
        if(!notp[i])
            for(int j=i*i;j<M;j+=i)notp[j]=1;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
        if(!(a[i]&1))
        {
            for(int j=1;j<=n;j++)vis[j]=0;
            ans+=dfs(i);
        }
    cout<<ans<<endl;
    return 0;
}
