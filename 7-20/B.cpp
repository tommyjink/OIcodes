#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=3e4+100,P=19260817;
int n,a[N],is[N],prime[N],cnt=0,f[N],g[N],d[N],q[N],ans[N],mx;
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {   
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
int F(int x)
{
    return qpow(x,P-2);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
        cin>>q[i],mx=max(mx,q[i]);
    mx+=5;
    for(int i=2;i<mx;i++) {
        if(!is[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt && i*prime[j]<N; j++) {
            is[i*prime[j]] = true;
            if(i%prime[j]==0) break;
        }
    }
    // cout<<"done"<<endl;
    ans[0]=a[0]=1;
    for(int i=1;i<mx;i++)a[i]=a[i-1]*i%P;
    for(int i=1;i<mx;i++)
    {
        f[i]=1;
        int x=i;
        for(int j=1;j<=cnt;j++)
        {
            int now=0;
            while(x%prime[j]==0)x/=prime[j],now++;
            if(now)
                for(int k=1,tmp=prime[j];k<=now;k++,tmp*=prime[j])
                    f[i]=f[i]*qpow(prime[j],i/tmp)%P;
        }
        g[i]=qpow(i,i)*a[i]%P;
        d[i]=g[i]*F(f[i])%P*F(f[i])%P;
        d[i]=d[i]*d[i]%P;
        ans[i]=ans[i-1]*d[i]%P;
        // printf("f[%lld]=%lld,%lld,F=%lld\n",i,f[i],g[i],d[i]);
    }
    for(int i=1;i<=t;i++)
        cout<<ans[q[i]]<<endl;
    // cout<<"done"<<endl;
    return 0;
}