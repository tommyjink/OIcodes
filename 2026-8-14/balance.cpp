#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=30;
int n,m,k,tag[N],x[N],y[N];
int fa[N],siz[N];
void init()
{
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)tag[i]=0,siz[i]=1;
}
int getfa(int x)
{
    if(x==fa[x])return x;
    return fa[x]=getfa(fa[x]);
}
void merge(int x,int y)
{
    x=getfa(x);
    y=getfa(y);
    if(x==y)return;
    fa[x]=y;
    siz[y]+=siz[x];
}
bool check(int s)
{
    // cout<<s<<":"<<endl;
    init();
    for(int i=1;i<=m;i++)
    {
        if(s&(1ll<<(i-1)))
        {
            // cout<<x[i]<<' '<<y[i]<<"!"<<endl;
            tag[x[i]]=tag[y[i]]=true;
        }
        else merge(x[i],y[i]);
    }
    int cnt=0,res=0;
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        if(i==fa[i])
        {
            cnt++;
            v.push_back(siz[i]);
        }
    }
    for(int i=1;i<=n;i++)
        if(tag[i])res++;
    if(res!=cnt)return false;
    sort(v.begin(),v.end());
    // for(int i:v)cout<<i<<" ";
    // cout<<"!"<<endl;
    if(abs(v[v.size()-1]-v[0])>k)return false;
    return true;
}
signed main()
{
    freopen("balance.in","r",stdin);
    freopen("balance.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>x[i]>>y[i];
    int ans=0;
    for(int i=1;i<(1ll<<m);i++)
        if(check(i))ans++;
    cout<<ans<<endl;
    return 0;
}