#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=500;
int n,m,f[N][N];
string s,t;
void solve()
{
    cin>>s>>t;
    n=s.length(),m=t.length();
    s=' '+s;
    t=' '+t;
    for(int p=1;p<=m;p++)
    {
        // cout<<"P="<<p<<endl;
        memset(f,128,sizeof(f));
        f[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=min(p,i);j++)
            {
                int res=f[i-1][j];
                if(s[i]==t[j]&&j>0)
                    res=max(res,f[i-1][j-1]);
                if(f[i-1][j]>=0&&p+f[i-1][j]+1<=m&&s[i]==t[p+f[i-1][j]+1])
                    res=max(res,f[i-1][j]+1);
                f[i][j]=res;
                // printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
            }
        }
        if(f[n][p]==m-p)
        {cout<<"YES"<<endl;return;}
    }
    cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}