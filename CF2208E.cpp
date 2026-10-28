#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005,P=998244353;
int n,a[N],f[N][N],g[N][N],h[N],tag[N];
struct node{int l,r;};
bool cmp(node x,node y)
{
    int xx=x.r-x.l+1;
    int yy=y.r-y.l+1;
    if(xx==yy)return x.l<y.l;
    return xx<yy;
}
vector<node> b;
void cal(int l,int r)
{
    cout<<l<<","<<r<<endl;
    g[l][0]=f[l][0]=1;
    for(int i=l+1;i<r;i++)
    {   
        if(tag[i])continue;
        if(~a[i])
        {
            for(int j=1;j<=i-l;j++)
            {
                f[i][j]=f[a[i]][j-1]*h[i-1]%P;
                g[i][j]=(g[i][j-1]+f[i][j])%P;
            }
        }
        else
        {
            for(int j=1;j<=i-l;j++)
            {
                f[i][j]=(g[i-1][i-1-l]-g[i-1][max(0ll,j-2)]+P)%P;
                g[i][j]=(g[i][j-1]+f[i][j])%P;
            }
        }
        h[i]=g[i][i-l];
        tag[i]=1;
    }
    g[l][0]=f[l][0]=0;
}
void solve()
{
    cin>>n;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            f[i][j]=g[i][j]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(~a[i])b.push_back({a[i],i});
        tag[i]=0;
    }
    b.push_back({0,n+1});
    sort(b.begin(),b.end(),cmp);
    for(auto [l,r]:b)
        cal(l,r);
    cout<<h[n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}