#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005,INF=1e18;
int n,m,dp[N*50];
struct node
{
    int c,f,v;
}a[N],b[N];
bool cmp(node x,node y)
{
    return x.f>y.f;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].c>>a[i].f>>a[i].v;
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>b[i].c>>b[i].f>>b[i].v;
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+m,cmp);
    // for(int i=1;i<=n;i++)
    //     cout<<a[i].c<<" "<<a[i].f<<" "<<a[i].v<<endl;
    // cout<<"_______"<<endl;
    // for(int i=1;i<=m;i++)
    //     cout<<b[i].c<<" "<<b[i].f<<" "<<b[i].v<<endl;
    // cout<<"_______"<<endl;
    int p=0;
    for(int i=0;i<=n*50;i++)
        dp[i]=-INF;
    dp[0]=0;
    for(int i=1;i<=m;i++)
    {
        int o=p;
        while(p==0||(p<=n&&a[p].f>=b[i].f))p++;
        p--;
        // cout<<o+1<<" "<<p<<endl;
        for(int k=o+1;k<=p;k++)
            for(int j=50*n;j>=a[k].c;j--)
                dp[j]=max(dp[j],dp[j-a[k].c]-a[k].v);
        for(int j=0;j<=50*n-b[i].c;j++)
            dp[j]=max(dp[j],dp[j+b[i].c]+b[i].v);
    }
    int ans=0;
    for(int i=0;i<=50*n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}