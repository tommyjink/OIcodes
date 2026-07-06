#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m,x[N],y[N],in[N],minn=1,fa[N];
map<pii,int> mp;
int getfa(int x)
{
    if(x==fa[x])return x;
    else return x=getfa(fa[x]);
}
bool merge(int x,int y)
{
    int fx=getfa(x),fy=getfa(y);
    if(fx!=fy){fa[fx]=fy;return true;}
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
        in[x[i]]++,in[y[i]]++;
        mp[pii(x[i],y[i])]=1;
        mp[pii(y[i],x[i])]=1;
    }
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
        if(in[i]<minn)minn=i;
    for(int i=1;i<=n;i++)
        if(!mp[pii(minn,i)])
            merge(minn,i);
    for(int i=1;i<=n;i++)
        if(getfa(i)!=getfa(minn))
            for(int j=1;j<=n;j++)
                if(!mp[pii(i,j)])
                    if(merge(i,j))break;
    int ans=0;
    for(int i=1;i<=n;i++)
        if(i==fa[i])ans++;
    cout<<ans-1<<endl;
    return 0;
}