#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4e5+10,M=25;
int n,head[N],tot=0,fa[N][M+5],siz[N],ans[N],dep[N],tag[N],sl=1,sr=1;
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int f,int d)
{
    fa[x][0]=f;
    siz[x]=1;
    dep[x]=d;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==f)continue;
        dfs(v,x,d+1);
        siz[x]+=siz[v];
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=M;i>=0;i--)
        if(dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if(x==y)return x;
    for(int i=M;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int cal(int l,int r)
{
    // cout<<l<<"!"<<r<<endl;
    if(l==1)return siz[r]*(siz[l]-siz[sr]);
    if(r==1)return siz[l]*(siz[r]-siz[sl]);
    return siz[l]*siz[r];
}
void solve()
{
    tot=0;
    sl=sr=1;
    cin>>n;
    for(int i=1;i<=n+10;i++)
        tag[i]=ans[i]=head[i]=0;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x+1,y+1);
        add(y+1,x+1);
    }
    dfs(1,0,1);
    for(int i=1;i<M;i++)
        for(int j=1;j<=n;j++)
            fa[j][i]=fa[fa[j][i-1]][i-1];
    int l=1,r=1,tmp=1;
    ans[1]=0;
    for(int i=head[1];i;i=e[i].next)
    {
        int v=e[i].to;
        ans[1]+=siz[v]*tmp;
        tmp+=siz[v];
    }
    tag[1]=true;
    for(int i=2;i<=n;i++)
    {
        if(tag[i])
            ans[i]=cal(l,r);
        else if(lca(l,i)==l&&lca(r,i)==1)
        {
            int now=i;
            while(!tag[now])
            {
                if(dep[now]==2)
                    sl=now;
                tag[now]=true,now=fa[now][0];
            }
            l=i;
            ans[i]=cal(l,r);
        }
        else if(lca(r,i)==r&&lca(l,i)==1)
        {
            int now=i;
            while(!tag[now])
            {
                if(dep[now]==2)
                    sr=now;
                tag[now]=true,now=fa[now][0];
            }
            r=i;
            ans[i]=cal(l,r);
        }
        else break;
    }
    ans[0]=n*(n-1)/2;
    for(int i=0;i<=n;i++)
        cout<<ans[i]-ans[i+1]<<" ";
    cout<<endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
/*
2
4
0 1
0 2
2 3
2
1 0
*/