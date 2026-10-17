#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1005,P=998244353;
int n,R[N],cnt=0,B[N],tot=0;
int tag[N],ans=0,vis[N];
string s;
struct DSU
{
    int fa[N];
    void init(){for(int i=1;i<=n;i++)fa[i]=i;}
    int get(int x)
    {
        return x==fa[x]?x:fa[x]=get(fa[x]);
    }
    bool merge(int x,int y)
    {
        x=get(x),y=get(y);
        if(x==y)return false;
        fa[x]=y;
        return true;
    }
}d;
bool check(int x,int y)
{
    int a=R[x],b=tag[x];
    int c=R[y],d=tag[y];
    if(a>b)swap(a,b);
    if(c>d)swap(c,d);
    if(a<c&&c<b&&b<d)return true;
    if(c<a&&a<d&&d<b)return true;
    return false;
}
void dfs(int k)
{
    if(k==n+1)
    {
        d.init();
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(check(i,j))
                    if(!d.merge(i,j))return;
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(d.fa[i]==i)cnt++;
        if(cnt>1)return;
        ans++;
        // cout<<ans<<":"<<endl;
        // for(int i=1;i<=n;i++)
        //     cout<<R[i]<<","<<tag[i]<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[B[i]])continue;
        vis[B[i]]=true;
        tag[k]=B[i];
        dfs(k+1);
        vis[B[i]]=false;
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
int f(int x)
{
    return (x-1+2*n)%(2*n)+1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=2*n;i++)
        if(s[i]=='R')R[++cnt]=i;
        else B[++tot]=i;
    int tmp=0;
    for(int i=1;i<=2*n;i++)
        if(s[i]!=s[f(i-1)])tmp++;
    if(n>6&&tmp==2)ans=qpow(2,n-2);
    else dfs(1);
    cout<<ans<<endl;
    return 0;
}