#include<bits/stdc++.h>
#include<stdio.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105,M=5005,P=1e9+7;
int n,x,a[N],f[N][M][N];
void add(int &x,int y)
{
    x=(x+y)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    f[1][0][0]=1;
    f[1][0][1]=1;
    for(int i=1;i<n;i++)
    {
        // cout<<"i="<<i<<endl;
        for(int v=x;v>=0;v--)
        {
            for(int t=i;t>=0;t--)
            {
                // printf("f[%lld][%lld]=%lld\n",v,t,f[v][t]);
                if(v+t*(a[i+1]-a[i])>x)continue;
                add(f[i+1][v+t*(a[i+1]-a[i])][t],(t+1)*f[i][v][t]%P);
                if(t>0)add(f[i+1][v+t*(a[i+1]-a[i])][t-1],t*f[i][v][t]%P);
                add(f[i+1][v+t*(a[i+1]-a[i])][t+1],f[i][v][t]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=x;i++)
        add(ans,f[n][i][0]);
    cout<<ans<<endl;
    return 0;
}