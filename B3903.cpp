#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,x,a[N],b[N],maxa=0,fac[N],inv[N],cnt=0;
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
void init()
{
    fac[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%P;
}
int binary(int x)
{
    int cnt=0;
    while(x)
    {
        cnt++;
        x>>=1;
    }
    return cnt;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin>>n>>x;
    int x1=binary(x),x2=binary(x-(1ll<<(x1-1)));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=binary(a[i]);
        b[a[i]]++;
        maxa=max(maxa,a[i]);
    }
    for(int i=1;i<=63;i++)b[i]+=b[i-1];
    int cnt1=b[x1]-b[x1-1],cnt2=b[x1-1]-b[x2],cnt3=b[x2];
    if(maxa>x1||cnt3+1<cnt1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    // cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
    int ans=fac[cnt3+1]*inv[cnt3+1-cnt1]%P*fac[cnt3]%P*
            fac[cnt2]%P*qpow(cnt2+1,cnt3-cnt1)%P*inv[cnt3-cnt1]%P;
    cout<<ans<<endl;
    return 0;
}