#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=35;
int n,m,a[N],id[N],num=0,L[N],R[N],f[N][M+5],dep[N];
int head[N],tot=0,idd[N],cnt=0,lazy[N],ld[N],rd[N],dv[N],sav[N];
vector<int> V[N];
struct node
{
    int from,to,next;
}e[N*2];
struct Tree
{
    int l,r,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
}
void pushdown(int k)
{
    t[k*2].val+=(t[k*2].r-t[k*2].l+1)*lazy[k];
    t[k*2+1].val+=(t[k*2+1].r-t[k*2+1].l+1)*lazy[k];
    lazy[k*2]+=lazy[k];
    lazy[k*2+1]+=lazy[k];
    lazy[k]=0;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=a[idd[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        lazy[k]+=d;
        t[k].val+=(t[k].r-t[k].l+1)*d;
        return;
    }
    pushdown(k);
    modify(k*2,l,r,d);
    modify(k*2+1,l,r,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return query(k*2,l,r)+query(k*2+1,l,r);
}
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa,int d)
{
    L[x]=id[x]=++num;
    f[x][0]=fa;
    dep[x]=d;
    V[d].push_back(x);
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x,d+1);
    }
    R[x]=num;
}
void init()
{
    for(int i=1;i<M;i++)
        for(int j=1;j<=n;j++)
            f[j][i]=f[f[j][i-1]][i-1];
    for(int i=1;i<=n;i++)
    {
        if(V[i].size())ld[i]=cnt+1;
        for(auto j:V[i])
            idd[++cnt]=j,dv[cnt]=id[j],sav[j]=cnt;
        if(V[i].size())rd[i]=cnt;
    }
}
int jump(int x,int dis)
{
    if(dis>=dep[x])return 0;
    for(int i=M-1;i>=0;i--)
        if(dis>=(1ll<<i))
            x=f[x][i],dis-=(1ll<<i);
    return x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0,1);
    init();
    build(1,1,n);
    // cout<<"id:\n";
    // for(int i=1;i<=n;i++)
    //     cout<<id[i]<<" ";
    // cout<<endl;
    // cout<<"idd:\n";
    // for(int i=1;i<=n;i++)
    //     cout<<idd[i]<<" ";
    // cout<<endl;
    // cout<<"dv:\n";
    // for(int i=1;i<=n;i++)
    //     cout<<dv[i]<<" ";
    // cout<<endl;
    // cout<<"(ld,rd):\n";
    // for(int i=1;i<=n;i++)
    //     printf("(%lld,%lld) ",ld[i],rd[i]);
    // cout<<endl;
    while(m--)
    {
        // for(int i=1;i<=n;i++)
        //     cout<<query(1,sav[i],sav[i])<<" ";
        // cout<<endl;
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y,z;
            cin>>x>>y>>z;
            int d1=dep[x]+y;
            int v2=jump(x,y);
            if(d1<N&&V[d1].size())
            {
                int p1=lower_bound(dv+ld[d1],dv+rd[d1]+1,L[x])-dv;
                int p2=lower_bound(dv+ld[d1],dv+rd[d1]+1,R[x]+1)-dv-1;
                if(p1<=p2)modify(1,p1,p2,z);
            }
            if(v2&&y)
            {
                modify(1,sav[v2],sav[v2],z);
            }
        }
        else
        {
            int x,y;
            cin>>x>>y;
            int d1=dep[x]+y;
            int v2=jump(x,y);
            int res=0;
            if(d1<N&&V[d1].size())
            {
                int p1=lower_bound(dv+ld[d1],dv+rd[d1]+1,L[x])-dv;
                int p2=lower_bound(dv+ld[d1],dv+rd[d1]+1,R[x]+1)-dv-1;
                if(p1<=p2)res+=query(1,p1,p2);
            }
            if(v2&&y)
            {
                // cout<<v2<<"!"<<endl;
                res+=query(1,sav[v2],sav[v2]);
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
/*
5 5
6 8 4 10 6
2 1
3 2
4 1
5 4
1 1 2 7
2 4 1
2 2 0
1 2 1 4
2 1 2

19
8
28
*/