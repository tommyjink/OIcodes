#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=300005,P=1e9+7;
int n,m,x[N],v[N],cnt=0,f[N],g[N],c[N];
struct node{int x,v,id;}a[N];
bool cmp(node x,node y){return x.x*y.v<y.x*x.v;}
inline int mod(int x){return x<0?(x%P+P)%P:x%P;}
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
int inv(int x){return qpow(x,P-2);}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=m;i++)cin>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[++cnt]={-x[i],v[j],j};
    sort(a+1,a+1+cnt,cmp);
    int ans=0,k=(1+m)/2;
    g[0]=f[0]=1;
    for(int i=1;i<=cnt;i++)
    {
        int now=a[i].id;
        int A=n-c[now],B=c[now],invA=inv(A);
        g[0]=f[0]*invA%P;
        for(int i=1;i<=m;i++)
            g[i]=mod(f[i]-B*g[i-1]%P)*invA%P;
        f[0]=mod(f[0]-g[0]);
        for(int i=1;i<=m;i++)
            f[i]=mod(f[i]+g[i-1]-g[i]);
        ans=(ans+(a[i].x*inv(a[i].v)%P)*g[k-1]%P)%P;
        c[now]++;
        // cout<<ans<<endl;

    }
    cout<<ans<<endl;
    return 0;
}