#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+100,P=1e9+7;
int n,p[N],e[N],b,bb,ans1=1,ans2=1;
int qpow(int x,int y,int d)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%d;
        y>>=1;
        x=x*x%d;
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i]>>e[i];
    cin>>b;
    bb=qpow(b,P-2,P);
    for(int i=1;i<=n;i++)
        ans1=ans1*qpow(p[i],e[i],P)%P;
    for(int i=1;i<=n;i++)
        ans2=ans2*qpow(p[i],e[i],b)%b;
    int ans=((ans1-ans2)%P+P)%P;
    cout<<ans*bb%P<<endl;
    return 0;
}