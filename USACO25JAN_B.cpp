#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,a[N],b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int p=0,k=-1,ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=(a[i]/m)*m;
            b[i]=a[i]-b[i];
            p+=b[i];
        }
        for(int i=1;i<=n;i++)
            if(k==-1||abs(p-b[i]*n)<abs(p-b[k]*n))
                k=i;
        for(int i=1;i<=n;i++)
            ans+=min(abs(b[k]-b[i]),abs(b[k]-b[i]+m));
        cout<<ans<<endl;
        // cout<<a[k]<<" "<<ans<<endl;
        // for(int i=1;i<=n;i++)
        //     cout<<b[i]<<" ";
        // cout<<endl;
        // cout<<p<<endl;
    }
    return 0;
}