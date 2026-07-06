#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=1e9+7;
int n,S=1,T=0,ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        ans=(ans+x+T*T%P)%P;
        S=S*S%P*x%P;
        T=(T%P+S)%P;
    }
    cout<<ans<<endl;
    return 0;
}