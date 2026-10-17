#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2005,P=1e9+7;
int n,f[N][N][2];
string s,t;
void solve()
{
    cin>>n>>s>>t;
    s=" "+s;
    t=" "+t;
    memset(f,0,sizeof(f));
    f[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0')f[i][0][0]=1;
        else if(s[i]=='+'||f[i-1][0][1])f[i][0][1]=1;
        else f[i][0][0]=1;
        if(t[i]=='0')f[0][i][0]=1;
        else if(t[i]=='+'||f[0][i-1][1])f[0][i][1]=1;
        else f[0][i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i]=='1'){f[i][j][0]=f[i-1][j][0],f[i][j][1]=f[i-1][j][1];continue;}
            if(t[j]=='1'){f[i][j][0]=f[i][j-1][0],f[i][j][1]=f[i][j-1][1];continue;}
            if(s[i]=='0'&&t[j]=='0')f[i][j][0]=1;
            else if(s[i]=='0')
            {
                f[i][j][0]=1;
                if(t[j]=='+')f[i][j][1]=(f[i][j-1][1]+f[i][j-1][0])%P;
                else f[i][j][1]=f[i][j-1][1];
            }
            else if(t[j]=='0')
            {
                f[i][j][0]=1;
                if(s[i]=='+')f[i][j][1]=(f[i-1][j][1]+f[i-1][j][0])%P;
                else f[i][j][1]=f[i-1][j][1];
            }
            else
            {
                if(s[i]=='+'&&t[j]=='+')
                {
                    f[i][j][0]=0;
                    f[i][j][1]=(f[i-1][j][0]+f[i-1][j][1]+f[i][j-1][0]+f[i][j-1][1]-f[i-1][j-1][1]-f[i-1][j-1][0]+P)%P;
                }
                else if(s[i]=='+')
                {
                    f[i][j][0]=f[i][j-1][0];
                    f[i][j][1]=(f[i-1][j][0]+f[i-1][j][1]+f[i][j-1][1])%P;
                }
                else if(t[j]=='+')
                {
                    f[i][j][0]=f[i-1][j][0];
                    f[i][j][1]=(f[i-1][j][1]+f[i][j-1][0]+f[i][j-1][1])%P;
                }
                else
                {
                    f[i][j][0]=f[i-1][j][0]*f[i][j-1][0];
                    f[i][j][1]=(f[i-1][j][1]+f[i][j-1][1]-f[i-1][j-1][1]+P)%P;
                }
            }
            // printf("f[%lld][%lld][0]=%lld\n",i,j,f[i][j][0]);
            // printf("f[%lld][%lld][1]=%lld\n",i,j,f[i][j][1]);
        }       
    }
    cout<<(f[n][n][0]+f[n][n][1])%P<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}