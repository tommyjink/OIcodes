#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int Q=5e4+10;
int x[Q],y[Q],c[Q];
int n,m,q;
void solve()
{
    cin>>n>>m>>q;
    for(int i=1;i<=q;i++)
        cin>>x[i]>>y[i]>>c[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int val=0;
            for(int k=1;k<=q;k++)
            {
                if(j<=y[k]-abs(i-x[k]))
                {
                    val^=c[k];
                }
            }
            ans+=val;
        }
    }
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