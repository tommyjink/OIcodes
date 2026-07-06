#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ls(x) t[x].l
#define rs(x) t[x].r
using namespace std;
const int N=1e6+10;
int n,a[N],tot,rt,x,y,z,b[N];
struct node
{
    int l,r,siz,pri,lazy,val;
}t[N];
void pushup(int x)
{
    t[x].siz=t[ls(x)].siz+t[rs(x)].siz+1;
}
void pushdown(int x)
{
    if(t[x].lazy)
    {
        t[ls(x)].lazy+=t[x].lazy;
        t[rs(x)].lazy+=t[x].lazy;
        t[ls(x)].val+=t[x].lazy;
        t[rs(x)].val+=t[x].lazy;
        t[x].lazy=0;
    }
}
int add(int k)
{
    t[++tot]=(node){0,0,1,rand(),0,k};
    return tot;
}
int merge(int x,int y)
{
    if(!x||!y)return x+y;
    if(t[x].pri<t[y].pri)
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
void split(int now,int k,int &x,int &y)
{
    if(!now){x=y=0;return ;}
    pushdown(now);
    if(t[now].val<=k)
        x=now,split(rs(x),k,rs(x),y);
    else y=now,split(ls(y),k,x,ls(y));
    pushup(now);
}
int kth(int k)
{
    int now=rt;
    while(now)
    {
        int tmp=t[ls(now)].siz+1;
        if(tmp<k)k-=tmp,now=rs(now);
        else if(tmp==k)return t[now].val;
        else now=ls(now);
    }
    return -1;
}
int rnk(int k)
{
    split(rt,k-1,x,y);
    int res=t[x].siz+1;
    rt=merge(x,y);
    return res;
}
void ins(int k)
{
    split(rt,k-1,x,y);
    rt=merge(x,merge(add(k),y));
}
void del(int k)
{
    split(rt,k-1,x,y);
    split(y,k,y,z);
    y=merge(ls(y),rs(y));
    rt=merge(merge(x,y),z);
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],ins(a[i]);
    for(int i=1;i<=n;i++)b[i]=a[i];
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
    {
        
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    int t;cin>>t;
    while(t--)solve();
    return 0;
}