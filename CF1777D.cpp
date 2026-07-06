#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=1e9+7,N=1e6+10;;
int n,head[N],tot=0,val[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    val[x]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        val[x]=max(val[x],val[v]+1);
    }
}
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
void solve()
{
    cin>>n;
    tot=0;
    for(int i=1;i<=n;i++)
        head[i]=val[i]=0;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+val[i])%P;
    ans=ans*qpow(2,n-1)%P;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}