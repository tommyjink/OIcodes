#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5050;
int n,a[N],sum[N],f[N],h[N],l[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],sum[i]=sum[i-1]+a[i];
    for(int i=0;i<N;i++)
        h[i]=1e15;
    h[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(sum[i]-sum[j]>=h[j]&&f[j]+1>=f[i])
            {
                f[i]=f[j]+1;
                h[i]=sum[i]-sum[j];
                l[i]=j;
            }
        }
    }
    cout<<f[n]<<endl;
    int now=n;
    vector<int> v;
    while(now)
    {
        v.emplace_back(sum[now]-sum[l[now]]);
        now=l[now];
    }
    reverse(v.begin(),v.end());
    for(auto i:v)cout<<i<<" ";
    return 0;
}