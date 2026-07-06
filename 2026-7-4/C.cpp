#include<bits/stdc++.h>
#define int long long
#define ls(x) t[x].l
#define rs(x) t[x].r
#define endl "\n"
using namespace std;
const int N=1e6+10;
int _c,n,a[N],tot=0;
int rt,x,y,z;
struct node
{
    int l,r,val,pri,siz;
}t[N];
int add(int d)
{
    t[++tot]=(node){0,0,d,rand(),1};
    return tot;
}
void pushup(int x)
{
    t[x].siz=t[ls(x)].siz+t[rs(x)].siz+1;
}
int merge(int x,int y)
{
    if(!x||!y)return x+y;
    if(t[x].pri<t[y].pri)
    {
        rs(x)=merge(rs(x),y);
        pushup(x);
        return x;
    }
    else
    {
        ls(y)=merge(x,ls(y));
        pushup(y);
        return y;
    }
}
void split(int now,int k,int &x,int &y)
{
    if(!now){x=y=0;return;}
    if(t[now].val<=k)
    {
        x=now;
        split(rs(x),k,rs(x),y);
        pushup(x);
    }
    else
    {
        y=now;
        split(ls(y),k,x,ls(y));
        pushup(y);
    }
}
void ins(int d)
{
    split(rt,d,x,y);
    rt=merge(merge(x,add(d)),y);
}
void del(int d)
{
    split(rt,d-1,x,y);
    split(y,d,y,z);
    y=merge(ls(y),rs(y));
    rt=merge(merge(x,y),z);
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
int rnk(int d)
{
    split(rt,d-1,x,y);
    int res=t[x].siz+1;
    rt=merge(x,y);
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    srand(time(0));
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {

    }
    return 0;
}