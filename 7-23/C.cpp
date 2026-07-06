#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e15;
int n,a[N],x[N],vis[N],sum=0,ans=0,sa[N],sb[N],aa[N],bb[N];
void dfs(int cnt,int now)
{
    if(now>ans)return;
    if(cnt==n)
    {
        ans=min(ans,now);
        if(ans==now)
            for(int i=1;i<=n/2;i++)
                aa[i]=sa[i],bb[i]=sb[i];
        return;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(vis[i]||vis[j]||x[i]==j||x[j]==i)continue;
            vis[i]=vis[j]=true;
            sa[cnt/2+1]=i,sb[cnt/2+1]=j;
            dfs(cnt+2,now+(cnt/2+1)*min(a[i],a[j]));
            vis[i]=vis[j]=false;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>x[i],sum+=x[i];
    if(sum==-n)
    {
        sort(a+1,a+1+n);
        for(int i=1;i<=n/2;i++)
            ans+=i*(n/2-i+1);
        cout<<ans<<endl;
        return 0;
    }
    else if(n<=20)
    {
        ans=INF;
        dfs(0,0);
        if(ans==INF)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        cout<<ans<<endl;
        for(int i=1;i<=n/2;i++)
            cout<<aa[i]<<" "<<bb[i]<<endl;
    }else cout<<"-1"<<endl;
    return 0;
}