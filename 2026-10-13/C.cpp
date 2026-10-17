#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,w[N],cnt=0,fa[N];
struct node
{
    int x,y,z;
}e[N];
bool cmp(node x,node y)
{
    return x.z<y.z;
}
void init()
{
    for(int i=0;i<n;i++)fa[i]=i;
}
int getfa(int x)
{
    return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
bool merge(int x,int y)
{
    x=getfa(x);
    y=getfa(y);
    if(x==y)return false;
    fa[x]=y;
    return true;
}
void solve()
{
    cin>>n;
    k=1,cnt=0;
    while(k<n)k<<=1;
    for(int i=0;i<k;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            e[++cnt]={i,j,w[i^j]};
    sort(e+1,e+1+cnt,cmp);
    init();
    cout<<n-1<<endl;
    for(int i=1;i<=cnt;i++)
        if(merge(e[i].x,e[i].y))
            cout<<e[i].x<<" "<<e[i].y<<endl;
}   
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}