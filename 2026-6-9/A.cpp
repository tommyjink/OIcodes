#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=3e6+10,M=2e5+10,P=1e9+7,inv3=333333336;
int n,q,mx,a[M],inv[N],ans[N];
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
int f(int n)
{   
    return n*(n+1)*(n+1)%P;
}
void init()
{
    inv[1]=1;
    for(int i=2;i<=mx+1;i++)
        inv[i]=(P-P/i*inv[P%i]%P)%P;
    int c=1,pre=0,ppre=0,tot=3*n+3;
    for(int x=0;x<=mx;x++)
    {
        int k=x+1;
        c=c*(tot-k+1)%P*inv[k]%P;
        int now=(c-3*pre-ppre)%P;
        now=(now+4*P)%P*inv3%P;
        ans[x]=now;
        ppre=pre;
        pre=now;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // for(int i=1;i<=100;i++)
    //     cout<<f(i)<<" ";
    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    init();
    for(int i=1;i<=q;i++)
        cout<<ans[a[i]]<<endl;
    return 0;
}
