#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5010,M=15010,P=998244353;
int n,m,a[N],ans=1e18;
int typ[M],l[M],r[M],k[M];
int b[N],fac[N],inv[N];
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
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i;i--)
        inv[i]=inv[i+1]*(i+1)%P;
}
void dfs(int x)
{
    if(x>n)
    {
        for(int i=1;i<=m;i++)
        {
            if(typ[i]==0)
            {
                for(int j=l[i];j<=r[i];j++)
                    if(b[k[i]]>b[j])return;
            }
            else
            {
                for(int j=l[i];j<=r[i];j++)
                    if(b[k[i]]<b[j])return;
            }
        }
        int res=0;
        for(int i=1;i<=n;i++)res+=abs(a[i]-b[i]);
        ans=min(ans,res);
        return;
    }
    for(int i=1;i<=5;i++)
    {
        b[x]=i;
        dfs(x+1);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>typ[i]>>l[i]>>r[i]>>k[i];
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
