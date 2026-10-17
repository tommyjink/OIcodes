#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int phi[N],vis[N],prime[N],tot=0,f[N];
void init()
{
    phi[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!vis[i])prime[++tot]=i,phi[i]=i-1;
        for(int j=1;j<=tot;j++)
        {
            int x=prime[j]*i;
            if(x>=N)break;
            vis[x]=true;
            if(i%prime[j]==0)
            {
                phi[x]=phi[i]*prime[j];
                break;
            }
            phi[x]=phi[prime[j]]*phi[i];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(int i=2;i<N;i++)
        f[i]=f[i-1]+i-phi[i];
    int t;cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;cin>>n;
        cout<<"Case "<<i<<": "<<f[n]<<endl;
    }
    return 0;
}