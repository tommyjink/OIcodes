#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=60;
int n,m,q,v,x[N],y[N],z[N],tag[N];
int head[N],tot=0,col[M+10][N];
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
void init()
{
    memset(head,0,sizeof(head));
    tot=0;
}
void dfs(int x,int d,int num)
{
    col[num][x]=d;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(col[num][v])continue;
        dfs(v,d,num);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q>>v;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i]>>z[i];
        if(z[i]<v)tag[i]=false;
        else tag[i]=true;
    }
    int i;
    for(i=M;(1ll<<(i-1))>v;i--)
    {
        init();
        for(int j=1;j<=m;j++)
        {
            if(z[j]&(1ll<<(i-1)))
                add(x[j],y[j],z[j]),
                add(y[j],x[j],z[j]);
        }
        int tt=0;
        for(int j=1;j<=n;j++)
            if(!col[i][j])dfs(j,++tt,i);
    }
    for(;i>=1;i--)
    {
        init();
        if(v&(1ll<<(i-1)))
        {
            for(int j=1;j<=m;j++)
                if(!(z[j]&(1ll<<(i-1))))
                    tag[j]=false;
        }
        else
        {
            for(int j=1;j<=m;j++)
                if((z[j]&(1ll<<(i-1)))&&tag[j])
                    add(x[j],y[j],z[j]),
                    add(y[j],x[j],z[j]);
            int tt=0;
            for(int j=1;j<=n;j++)
                if(!col[i][j])dfs(j,++tt,i);
        }
    }
    init();
    for(int i=1;i<=m;i++)
        if(tag[i])
            add(x[i],y[i],z[i]),
            add(y[i],x[i],z[i]);
    int tt=0;
    for(int j=1;j<=n;j++)
        if(!col[0][j])dfs(j,++tt,0);
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int ans=0;
        for(int i=0;i<=M;i++)
            if(col[i][u]&&col[i][v]&&col[i][u]==col[i][v])
                ans=1;
        if(ans)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}