#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,p[N],k[N],t[N],l[N],r[N];
int ans1=1,ans2=1,ans3=1;
int qpow(int x,int y,int P)
{
    x%=P;
    y%=(P-1);
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i]>>k[i],ans1=ans1*(k[i]+1)%P;
    for(int i=1;i<=n;i++)
    {
        if(p[i]%P==1)ans2=ans2*(k[i]+1)%P;
        else ans2=ans2*qpow(p[i]-1,P-2,P)%P*(qpow(p[i],k[i]+1,P)-1+P)%P;
    }
    l[0]=r[n+1]=1;
    for(int i=1;i<=n;i++)t[i]=qpow(p[i],(1+k[i])*k[i]/2,P);
    for(int i=1;i<=n;i++)l[i]=l[i-1]*(k[i]+1)%(P-1);
    for(int i=n;i>=1;i--)r[i]=r[i+1]*(k[i]+1)%(P-1);
    for(int i=1;i<=n;i++)ans3=ans3*qpow(t[i],l[i-1]*r[i+1]%(P-1),P)%P;
    cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    return 0;
}