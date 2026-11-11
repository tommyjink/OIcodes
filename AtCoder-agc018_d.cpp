#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,tot,head[N],ans=0;
int siz[N],tag[N],w[N];
struct node
{
    int to,next,val,from;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z,x};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    // cout<<x<<"!"<<endl;
    siz[x]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        // cout<<v<<"?"<<endl;
        if(v==fa)continue;
        dfs(v,x);
        w[v]=e[i].val;
        ans+=w[v]*2*min(siz[v],n-siz[v]);
        siz[x]+=siz[v];
    }
    tag[x]=true;
    int tmp=n-siz[x];
    if(tmp>n/2)tag[x]=false;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(siz[v]>n/2)tag[x]=false;
    }

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
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0);
    int cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=tag[i];
    if(cnt==1)
    {
        for(int x=1;x<=n;x++)
        {
            if(tag[x])
            {
            int tmp=1e18;
                for(int i=head[x];i;i=e[i].next)
                {
                    tmp=min(tmp,e[i].val);
                }

            cout<<ans-tmp<<endl;
            return 0;
            }
        }
    }
    else
    {
        for(int i=1;i<=tot;i++)
        {
            if(tag[e[i].from]&&tag[e[i].to])
            {
                cout<<ans-e[i].val<<endl;
                return 0;
            }
        }
    }
    return 0;
}