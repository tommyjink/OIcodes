#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=105,M=10005;
int n,m,s,tot,idx,P=-1,Q;
int a[N],head[N],deg[N],dfn[N],f[N],g[N][N],q[N];
struct node
{
    int to,next,val;
}e[M];

void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}

int gcd(int x,int y)
{
    if(!y)return x;
    return gcd(y,x%y);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s;
    for(int i=1;i<n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        deg[y]++;
    }
    int l=1,r=0;
    for(int i=1;i<=n;i++)
        if(!deg[i])q[++r]=i;
    while(l<=r)
    {
        int x=q[l++];
        dfn[++idx]=x;
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].to;
            deg[y]--;
            if(!deg[y])q[++r]=y;
        }
    }
    memset(f,-1,sizeof(f));
    f[s]=0;
    for(int i=1;i<n;i++)
    {
        memset(g,-1,sizeof(g));
        for(int j=1;j<=n;j++)
        {
            int x=dfn[j];
            f[x]=max(f[x],g[x][0]);
            swap(g[x][0],f[x]);
            if(f[x]!=-1&&f[x]*Q>P*i)
            {
                Q=i;
                P=f[x];
            }
            for(int k=0;k<=i;k++)
            {
                if(g[x][k]==-1)continue;
                for(int o=head[x];o;o=e[o].next)
                {
                    int y=e[o].to,w=e[o].val;
                    int p=(k+w)%(i+1);
                    g[y][p]=max(g[y][p],g[x][k]+a[i]);
                }
            }
        }
    }
    if(P==-1)cout<<-1<<" "<<-1<<endl;
    else
    {
        int d=gcd(P,Q);
        cout<<P/d<<" "<<Q/d<<endl;
    }
    return 0;
}
