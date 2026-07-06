#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int T,a[N],n,num[N],tag[N*4],savx[N],savy[N];
int head[N],tot=0,cnt=0,siz[N],dep[N];
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
    if(tag[k]==1)
    {
        tag[k*2]=tag[k*2+1]=1;
        t[k*2].val=0;
        t[k*2+1].val=0;
    }
    if(tag[k]==2)
    {
        tag[k*2]=tag[k*2+1]=2;
        t[k*2].val=t[k*2].r-t[k*2].l+1;
        t[k*2+1].val=t[k*2+1].r-t[k*2+1].l+1;
    }
}
void Tbuild(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    tag[k]=0;
    if(l==r)
    {
        t[k].val=1;
        return;
    }
    int mid=(l+r)>>1;
    Tbuild(k*2,l,mid);
    Tbuild(k*2+1,mid+1,r);
    pushup(k);
}
void Tset(int k,int l,int r,int mode)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        tag[k]=mode;
        if(mode==1)
            t[k].val=0;
        if(mode==2)
            t[k].val=t[k].r-t[k].l+1;
        return;
    }
    pushdown(k);
    Tset(k*2,l,r,mode);
    Tset(k*2+1,l,r,mode);
    pushup(k);
}
int Tquery(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return Tquery(k*2,l,r)+Tquery(k*2+1,l,r);
}
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa,int d)
{
    num[x]=++cnt,siz[x]=1,dep[x]=d;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x,d+1);
        siz[x]+=siz[v];
    }
}
void init()
{
    tot=0,cnt=0;
    Tbuild(1,1,n);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)
    {
        cin>>n;
        init();
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            savx[i]=x,savy[i]=y;
            if(a[x]<a[y])swap(savx[i],savy[i]);
            add(x,y);
            add(y,x);
        }
        dfs(1,0,1);
        for(int i=1;i<=n-1;i++)
        {
            int x=savx[i],y=savy[i];
            if(a[x]>2*a[y])
            {
                if(dep[x]>dep[y])
                    Tset(1,num[x],num[x]+siz[x]-1,1);
                else Tset(1,1,num[y]-1,1),Tset(1,num[y]+siz[y],n,1);
            }
        }
        cout<<Tquery(1,1,n)<<endl;
        for(int i=1;i<=n;i++)
            head[i]=0;
    }
    return 0;
}
/*
3

3
1 2 3
1 2
2 3

5
3 2 2 2 1
1 2
3 1
4 1
1 5

8
699 673 592 276 600 343 369 374
7 6
8 5
4 6
7 1
7 2
1 8
4 3
*/