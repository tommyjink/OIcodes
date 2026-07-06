#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=400005,M=4000005;
int n,m,tot,head[M],to[M],nxt[M],rhead[M],rto[M],rnxt[M],cnt1,cnt2;
int vis[M],col[M],ord[M],sz,sta[M],top;
struct node
{
    int u,e;
};
int id(int x,int y)
{
    return ((x-1)<<1)|y;
}
int rev(int x)
{
    return x^1;
}
int P(int x)
{
    return x*2-1;
}
int Q(int x)
{
    return x*2;
}
void add1(int x,int y)
{
    to[cnt1]=y;
    nxt[cnt1]=head[x];
    head[x]=cnt1++;
}
void add2(int x,int y)
{
    rto[cnt2]=y;
    rnxt[cnt2]=rhead[x];
    rhead[x]=cnt2++;
}
void add(int x,int y)
{
    add1(x,y);
    add2(y,x);
}
void ins(int x,int y)
{
    add(rev(x),y);
    add(rev(y),x);
}
void dfs1(int s)
{
    static node q[M];
    int l=1,r=1;
    q[1]=(node){s,head[s]};
    vis[s]=1;
    while(l<=r)
    {
        int x=q[r].u;
        int &e=q[r].e;
        while(e!=-1&&vis[to[e]])e=nxt[e];
        if(e==-1)
        {
            ord[++sz]=x;
            r--;
            continue;
        }
        int v=to[e];
        e=nxt[e];
        vis[v]=1;
        q[++r]=(node){v,head[v]};
    }
}
void dfs2(int s,int c)
{
    top=0;
    sta[++top]=s;
    col[s]=c;
    while(top)
    {
        int x=sta[top--];
        for(int i=rhead[x];i!=-1;i=rnxt[i])
        {
            int v=rto[i];
            if(col[v])continue;
            col[v]=c;
            sta[++top]=v;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(head,-1,sizeof(head));
    memset(rhead,-1,sizeof(rhead));
    cin>>n>>m;
    tot=2*n;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(z==0)
        {
            ins(id(P(x),0),id(P(y),1));
            ins(id(Q(x),0),id(Q(y),1));
        }
        else
        {
            ins(id(P(x),1),id(Q(x),1));
            ins(id(P(x),1),id(Q(y),0));
            ins(id(P(y),0),id(Q(x),1));
            ins(id(P(y),0),id(Q(y),0));
        }
    }
    int lim=tot*2;
    for(int i=0;i<lim;i++)
        if(!vis[i])dfs1(i);
    int scc=0;
    for(int i=lim;i>=1;i--)
        if(!col[ord[i]])dfs2(ord[i],++scc);
    for(int i=1;i<=tot;i++)
        if(col[id(i,0)]==col[id(i,1)])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        int a=(col[id(P(i),1)]>col[id(P(i),0)]);
        int b=(col[id(Q(i),1)]>col[id(Q(i),0)]);
        cout<<"DABC"[a*2+b];
    }
    cout<<endl;
    return 0;
}
