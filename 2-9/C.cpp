#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,tot=0,head[N],mx[N],cmx[N],ccmx[N];
int sond[N],ans=0,mxnum[N],cmxnum[N],ccmxnum[N];
int mxsond[N],cmxsond[N];
struct node
{
    int to,next;
}e[N*4];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        sond[x]=max(sond[x],sond[v]);
    }
    int num=0,cnum=0,ccnum=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(num==0||mx[v]+1>mx[x])
        {
            mx[x]=mx[v]+1;
            num=v;
        }
    }   
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||v==num)continue;
        if(cnum==0||mx[v]+1>cmx[x])
        {
            cmx[x]=mx[v]+1;
            cnum=v;
        }
    }
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||v==num||v==cnum)continue;
        if(ccnum==0||mx[v]+1>ccmx[x])
        {
            ccmx[x]=mx[v]+1;
            ccnum=v;
        }
    }
    mxnum[x]=num,cmxnum[x]=cnum,ccmxnum[x]=ccnum;
    sond[x]=max(sond[x],mx[x]+cmx[x]+1);
    num=0,cnum=0;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(num==0||sond[v]>sond[num])
            num=v;
    }   
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa||v==num)continue;
        if(cnum==0||sond[v]>sond[cnum])
            cnum=v;
    }
    mxsond[x]=num,cmxsond[x]=cnum;
    ans=max(ans,sond[num]+sond[cnum]);
    ans=max(ans,sond[x]);
}
void dfs1(int x,int fa,int now)
{
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(v==mxnum[x])
        {
            dfs1(v,x,max(now+1,cmx[x]+1));
        }
        else dfs1(v,x,max(now+1,mx[x]+1));
    }
    if(mxnum[x]==mxsond[x])
    {
        ans=max(ans,cmx[x]+now+1+sond[mxsond[x]]);
        ans=max(ans,mx[x]+now+1+sond[cmxsond[x]]);
        // if(cmx[x]+now+1+sond[mxsond[x]]==14)cout<<x<<","<<now<<endl;
    }
    else
    {
        ans=max(ans,mx[x]+now+1+sond[mxsond[x]]);
    }
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        if(v==mxnum[x])
        {
            ans=max(ans,cmx[x]+ccmx[x]+1+sond[v]);
        }
        else if(v==cmxnum[x])
        {
            ans=max(ans,mx[x]+ccmx[x]+1+sond[v]);
        }
        else ans=max(ans,mx[x]+cmx[x]+1+sond[v]);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    dfs1(1,0,0);
    // for(int i=1;i<=n;i++)
    //     cout<<mx[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<cmx[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<sond[i]<<" ";
    // cout<<endl;
    cout<<ans-1<<endl;
    return 0;
}