#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int tag[N];
signed main()
{
    freopen("test.in","r",stdin);
    freopen("test2.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,K,ans=0,cnt=0;
        cin>>n>>K;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    if((i+k)%K==0&&(i+j)%K==0&&(j+k)%K==0)
                        ans++;
        cout<<ans<<endl;
    }
    return 0;
}