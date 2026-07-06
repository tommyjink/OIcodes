#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=3e3+114,MOD=1e9+7;
int n,a[N],dp[N][N][3][3],DP[N][N][3][3];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=c-'0';
    }
    for(int i=0;i<3;i++)
        if((1<<i)&a[1])dp[1][0][i][0]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=i-1;j++)
            for(int t=0;t<3;t++)
                for(int w=0;w<3;w++)
                    for(int now=0;now<3;now++)if((1<<now)&a[i]){
                        if(now==t){
                            dp[i][j][t][w]=(dp[i][j][t][w]+dp[i-1][j][t][w])%MOD;
                            DP[i][j][t][w]=(DP[i][j][t][w]+DP[i-1][j][t][w]+dp[i-1][j][t][w])%MOD;
                        }else if(now==(t+1)%3){
                            if(j>0){
                                dp[i][j-1][now][w]=(dp[i][j-1][now][w]+dp[i-1][j][t][w])%MOD;
                                DP[i][j-1][now][w]=(DP[i][j-1][now][w]+DP[i-1][j][t][w]+dp[i-1][j][t][w])%MOD;
                            }else{
                                if(w<2){
                                    dp[i][0][now][w+1]=(dp[i][0][now][w+1]+dp[i-1][0][t][w])%MOD;
                                    DP[i][0][now][w+1]=(DP[i][0][now][w+1]+DP[i-1][0][t][w])%MOD;
                                }else{
                                    dp[i][0][now][0]=(dp[i][0][now][0]+dp[i-1][0][t][2])%MOD;
                                    DP[i][0][now][0]=(DP[i][0][now][0]+DP[i-1][0][t][2]+dp[i-1][0][t][2])%MOD;
                                }
                            }
                        }else{
                            dp[i][j+1][now][w]=(dp[i][j+1][now][w]+dp[i-1][j][t][w])%MOD;
                            DP[i][j+1][now][w]=(DP[i][j+1][now][w]+DP[i-1][j][t][w])%MOD;
                        }
                    }
    int ans=0;
    for(int i=0;i<=n;i++)
        for(int t=0;t<3;t++)
            for(int w=0;w<3;w++){
                int cnta=1,cntb=0;
                if(w==2)cntb++;
                cnta+=i/3,cntb+=i/3;
                if(i%3==2)cntb++;
                int res=(DP[n][i][t][w]+(max(cnta,cntb)-1)*dp[n][i][t][w]%MOD)%MOD;
                ans=(ans+res)%MOD;
            }
    cout<<ans<<endl;
    return 0;
}
