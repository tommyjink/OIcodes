#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10,mod=1e9+7;
int n,h[N],cnt[N],f[110][N],m=1001;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        m=min(m,h[i]);
    }
    int ans=0;
    if(n%2==0)m=0;
    for(int i=0;i<=m;i++){
        for(int j=1;j<=n;j++)cnt[j]=h[j]-i;
        memset(f,0,sizeof f);
        f[1][cnt[1]]=1;
        for(int j=2;j<=n;j++){
            int sum=0;
            for(int pre=0;pre<=cnt[j-1];pre++){
                sum=(sum+f[j-1][pre])%mod;
            }
            for(int now=0;now<=cnt[j];now++){
                f[j][cnt[j]-now]=(f[j][cnt[j]-now]+sum)%mod;
                sum=(sum-f[j-1][now]+mod)%mod;
                if(!sum)break;
            }
        }
        for(int j=0;j<=cnt[n];j++)ans=(ans+f[n][j])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
