#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a,b,c,s[N],vis[N];
void solve()
{
    int ans=0;
    cin>>n>>a>>b>>c;
    string tmp;cin>>tmp;
    for(int i=1;i<=n;i++)
    {
        if(tmp[i-1]=='5') s[i]=5;
        else if(tmp[i-1]=='2') s[i]=2;
        else s[i]=0;
        vis[i]=false;
    }
    for(int i=1;i<=n-2;i++)
    {
        if(vis[i]||vis[i+1]||vis[i+2])continue;
        if(s[i]==5&&s[i+1]==2&&s[i+2]==0)
            vis[i]=vis[i+1]=vis[i+2]=true,ans++;
    }
    for(int i=1;i<=n-1;i++)
    {
        if(vis[i]||vis[i+1])continue;
        if(s[i]==5&&s[i+1]==2&&c>0)
            vis[i]=vis[i+1]=true,ans++,c--;
        else if(s[i]==5&&s[i+1]==0&&b>0)
            vis[i]=vis[i+1]=true,ans++,b--;
        else if(s[i]==2&&s[i+1]==0&&a>0)
            vis[i]=vis[i+1]=true,ans++,a--;
    }
    int aa=0,bb=0,cc=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        if(s[i]==5)aa++;
        if(s[i]==2)bb++;
        if(s[i]==0)cc++;
    }
    // cout<<aa<<","<<bb<<","<<cc<<endl;
    int res=0;
    for(int i=0;i<=aa&&i<=b&&i<=c;i++)
    {
        int now=i,x=a,y=b-i,z=c-i;
        int k=min({bb,x,z});
        now+=k;
        x-=k,z-=k;
        k=min({cc,x,y});
        now+=k;
        x-=k,y-=k;
        now+=min({x,y,z});
        res=max(res,now);
        // cout<<res<<endl;
    }
    ans+=res;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}