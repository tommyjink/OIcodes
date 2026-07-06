#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9;
int n,in[N],ans=0,b[N],c[N],d[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    b[0]=1;
    for(int i=1;i<N;i++)
        b[i]=b[i-1]*i%P;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        in[x]++,in[y]++;
    }
    c[0]=1;
    for(int i=1;i<=n;i++)c[i]=c[i-1]*b[in[i]-1]%P;
    d[n+1]=1;
    for(int i=n;i>=1;i--)d[i]=d[i+1]*b[in[i]-1]%P;
    // cout<<k<<"!"<<endl;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+c[i-1]*d[i+1]%P*b[in[i]]%P)%P;
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}