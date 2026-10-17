#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N =1e6+10,P=1e9+7;
int n,a[N],fa[N],siz[N];
vector<int> g[N];
int getfa(int x)
{
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans=0;
    for(int i=1;i<=n;i++)a[i]=i;
    while(next_permutation(a+1,a+1+n))
    {
        for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
        for(int i=1;i<=n;i++)
        {
            for(int v:g[i])
            {
                int x=getfa(a[i]);
                int y=getfa(v);
                if(x==y)continue;
                fa[x]=y;
                siz[y]+=siz[x];
            }
            ans=(ans+siz[a[i]])%P;
        }
    }
    cout<<ans<<endl;
    return 0;
}