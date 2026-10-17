#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ls(x) t[x].l
#define rs(x) t[x].r
using namespace std;
const int N=1e6+10;
int n,tot=0,A,B,rt;
struct node1{int a,b;}a[N];
bool cmp(node1 x,node1 y){return x.b>y.b;}
struct node
{
    int l,r,rd,val,siz,lazy,sum;
}t[N*2];
int add(int val)
{
    t[++tot]=(node){0,0,rand(),val,1,0,val};
    return tot;
}
void pushdown(int x)
{
    if(t[x].lazy)
    {
        if(ls(x))
        {
            t[ls(x)].lazy+=t[x].lazy;
            t[ls(x)].val+=t[x].lazy;
            t[ls(x)].sum+=t[x].lazy*t[ls(x)].siz;
        }
        if(rs(x))
        {
            t[rs(x)].lazy+=t[x].lazy;
            t[rs(x)].val+=t[x].lazy;
            t[rs(x)].sum+=t[x].lazy*t[rs(x)].siz;
        }
        t[x].lazy=0;
    }
}
void pushup(int x)
{
    t[x].siz=t[ls(x)].siz+t[rs(x)].siz+1;
    t[x].sum=t[ls(x)].sum+t[rs(x)].sum+t[x].val;
}
int merge(int x,int y)
{
    if(!x||!y)return x+y;
    if(t[x].rd<t[y].rd)
    {
        pushdown(x);
        rs(x)=merge(rs(x),y);
        pushup(x);
        return x;
    }
    else
    {
        pushdown(y);
        ls(y)=merge(x,ls(y));
        pushup(y);
        return y;
    }
}
void split(int now,int &x,int &y,int k)
{
    if(!now){x=y=0;return;}
    pushdown(now);
    int siz=t[ls(now)].siz+1;
    if(siz>k)
    {
        y=now;
        split(ls(now),x,ls(y),k);
    }
    else
    {
        x=now;
        split(rs(now),rs(now),y,k-siz);
    }
    pushup(now);
}
int findq(int x,int pre)
{
    if(!x)return -1;
    pushdown(x);
    int k=t[ls(x)].siz+pre+1;
    if(t[x].val>=k*B-A)
    {
        int q=findq(ls(x),pre);
        if(q==-1)return k;
        return q;
    }
    else return findq(rs(x),k);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].a;
    for(int i=1;i<=n;i++)cin>>a[i].b;
    sort(a+1,a+1+n,cmp);
    rt=add(a[1].b-a[1].a);
    for(int i=2;i<=n;i++)
    {
        A=a[i].a,B=a[i].b;
        int q=findq(rt,0);
        if(q==-1)q=i;
        int x,y;
        split(rt,x,y,q-1);
        t[y].lazy+=B;
        t[y].sum+=B*t[y].siz;
        t[y].val+=B;
        rt=merge(x,merge(add(q*B-A),y));
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans+=a[i].a;
    A=0,B=0;
    int q=findq(rt,0);
    if(q==-1)ans+=t[rt].sum;
    else
    {
        int x,y;
        split(rt,x,y,q-1);
        ans+=t[x].sum;
    }
    cout<<ans<<endl;
    return 0;
}