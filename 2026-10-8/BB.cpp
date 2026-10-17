#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1005,P=998244353;
int n,m,f[N][N],g[2][N][N],cnt[N];
string s;
int cal(int l,int r){return cnt[r]-cnt[l-1];}
void add(int &x,int y){x=(x+y)%P;}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    m=2*n-1;
    for(int i=1;i<=m;i++)
        if(s[i]=='R')cnt[i]=cnt[i-1]+1;
        else cnt[i]=cnt[i-1]-1;
    for(int i=1;i<=m;i++)
        f[i][i]=1;
    for(int len=2;len<=m;len++)
    {
        for(int i=1;i<=m-len+1;i++)
        {
            int j=i+len-1;
            for(int k=i;k<j;k++)
            {
                if(abs(cal(i,k))==1&&abs(cal(k+1,j))==1)
                {
                    if(cal(i,k)==-1)add(g[0][i][j],f[i][k]*f[k+1][j]%P);
                    else add(g[1][i][j],f[i][k]*f[k+1][j]%P);
                }
                if(abs(cal(i,j))==1&&abs(cal(k+1,j))==1)
                {
                    if(cal(k+1,j)==-1)add(f[i][j],g[1][i][k]*f[k+1][j]%P);
                    else add(f[i][j],g[0][i][k]*f[k+1][j]%P);
                }
            }
        }
    }
    cout<<f[1][m]<<endl;
    return 0;
}