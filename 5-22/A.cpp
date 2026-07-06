#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int tag[N];
signed main()
{
    // freopen("test.in","r",stdin);
    // freopen("test1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,ans=0,cnt=0;
        cin>>n>>k;
        memset(tag,0,sizeof(tag));
        for(int i=1;i<=n;i++)
            if(i%k==0)tag[i]=true,ans++;
        for(int i=1;i<=n;i++)
            if(!tag[i]&&i*2%k==0)cnt++;
        ans=ans*ans*ans+cnt*cnt*cnt;
        cout<<ans<<endl;
    }
    return 0;
}