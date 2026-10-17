#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=6e6+10;
int n,m,C,a[N],s[N],g[N],ans=0;
vector<pii> b[N];
inline int f(int x,int y){return x*(m+1)+y;}
int sum(pii x,pii y)
{
    if(x.first>y.first||x.second>y.second)return -1;
    return s[f(y.first,y.second)]-s[f(y.first,x.second-1)]-
    s[f(x.first-1,y.second)]+s[f(x.first-1,x.second-1)];
}
void cal(int now,int l,int r,int optl,int optr)
{
    if(l>r)return;
    int mid=(l+r)>>1,p=optl,val=-1;
    for(int i=optl;i<=optr;i++)
    {
        int res=sum(b[now][mid],b[now+C][i]);
        if(res>=val)p=i,val=res;
    }
    g[f(b[now][mid].first,b[now][mid].second)]=val;
    ans=max(ans,val);
    cal(now,l,mid-1,optl,p);
    cal(now,mid+1,r,p,optr);
}
void solve()
{
    ans=0;
    cin>>n>>m>>C;
    C/=2;
    C-=2;
    for(int i=2;i<=n+m;i++)
        b[i].clear();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[f(i,j)];
            s[f(i,j)]=a[f(i,j)];
            b[i+j].push_back({i,j});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[f(i,j)]+=s[f(i-1,j)];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[f(i,j)]+=s[f(i,j-1)];
    for(int i=2;i+C<=n+m;i++)
        cal(i,0,b[i].size()-1,0,b[i+C].size()-1);
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[f(i,j)]=0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)solve();
    return 0;
}