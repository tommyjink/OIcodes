#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10,M=1e5+10;
int n,f[N][M],ans=0;
struct node
{
    int w,s,v;
}a[N];
bool cmp(node x,node y)
{
    return x.w+x.s>y.w+y.s;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].w>>a[i].s>>a[i].v;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        // cout<<a[i].w<<","<<a[i].s<<","<<a[i].v<<endl;
        for(int j=0;j<M;j++)
        {
            f[i][j]=f[i-1][j];
            if(j<=a[i].s)f[i][j]=max(f[i-1][j+a[i].w]+a[i].v,f[i-1][j]);
            ans=max(ans,f[i][j]);
            // printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
        }
    }
    cout<<ans<<endl;    
    return 0;
}