#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=60;
int n,m,q,v,x[N],y[N],z[N],tag[N],sum=0;
int head[N],tot=0,col[M+10][N],vis[N];
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y,int z)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
void dfs(int x,int d,int num)
{
    col[num][x]=d;
    for(int i=head[x];i;i=e[i].next)
    {
        if(!(tag[(i+1)/2]&&vis[(i+1)/2]))continue;
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
        tag[i]=true,vis[i]=true;
        add(x[i],y[i],z[i]);
        add(y[i],x[i],z[i]);
        sum|=z[i];
    }
    int i;
    for(i=M;(1ll<<(i-1))>v;i--)
    {
        for(int j=1;j<=m;j++)
            if(z[j]&(1ll<<(i-1)))
                tag[i]=true;
            else tag[i]=false;
        int tt=0;
        for(int j=1;j<=n;j++)
            if(!col[i][j])dfs(j,++tt,i);
    }
    for(int i=1;i<=m;i++)
        tag[i]=true;
    for(;i>=1;i--)
    {
        if(v&(1ll<<(i-1)))
        {
            for(int j=1;j<=m;j++)
                if(!(z[j]&(1ll<<(i-1))))
                    tag[j]=false;
        }
        else
        {
            for(int j=1;j<=m;j++)
                if((z[j]&(1ll<<(i-1))))
                    vis[j]=true;
                else vis[j]=false;
            int tt=0;
            for(int j=1;j<=n;j++)
                if(!col[i][j])dfs(j,++tt,i);
        }
    }
    int tt=0;
    for(int j=1;j<=n;j++)
        if(!col[0][j])dfs(j,++tt,0);
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int ans=0;
        for(int i=0;i<=M;i++)
            if((i==0||(sum&(1ll<<(i-1))))&&col[i][u]==col[i][v])
                ans=1,cout<<i<<"!"<<endl;
        if(ans)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}