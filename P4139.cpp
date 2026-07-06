
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int T,p,phi[N];
void getphi(){
    phi[1]=1;
    for(int i=2;i<N;i++)if(!phi[i])
        for(int j=i;j<N;j+=i){
            if(!phi[j])phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
}
int mul(int a,int b,int mod){
    int res=0;
    while(b){
        if(b&1)res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}
int qpow(int a,int b,int mod){
    int res=1;
    while(b){
        if(b&1)res=mul(res,a,mod)%mod;
        a=mul(a,a,mod)%mod;
        b>>=1;
    }
    return res;
}
int solve(int mod){
    if(mod==1)return 0;
    return qpow(2,solve(phi[mod])+phi[mod],mod);
}
int main(){
    getphi();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&p);
        printf("%d\n",solve(p));
    }
}
