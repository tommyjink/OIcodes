#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n,MOD;
int p[10]={0,2,3,5,7,11,13,17,19,0};
struct node{
    int val,big,S;
    void init(){
        int i,tmp=val;big=-1;
        for(i=1;i<=8;++i){
            if(tmp%p[i]) continue;
            S|=(1<<(i - 1));
            while(tmp%p[i]==0) tmp/=p[i];
        }
        if(tmp!=1) big=tmp; 
    }
}a[510];
inline bool cmp(node l,node r){
    return l.big<r.big;
}
int pl(int l,int r){
    l+=r;
    return l>=MOD?l - MOD:l;
}
int dp[300][300],f1[300][300],f2[300][300];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>MOD;
    for(int i = 2;i<=n;++i) a[i - 1].val = i,a[i - 1].init();
    sort(a + 1,a + n,cmp);
    dp[0][0]=1;
    for(int i = 1;i<n;++i){
        if(i==1||a[i].big!=a[i - 1].big||a[i].big==-1){
            memcpy(f1,dp,sizeof(f1));
            memcpy(f2,dp,sizeof(f2));
        }
        for(int j = 255;j>=0;--j){
            for(int k = 255;k>=0;--k){
                if(j&k) continue;
                if((a[i].S&j)==0) f2[j][k|a[i].S]=pl(f2[j][k|a[i].S],f2[j][k]);
                if((a[i].S&k)==0) f1[j|a[i].S][k]=pl(f1[j|a[i].S][k],f1[j][k]);
            }
        }
        if(i==n - 1||a[i].big!=a[i + 1].big||a[i].big==-1){
            for(int j = 0;j<=255;++j){
                for(int k = 0;k<=255;++k){
                    if(j&k) continue;
                    dp[j][k]=pl(f1[j][k],pl(f2[j][k],MOD - dp[j][k]));
                }
            }
        }
    }
    int ans=0;
    for(int j = 0;j<=255;++j){
        for(int k = 0;k<=255;++k){
            if((j&k)==0&&dp[j][k]) ans=pl(ans,dp[j][k]);
        }
    }
    cout<<ans;
    return 0;
}