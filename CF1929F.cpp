#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,C,ls[N],rs[N],val[N],ans;
int b[N],cnt=0,fac[N],inv[N];
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
int Com(int x,int y)
{
    if(x<y||y<0)return 0;
    int res=1;
    for(int i=x;i>=x-y+1;i--)res=res*i%P;
    for(int i=y;i>=1;i--)res=res*(inv[i]*fac[i-1]%P)%P;
    return res;
}
void dfs(int x)
{
    if(x==-1)return;
    dfs(ls[x]);
    b[++cnt]=val[x];
    dfs(rs[x]);
}
void solve()
{
    cnt=0;
    ans=1;
    cin>>n>>C;
    for(int i=1;i<=n;i++)
        cin>>ls[i]>>rs[i]>>val[i];
    dfs(1);
    b[0]=1;
    b[cnt+1]=C;
    // for(int i=1;i<=cnt;i++)
    //     cout<<b[i]<<" ";
    // cout<<endl;
    for(int i=0;i<=cnt;i++)
    {
        if(b[i]==-1)continue;
        int j=i+1;
        while(b[j]==-1)j++;
        if(i+1==j)continue;
        ans=ans*Com(b[j]-b[i]+j-i-1,j-i-1)%P;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}