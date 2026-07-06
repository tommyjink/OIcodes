#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define F(x) x+8
using namespace std;
const int N=1e3+10,M=300,L=8;
int n,T[N],B[N],f[N][M][L+10];
//f[i+1][j>>1][k-1]=min(f[i+1][j>>1][k-1],f[i][j][k])    ,j&1
//f[i][j|(1ll<<l)][l]=min(f[i][j|(1ll<<l)][l],f[i][j][k]+T[i+k]^T[i+l])     
void solve()
{
    cin>>n;
    memset(f,127,sizeof(f));
    for(int i=1;i<=n;i++)
        cin>>T[i]>>B[i];
    f[1][0][-1+8]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(1ll<<8);j++)
        {
            for(int k=-8;k<=7;k++)
            {
                if(f[i][j][k+8]>1e9)continue;
                int limit=B[i];
                for(int l=0;l<=7;l++)
                    if(!(j&(1ll<<l)))
                        limit=min(limit,l+B[i+l]);
                if(j&1ll)f[i+1][j>>1][k-1+8]=min(f[i+1][j>>1][k-1+8],f[i][j][k+8]);
                else for(int l=0;l<=limit;l++)
                {
                    if(j&(1ll<<l))continue;
                    f[i][j|(1ll<<l)][l+8]=min(f[i][j|(1ll<<l)][l+8],f[i][j][k+8]+(i+k?(T[i+k]^T[i+l]):0));
                }
            }
        }
    }
    int ans=1e9;
    for(int i=-8;i<=-1;i++)ans=min(ans,f[n+1][0][i+8]);
    cout<<ans<<endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

/*
2


5
5 2
4 1
12 0
3 3
2 2


2
5 0
4 0
*/