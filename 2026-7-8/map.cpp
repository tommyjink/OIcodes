#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=210;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m,k,q,a[N],fa[N];
int a1[M],b1[M],a2[M],b2[M],id[M],tot;
bool f[M][M];

int getid(int x,int y)
{
    return (x-1)*m+y;
}

int get(int x)
{
    if(x==fa[x])return x;
    return fa[x]=get(fa[x]);
}

void merge(int x,int y)
{
    x=get(x),y=get(y);
    if(x!=y)fa[x]=y;
}

int find(int x)
{
    for(int i=1;i<=tot;i++)
        if(id[i]==x)return i;
    id[++tot]=x;
    return tot;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("map.in","r",stdin);
    freopen("map.out","w",stdout);
    cin>>n>>m>>k>>q;
    for(int i=1;i<=n*m;i++)
        fa[i]=i,a[i]=0;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
            if(s[j-1]=='#')a[getid(i,j)]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[getid(i,j)])continue;
            for(int t=0;t<4;t++)
            {
                int x=i+dx[t],y=j+dy[t];
                if(x<1||x>n||y<1||y>m||a[getid(x,y)])continue;
                merge(getid(i,j),getid(x,y));
            }
        }
    }
    for(int i=1;i<=k;i++)
        cin>>a1[i]>>b1[i]>>a2[i]>>b2[i];
    for(int i=1;i<=k;i++)
    {
        int x=get(getid(a1[i],b1[i]));
        int y=get(getid(a2[i],b2[i]));
        x=find(x),y=find(y);
        f[x][y]=true;
    }
    for(int i=1;i<=tot;i++)
        f[i][i]=true;
    for(int k=1;k<=tot;k++)
        for(int i=1;i<=tot;i++)
            for(int j=1;j<=tot;j++)
                f[i][j]|=f[i][k]&f[k][j];
    while(q--)
    {
        int x,y,xx,yy;
        cin>>x>>y>>xx>>yy;
        x=get(getid(x,y)),y=get(getid(xx,yy));
        if(x==y)
        {
            cout<<1<<endl;
            continue;
        }
        int p=0,pp=0;
        for(int i=1;i<=tot;i++)
        {
            if(id[i]==x)p=i;
            if(id[i]==y)pp=i;
        }
        if(p&&pp&&f[p][pp])cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
