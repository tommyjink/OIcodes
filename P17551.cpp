#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1005,P=998244353;
int n,g[2][N][N],f[2][N][N],sum[2][N][N];
int K,now=0;
string s;
void add(int &x,int y)
{
    x=(x+y+P)%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    n=s.length();
    K=n/3;
    s=" "+s;
    f[now][0][0]=1;
    sum[now][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        now^=1;
        for(int j=0;j<=K;j++)
            for(int k=0;k<=K;k++)   
                g[now][j][k]=f[now][j][k]=sum[now][j][k]=0;
        for(int a=0;a<=K;a++)
        {
            for(int b=0;a+b<=K;b++)
            {
                if(s[i]=='A'||s[i]=='?')
                {
                    if(a+b==K)add(f[now][a][b],f[now^1][a][b]);
                    else add(f[now][a][b+1],f[now^1][a][b]);
                }
                if(s[i]=='B'||s[i]=='?')
                {
                    if(b==0)add(f[now][a][b],f[now^1][a][b]);
                    else add(f[now][a+1][b-1],f[now^1][a][b]);
                }
            }
        }
        for(int a=0;a<=K;a++)
        {
            for(int b=a;b<=K;b++)
            {
                if(s[i]=='A'||s[i]=='?')
                {
                    if(a>0&&b>0)
                    {
                        add(g[now][a-1][b-1],g[now^1][a][b]);
                    }
                }
                if(s[i]=='B'||s[i]=='?')
                {
                    if(a<=b)add(g[now][min(b,a+1)][b],g[now^1][a][b]);
                }
            }
        }
        if(s[i]=='A'||s[i]=='?')
        {
            for(int a=1;a<=K;a++)
            {
                for(int k=1;k<=K;k++)
                {
                    add(g[now][min(a-1,k-1)][k-1],sum[now^1][a][K-a]-(k-a-1>=0?sum[now^1][a][k-a-1]:0));
                }
            }
        }
        for(int a=0;a<=K;a++)
            for(int b=0;a+b<=K;b++)
                sum[now][a][b]=((b?sum[now][a][b-1]:0)+f[now][a][b])%P;
    }
    cout<<g[now][0][0]<<endl;
    return 0;
}