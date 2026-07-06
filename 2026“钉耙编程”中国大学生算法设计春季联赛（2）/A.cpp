#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
string s,t;
int dp[20],ndp[20];

int get(string s)
{
    int res=0;
    for(auto c:s) res=(res*2+c-'0')%mod;
    return res;
}
void solve()
{
    cin>>s>>t;
    int n=max(s.size(),t.size());
    s=string(n-s.size(),'0')+s;
    t=string(n-t.size(),'0')+t;
    memset(dp,0,sizeof dp);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        memset(ndp,0,sizeof ndp);
        int x=s[i]-'0',y=t[i]-'0';
        for(int st=0;st<16;st++)
        {
            if(!dp[st]) continue;
            for(int a=0;a<=1;a++)
            {
                for(int b=a;b<=1;b++)
                {
                    if(!(st&1)&&a<x) continue;
                    if(!(st&2)&&a>y) continue;
                    if(!(st&4)&&b<x) continue;
                    if(!(st&8)&&b>y) continue;
                    int nst=st;
                    if(a>x) nst|=1;
                    if(a<y) nst|=2;
                    if(b>x) nst|=4;
                    if(b<y) nst|=8;
                    ndp[nst]=(ndp[nst]+dp[st])%mod;
                }
            }
        }
        for(int i=0;i<16;i++) dp[i]=ndp[i];
    }
    int ans=0;
    for(int i=0;i<16;i++) ans=(ans+dp[i])%mod;
    ans=(ans*2%mod-(get(t)-get(s)+1)%mod+mod)%mod;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}