
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N=1e6+10;

int n,d[N],f[N],fa[N];
int id[N],c[N],siz[N];
vector<int> g[N];

bool cmp(int x,int y)
{
    return d[x]<d[y];
}

bool dfs(int x)
{
    for(int v:g[x])
    {
        f[v]=f[x]-siz[v]+(n-siz[v]);
        if(!dfs(v))return false;
    }
    return f[x]==d[x];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>d[i],id[i]=i,siz[i]=1,c[i]=d[i];

    sort(id+1,id+1+n,cmp);
    sort(c+1,c+1+n);

    int sum=0;

    for(int now=n;now>=2;now--)
    {
        int x=id[now];

        int df=d[x]+2*siz[x]-n;

        int p=lower_bound(c+1,c+1+n,df)-c;

        if(p>=now || c[p]!=df)
        {
            cout<<-1;
            return 0;
        }

        fa[x]=id[p];

        siz[fa[x]]+=siz[x];

        g[fa[x]].push_back(x);

        sum+=siz[x];
    }

    f[id[1]]=sum;

    if(dfs(id[1]))
    {
        for(int i=2;i<=n;i++)
        {
            cout<<id[i]<<" "<<fa[id[i]]<<endl;
        }
    }
    else cout<<-1;

    return 0;
}
