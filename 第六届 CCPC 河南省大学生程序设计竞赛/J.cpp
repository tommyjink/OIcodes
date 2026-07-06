#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int vis[N+100],val[N],T;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=2;i<=N;i++)
    {
        if(vis[i])continue;
        // cout<<i<<endl;
        for(int j=i;j*i<=N;j++)
            vis[j*i]=true;
    }
    for(int i=10000;i<=99999;i++)
    {
        if(!vis[i])continue;
        int x=i,y=0;
        while(x)
        {
            y|=(1ll<<(x%10));
            x/=10;
        }
        val[y]=i;
    }
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int x=n,y=0;
        while(x)
        {
            y|=(1ll<<(x%10));
            x/=10;
        }
        if(val[y])cout<<val[y]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}