#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,d,b[N],s[N],h[N],num[N],ans[N];
int head[N],tot=0,f[N],tag[N],now=0;
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void addp(int x,int d)
{
    if(tag[s[x]]==0)
        now++;
    tag[s[x]]+=d;
    if(tag[s[x]]==0)
        now--;
}
void dfs(int x,int fa)
{
    addp(x,1);
    ans[x]=now;
    f[x]=fa;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
    }
    addp(x,-1);
}
int cal(int x)
{
    int res=0;
    for(int i=1;i<=n;i++)tag[i]=0;
    while(x)
    {
        if(b[x])
        {
            b[x]--;
            tag[s[x]]++;
            if(tag[s[x]]==1)res++;
        }
        x=f[x];
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>d;
    int bj=1;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]!=d)bj=false;
    }
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=d;i++)cin>>h[i];
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    if(bj) for(int i=1;i<=d;i++)
            cout<<ans[h[i]]<<" ";
    else for(int i=1;i<=d;i++)
            cout<<cal(h[i])<<" ";
    return 0;
}