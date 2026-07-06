#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5005,INF=30000;
int n,t,lp,rp,ans;
string s;
short f[N][N][3];
void solve()
{
    cin>>n>>s;
    s="$"+s;
    lp=1;
    while(lp<=n&&s[lp]!='(')lp++;
    rp=n;
    while(rp>=1&&s[rp]!=')')rp--;
    if(lp>rp)
    {
        cout<<0<<endl;
        return;
    }
    ans=2;
    for(int i=1;i<=n;i++)
    {
        f[i][i-1][0]=-INF;
        f[i][i-1][1]=-INF;
        f[i][i-1][2]=0;
    }
    for(int l=rp-1;l>lp;l--)
    {
        for(int r=l;r<rp;r++)
        {
            f[l][r][0]=f[l][r][1]=f[l][r][2]=-INF;
            for(int i=0;i<3;i++)
                f[l][r][i]=max(f[l+1][r][i],f[l][r-1][i]);
            if(l!=r&&s[l]==s[r])
            {
                int z=(s[l]=='(' ? 0 : 1);
                f[l][r][z^1]=max(f[l][r][z^1],(short)(f[l+1][r-1][2]+2));
                f[l][r][2]=max(f[l][r][2],(short)(f[l+1][r-1][z]+2));
            }
            if(ans<2+f[l][r][2])
                ans=2+f[l][r][2];
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
