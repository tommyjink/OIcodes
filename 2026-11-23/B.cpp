#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,P=998244353;
int n,deg[N],col[N],fac[N],inv[N];
int head[N],tot=1,cnt=0,d[N];
int siz[N],vis[N];
vector<int> V[N]; 
struct node
{
    int to,next,from,ban;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x],x};
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
void dfs(int x,int now)
{
    // cout<<x<<"?"<<endl;
    col[x]=now;
    V[now].push_back(x);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(col[v])continue;
        dfs(v,now);
    }
}
int dfs1(int x)
{
    vis[x]=true;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(e[i].ban)continue;
        if(vis[v])return i;
        ban[i^1]=true;
        int res=dfs1(v);
        if(res)return res;
    }
    return 0;
}   
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // freopen("B.in","r",stdin);
    // freopen("B.out","w",stdout);
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=fac[i-1]*i%P;
    inv[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
        deg[x]++,deg[y]++;
    }
    // for(int i=1;i<=n;i++)
    // cout<<deg[i]<<" ";
    // cout<<endl;
    int ans=0,c0=0,c1=0,c2=0;
    for(int i=1;i<=n;i++)
    {
        if(col[i])continue;
        dfs(i,++cnt);
        int m=V[cnt].size(),num=0;
        for(int x:V[cnt])num+=deg[x];
        num/=2;
        // cout<<num<<" "<<m<<endl;
        if(num==m)c0++;
        if(num+1==m)c1++;
        if(num==m+1)c2++;
    }
    // cout<<c0<<" "<<c1<<" "<<c2<<endl;
    if(c0==cnt)
    {
        ans=0;
        for(int i=1;i<=cnt;i++)
        {
            int m=V[i].size();
            d[i]=0;
            for(int x:V[i])
                if(deg[x]>=2)d[i]=(d[i]+C(deg[x],2)*(n-1)%P)%P;
            ans=(ans+d[i]*qpow(2,cnt-1)%P)%P;
        }
        // cout<<"!"<<endl;
    }
    else if(c0==cnt-2&&c1==1&&c2==1)
    {
        ans=1;
        for(int i=1;i<=cnt;i++)
        {
            int m=V[i].size(),num=0;
            for(int x:V[i])num+=deg[x];
            num/=2;
            if(num==m)ans=ans*2%P;
            else if(num+1==m)ans=ans*m%P;
            else if(num==m+1)
            {
                int res=0;
                for(int x:V[i])
                    if(deg[x]>=2)res=(res+C(deg[x],2)*((deg[x]==2)+1)%P)%P;
                ans=ans*res%P;
            }
        }
    }
    else ans=0;
    cout<<ans<<endl;
    return 0;
}