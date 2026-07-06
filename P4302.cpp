#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=150;
int n,f[N][N],g[N][N];
string s;
int cal(int x)
{
    int res=0;
    while(x)
        x/=10,res++;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    n=s.length();
    s=' '+s;
    for(int len=1;len<=n;len++)
    {
        for(int i=n-len+1;i>=1;i--)
        {
            int j=i+len-1;
            int k=j+len;
            g[i][j]=1;
            f[i][j]=j-i+1;
            if(k<=n&&s.substr(i,len)==s.substr(j+1,len))
                g[i][j]=g[j+1][k]+1;
            // cout<<s.substr(i,len)<<endl;
            // printf("g[%lld][%lld]=%lld\n",i,j,g[i][j]);
        }
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            f[i][j]=j-i+1;
            for(int k=i;k<=j-1;k++)
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            for(int k=1;k<=len;k++)
                if(len%k==0&&g[i][i+k-1]>=len/k)
                    f[i][j]=min(f[i][j],f[i][i+k-1]+2+cal(len/k));
        }
    }
    cout<<f[1][n];
    return 0;
}