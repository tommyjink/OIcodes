#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,P,Q,a[N],b[N],sum[N];
string s;  
void solve()
{
    cin>>n>>P>>Q>>s;
    s=" "+s;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=s[i]-'0';
        if(a[i])b[++cnt]=i;
    }
    int ans=0,val=1e16;
    for(int i=0;i<(1ll<<n);i++)
    {
        if(__builtin_popcountll(i)!=cnt)continue;
        int res=0,p=1;
        for(int j=1;j<=n;j++)
            sum[j]=0;
        for(int j=1;j<=n;j++)
            if(i&(1ll<<(j-1)))
                res+=abs(j-b[p]),p++,sum[j]=1;
        for(int j=1;j<=n;j++)
            sum[j]+=sum[j-1];
        int tag=1;
        for(int j=P;j<=n;j++)
            if(sum[j]-sum[j-P]<Q)tag=0;

        if(res<=val&&tag)val=res,ans=i;
    }
    for(int i=1;i<=n;i++)
        if(ans&(1ll<<(i-1)))cout<<1;
        else cout<<0;
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}