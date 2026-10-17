#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=300,M=1005,INF=1e15;
int n,W,w[N],t[N],v[N],f[M];
bool check(int x)
{
    for(int i=1;i<=n;i++)
        v[i]=1000*t[i]-x*w[i];
    for(int i=0;i<=W;i++)f[i]=-INF;
    f[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=W;j>=0;j--)
        {
            int k=min(W,j+w[i]);
            f[k]=max(f[k],f[j]+v[i]);
        }
    }
    return f[W]>=0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>W;
    for(int i=1;i<=n;i++)
        cin>>w[i]>>t[i];
    int l=0,r=1000000;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}