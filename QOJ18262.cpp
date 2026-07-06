#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int X=105,S=10200;
int n,k,mod,ms;
int fac[X],inv[X];
int dp[2][X][S];

int qpow(int a,int b){
    int r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod,b>>=1;
    }
    return r;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>mod;
    ms=n*(n+1);
    fac[0]=1;
    for(int i=1;i<=n+1;i++)fac[i]=fac[i-1]*i%mod;
    inv[n+1]=qpow(fac[n+1],mod-2);
    for(int i=n;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    dp[0][0][0]=1;
    for(int i=1;i<n;i++){
        int cur=i&1^1,nxt=i&1;
        memset(dp[nxt],0,sizeof(dp[nxt]));
        for(int s=0;s<=ms;s++){
            int pr=0;
            for(int c=0;c<=i;c++){
                if(c<=i-1)pr=(pr+dp[cur][c][s]*fac[i-c])%mod;
                int ns=s+i+c;
                if(ns<=ms)dp[nxt][c][ns]=(dp[nxt][c][ns]+pr*inv[i-c])%mod;
            }
        }
    }
    int ans=0,cur=n&1^1;
    for(int c=0;c<n;c++){
        int way=fac[n-c],l=n+c,r=2*n;
        for(int s=0;s<=ms;s++){
            if(!dp[cur][c][s])continue;
            int nd=max(l,k-s);
            if(nd<=r)ans=(ans+dp[cur][c][s]*way%mod*(r-nd+1))%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
