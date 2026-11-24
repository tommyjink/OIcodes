#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,m,b[N],in[N],fac[N],inv[N];
int head[N],tot,tag[N],inn[N],d[N];
int num,dfn[N],low[N],stk[N],top,col[N],cnt;
int val[N],siz[N];
struct node
{
    int to,next,val,from;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z,x};
    head[x]=tot;
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
int C(int x,int y)
{
    if(x<y||y<0)return 0;
    return fac[x]*inv[y]%P*inv[x-y]%P;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    stk[top++]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
        else if(!col[v])low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        while(1)
        {
            int t=stk[--top];
            col[t]=cnt;
            val[cnt]=b[t];
            siz[cnt]++;
            if(t==x)break;
        }
    }
}
void solve()
{
    cin>>n>>m;
    tot=num=top=cnt=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=head[i]=dfn[i]=low[i]=stk[i]=col[i]=val[i]=siz[i]=in[i]=tag[i]=inn[i]=d[i]=0;
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];
    int ok=1;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(b[x]+z<b[y]){ok=0;}
        if(b[x]+z==b[y])
            add(x,y,z),inn[y]++;
    }
    if(!ok){cout<<"0"<<endl;return;}
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
    // for(int i=1;i<=n;i++)
    //     cout<<col[i]<<",";
    // cout<<endl;
    // for(int i=1;i<=cnt;i++)
    //     cout<<siz[i]<<"!"<<val[i]<<endl;
    for(int i=1;i<=tot;i++)
    {
        int x=e[i].from;
        int y=e[i].to;
        if(col[x]!=col[y])
            in[col[y]]++;
    }
    int ans=1;
    vector<int> V;
    for(int i=1;i<=n;i++)
        d[b[i]]++;
    for(int i=1;i<=cnt;i++)
    {
        if(!in[i])
        {
            tag[val[i]]++,ans=ans*siz[i]%P;
            d[val[i]]--;
        }
    }
    for(int i=1;i<=n;i++)
        if(tag[i]>1){cout<<"0"<<endl;return;}
    int now=0;
    for(int i=n;i>=1;i--)
    {
        if(!tag[i])now++;
        // cout<<i<<","<<now<<","<<d[i]<<","<<C(now,d[i])<<endl;
        // if(now<d[i]){cout<<"0"<<endl;return;}
        ans=ans*C(now,d[i])%P*fac[d[i]]%P;
        now-=d[i];
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}