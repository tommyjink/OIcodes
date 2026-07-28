#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4e5+10,INF=1e16;
int n,head[N],tot,son[N],dep[N],dmax[N],ans[N];
int w[N],val[N],h[N];
string s;
struct node1
{
    int to,next;
}e[N*2];
struct node
{
    vector<int> f;
    int tag,mov,fix;
};
void add(int x,int y)
{
    e[++tot]=(node1){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    dmax[x]=dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        dmax[x]=max(dmax[x],dmax[v]);
        if(!son[x]||dmax[son[x]]<dmax[v])son[x]=v;
    }
    h[x]=dmax[x]-dep[x]+1;
}
void dfs1(int x,int fa,node &now)
{
    if(now.f.empty())
    {
        now.f.assign(4*h[x]+20,-INF);
        now.mov=2*h[x]+10;
        now.tag=0;
        now.fix=-h[x]-2;
    }

    if(son[x])
    {
        dfs1(son[x],x,now);
        now.mov-=w[x];
        now.tag+=val[x];
        now.fix+=w[x];
    }

    int p=w[x];
    int nv=val[x]-now.tag;
    if(now.f[now.mov+p]<nv)
    {
        now.f[now.mov+p]=nv;
        now.fix=max(now.fix,p);
    }

    while(now.fix>0)
    {
        int p=now.fix-1;
        now.f[now.mov+p]=max(now.f[now.mov+p],
                              now.f[now.mov+p+1]);
        now.fix--;
    }

    if(now.f[now.mov]>-INF/2)
        ans[x]=max(ans[x],now.f[now.mov]+now.tag);

    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||v==son[x])continue;

        node tmp;
        dfs1(v,x,tmp);

        while(now.fix>-h[v])
        {
            int p=now.fix-1;
            now.f[now.mov+p]=max(now.f[now.mov+p],
                                  now.f[now.mov+p+1]);
            now.fix--;
        }

        while(tmp.fix>-h[v])
        {
            int p=tmp.fix-1;
            tmp.f[tmp.mov+p]=max(tmp.f[tmp.mov+p],
                                  tmp.f[tmp.mov+p+1]);
            tmp.fix--;
        }

        for(int j=-h[v];j<=h[v];j++)
        {
            int x1=now.f[now.mov-j];
            int x2=tmp.f[tmp.mov+j];

            if(x1>-INF/2&&x2>-INF/2)
                ans[x]=max(ans[x],
                    x1+now.tag+x2+tmp.tag);
        }

        for(int j=-h[v];j<=h[v];j++)
        {
            int x2=tmp.f[tmp.mov+j];
            if(x2<=-INF/2)continue;

            int p=j+w[x];
            int nv=x2+tmp.tag+val[x]-now.tag;

            if(now.f[now.mov+p]<nv)
            {
                now.f[now.mov+p]=nv;
                now.fix=max(now.fix,p);
            }
        }

        while(now.fix>0)
        {
            int p=now.fix-1;
            now.f[now.mov+p]=max(now.f[now.mov+p],
                                  now.f[now.mov+p+1]);
            now.fix--;
        }

        if(now.f[now.mov]>-INF/2)
            ans[x]=max(ans[x],now.f[now.mov]+now.tag);
    }
}
void solve()
{
    cin>>n>>s;
    s=" "+s;

    for(int i=0;i<=n;i++)
        head[i]=0,ans[i]=-INF,dmax[i]=0,son[i]=0,dep[i]=0;

    tot=0;

    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++)
        if(s[i]-'0'==0)w[i]=1,val[i]=-1;
        else w[i]=-1,val[i]=3;

    node tmp1;
    dfs1(1,0,tmp1);

    for(int i=1;i<=n;i++)
        if(s[i]-'0'==1)w[i]=1,val[i]=-1;
        else w[i]=-1,val[i]=3;

    node tmp2;
    dfs1(1,0,tmp2);

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)solve();

    return 0;
}