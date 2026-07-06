#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6,INF=1e9;
int n,a[5][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        int ans=0,maxx=-INF;
        cin>>n;
        for(int i=1;i<=2;i++)
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
        {
            ans+=max(a[1][i],a[2][i]);
            if(a[1][i]>a[2][i])a[1][i]=-INF;
            else a[2][i]=-INF;
        }
        for(int i=1;i<=n;i++)
            maxx=max(maxx,max(a[1][i],a[2][i]));
        cout<<ans+maxx<<endl;
    }
    return 0;
}