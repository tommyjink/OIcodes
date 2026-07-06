#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=20,M=60,L=1e5,P=1000003;
int n,k,len,b[M][M],f[M][L];
string s[N];
void solve()
{
    int ans=0;
    memset(b,0,sizeof(b));
    memset(f,0,sizeof(f));
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    len=s[1].length();
    for(int i=0;i<len;i++)
        for(int j=1;j<=n;j++)
            for(int c='a';c<='z';c++)
                if(s[j][i]=='?'||s[j][i]==c)
                    b[i][c-'a']|=(1ll<<(j-1));
    f[0][(1ll<<n)-1]=1;
    for(int i=0;i<len;i++)
        for(int j=0;j<(1ll<<n);j++)
                for(int c='a';c<='z'&&f[i][j];c++)
                    f[i+1][j&b[i][c-'a']]+=f[i][j],
                    f[i+1][j]%=P;
    for(int i=0;i<(1ll<<n);i++)
        if(__builtin_popcount(i)==k)
            ans=(ans+f[len][i])%P;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}