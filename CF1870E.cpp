
#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010],mex;
vector<pair<int,int>>g[5010];
bool dp[5010][10020];
int rd(){int x=0,f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}return f?-x:x;}
void sol(){
    n=rd();
    for(int i=1;i<=n;i++)a[i]=rd();
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<=n;i++)if(!a[i])g[i].push_back({i,1});
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(int)*(n+5));mex=0;
        for(int j=i;j<=n;j++){
            b[a[j]]=1;
            while(b[mex])++mex;
            if(mex>a[i]&&a[j]<a[i]){g[j].push_back({i,mex});break;}
        }
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(int)*(n+5));mex=0;
        for(int j=i;j>=1;j--){
            b[a[j]]=1;
            while(b[mex])++mex;
            if(mex>a[i]&&a[j]<a[i]){g[i].push_back({j,mex});break;}
        }
    }
    memset(dp[0],0,sizeof(bool)*((n<<1)+5));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        memcpy(dp[i],dp[i-1],sizeof(bool)*((n<<1)+5));
        for(auto j:g[i]){
            for(int k=0;k<=(n<<1);k++){
                if((k^j.second)<=(n<<1))dp[i][k]|=dp[j.first-1][k^j.second];
            }
        }
    }
    for(int i=(n<<1);i>=0;i--){
        if(dp[n][i]){cout<<i<<'\n';return;}
    }
}
int main(){
    int T=rd();
    while(T--)sol();
    return 0;
}
