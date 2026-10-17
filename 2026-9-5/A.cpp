#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,M=2e5+10,B=450;
int n,m,q,a[N],head[N],tot,deg[N],id[N],cnt;
int hhead[N],htot,sum[N],vis[N],b[N],num[N],on[N],ans;

struct node
{
    int to,next;
}e[M];

struct node1
{
    int to,next,val;
}g[M];

void add(int x,int y)
{
    e[++tot]={y,head[x]};
    head[x]=tot;
}

void addh(int x,int y,int z)
{
    g[++htot]={y,hhead[x],z};
    hhead[x]=htot;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++)
        if(a[i]!=a[i+1])
        {
            add(a[i],a[i+1]);
            add(a[i+1],a[i]);
            deg[a[i]]++;
            deg[a[i+1]]++;
        }
    deg[a[1]]++;
    deg[a[n]]++;
    for(int i=1;i<=n;i++)
        if(deg[i]>B)id[i]=++cnt;
    for(int i=1;i<=n;i++)
        if(id[i])
        {
            int sz=0;
            for(int j=head[i];j;j=e[j].next)
            {
                int x=e[j].to;
                if(!vis[x])vis[x]=1,b[++sz]=x;
                num[x]++;
            }
            for(int j=1;j<=sz;j++)
            {
                int x=b[j];
                addh(x,id[i],num[x]);
                vis[x]=num[x]=0;
            }
        }
    while(q--)
    {
        int x,res=0;
        cin>>x;
        if(id[x])res=sum[id[x]];
        else
            for(int i=head[x];i;i=e[i].next)
                res+=on[e[i].to];
        if(on[x])ans+=2*res-deg[x];
        else ans+=deg[x]-2*res;
        int d=on[x]?-1:1;
        for(int i=hhead[x];i;i=g[i].next)
            sum[g[i].to]+=d*g[i].val;
        on[x]^=1;
        cout<<ans/2<<endl;
    }
    return 0;
}
