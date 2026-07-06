#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[10],tot,head[N],f[N][21];
int dep[N],val[N];
struct node
{
    int to,next,val;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    // cout<<x<<"!"<<endl;
    f[x][0]=fa;
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        val[v]=val[x]+e[i].val;
        dfs(v,x);
    }
}
void init()
{
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            f[j][i]=f[f[j][i-1]][i-1];
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
int cal(int x,int y)
{
    int o=lca(x,y);
    return val[x]+val[y]-2*val[o];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x++,y++;
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0);
    init();
    // for(int i=1;i<=n;i++)
    //     cout<<val[i]<<" ";
    // cout<<endl;
    // while(1)
    // {
    //     int x,y;
    //     cin>>x>>y;
    //     cout<<lca(x,y)<<endl;
    // }
    int q;
    cin>>q;
    while(q--)
    {
        int ans=0;
        for(int i=1;i<=5;i++)
            cin>>a[i],a[i]++;
        int o=a[1];
        for(int i=1;i<=5;i++)
            o=lca(o,a[i]);
        for(int i=1;i<=5;i++)
            ans+=cal(a[i],o);
        for(int i=1;i<=5;i++)
            for(int j=1;j<i;j++)
                ans-=cal(lca(a[i],a[j]),o);
        for(int i=1;i<=5;i++)
            for(int j=1;j<i;j++)
                for(int k=1;k<j;k++)
                    ans+=cal(lca(a[i],lca(a[j],a[k])),o);
        for(int i=1;i<=5;i++)
            for(int j=1;j<i;j++)
                for(int k=1;k<j;k++)
                    for(int p=1;p<k;p++)
                        ans-=cal(lca(a[i],lca(a[j],lca(a[k],a[p]))),o);
        cout<<ans<<endl;
    }
    return 0;
}

/*
5
0 1 1
1 2 2
2 3 3
3 4 4
1
4 0 3 1 2

10



6
4 0 4
0 1 2
1 3 9
3 5 1
3 2 5
2
4 0 3 5 2
0 4 1 3 5
*/