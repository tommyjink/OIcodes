#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=100;
int n,f[N][N];
string s;
//f[i][j]=f[i-1][j]+1; 
//f[i][j]=min(f[i][j],f[(i+j)/2][j]+1);   s.substr(j,len)==s.substr(j+len,len)
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    n=s.length();
    s=" "+s;
    memset(f,127,sizeof(f));
    f[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)f[i][i]=min(f[i][i],f[i-1][j]+2);
        for(int j=1;j<i;j++)
        {
            f[i][j]=f[i-1][j]+1;
            int len=(i-j+1);
            if(len%2==0&&s.substr(j,len/2)==s.substr(j+len/2,len/2))
                f[i][j]=min(f[i][j],f[j+len/2-1][j]+1);
        }
    }
    int ans=1e9;
    for(int i=1;i<=n;i++)ans=min(ans,f[n][i]);
    cout<<ans<<endl;
    return 0;
}