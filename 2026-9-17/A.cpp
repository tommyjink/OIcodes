#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5005,M=1e5;
int n,a[N],prime[M],tot,vis[M];
map<int,int> sav;
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
int cal(int x)
{
    if(sav.count(x))return sav[x];
    int res=x,o=x;
    for(int i=1;prime[i]*prime[i]<=x;i++)
    {
        if(x%prime[i])continue;
        res=res/prime[i]*(prime[i]-1);
        while(x%prime[i]==0)x/=prime[i];
    }
    if(x>1)res=res/x*(x-1);
    return sav[o]=res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    eular();
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=i;j++)
            ans+=cal(a[i]+a[j]);
    }
    cout<<ans<<endl;
    return 0;
}
