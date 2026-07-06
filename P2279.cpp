#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4;
int n,head[N],tot=0,f[N][5];
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
//f[x][0]:+2    f[x][0]=1+sum{f[v][4]};
//f[x][1]:+1    f[x][1]=min{f[v][0]+sum{f[t][3]}}
//f[x][2]:+0    f[x][2]=min{f[v][1]+sum{f[t][2]}}
//f[x][3]:-1    f[x][3]=sum{f[v][2]}
//f[x][4]:-2    f[x][4]=sum{f[v][3]}
void dfs(int x,int fa)
{
    // cout<<"X:"<<x<<endl;
    f[x][0]=1;
    f[x][1]=f[x][2]=1e12;
    f[x][3]=f[x][4]=0;
    if(head[x]==0)f[x][1]=f[x][2]=1;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        f[x][0]+=f[v][4];
        f[x][3]+=f[v][2];
        f[x][4]+=f[v][3];
    }
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        int res1=f[v][0];
        int res2=f[v][1];
        for(int j=head[x];j;j=e[j].next)
        {
            int t=e[j].to;
            if(t==v||t==fa)continue;
            res1+=f[t][3];
            res2+=f[t][2];
        }
        f[x][1]=min(f[x][1],res1);
        f[x][2]=min(f[x][2],res2);
    }
    for(int i=1;i<=4;i++)
        f[x][i]=min(f[x][i],f[x][i-1]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x;cin>>x;
        add(x,i);
        add(i,x);
        // int x,y;
        // cin>>x>>y;
        // add(x,y);
        // add(y,x);
    }
    dfs(1,0);
    // for(int i=1;i<=10;i++)
    // {
    //     for(int j=0;j<=4;j++)
    //     {
    //         printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
    //     }
    //     cout<<endl;
    // }
    cout<<f[1][2];
    return 0;
}
/*

10
1 2
2 3
3 4
1 5
1 6
5 7
5 8
5 9
9 10

*/