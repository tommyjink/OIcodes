#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)a[i]=0;
        for(int i=1;i<=n;i++)
        {
            int x;cin>>x;
            if(x>n)continue;
            if(!a[x])a[x]=1,ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}