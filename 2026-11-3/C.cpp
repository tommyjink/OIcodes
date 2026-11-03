#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,INF=1e18;
int n,m,a[N],x[N],y[N];
int id[N],cnt[N],b[N],c[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>x[i]>>y[i],id[i]=i;
    int ans=INF;
    do
    {
        for(int i=1;i<=n;i++)
            cnt[i]=0,b[i]=a[i];
        int res=0;
        for(int ii=1;ii<=m;ii++)
        {
            int i=id[ii];
            int xx=x[i],yy=y[i];
            if(b[xx]==b[yy])continue;
            else if(b[xx]<b[yy])
            {
                cnt[yy]++;
                res+=b[yy]-b[xx];
                b[yy]=b[xx];
            }
            else
            {
                cnt[xx]++;
                res+=b[xx]-b[yy];
                b[xx]=b[yy];
            }
        }
        int tag=0;
        for(int i=1;i<=n;i++)
            if(cnt[i]>1)tag=1;
        if(tag)continue;
        if(res<ans)
        {
            ans=res;
            for(int i=1;i<=m;i++)
                c[i]=id[i];
        }
    }
    while(next_permutation(id+1,id+1+m));
    cout<<ans<<endl;
    for(int i=1;i<=m;i++)
        cout<<c[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}