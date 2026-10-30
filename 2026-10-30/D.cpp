#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=305,P=1e9;
int n,f[N][N],v[N];
string s;
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>s;
    n=s.length();
    s=" "+s;
    for(int i=1;i<=n;i++)
        f[i][i]=1;
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            if(s[i]!=s[j])continue;
            int cnt=0;
            for(int k=i+1;k<j;k++)
                if(s[k]==s[i])v[++cnt]=k;
            f[i][j]=f[i+1][j-1];
            for(int k=1;k<=cnt;k++)
            {
                f[i][j]=(f[i][j]+f[i+1][v[k]-1]*f[v[k]][j]%P)%P;
            }
            // printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
