#define ls(x) tr[(x)].l
#define rs(x) tr[(x)].r
const int N=1e5+5;
struct node {int l,r,key,val,siz;} tr[N];
int rt,idx,x,y,z;
il int add(int key) {tr[++idx]={0,0,key,rand(),1};return idx;}
il void upd(int x) {tr[x].siz=tr[ls(x)].siz+tr[rs(x)].siz+1;}
void split(int now,int key,int &x,int &y)
{
    if(!now) {x=y=0;return;}
    if(tr[now].key<=key) x=now,split(rs(x),key,rs(x),y),upd(x);
    else y=now,split(ls(y),key,x,ls(y)),upd(y);
}
int merge(int x,int y)
{
    if(!x||!y) return x+y;
    if(tr[x].val<tr[y].val) {rs(x)=merge(rs(x),y),upd(x);return x;}
    else {ls(y)=merge(x,ls(y)),upd(y);return y;}
}
il void ins(int key) {split(rt,key,x,y),rt=merge(merge(x,add(key)),y);}
il void del(int key)
{
    split(rt,key,y,z),split(y,key-1,x,y);
    y=merge(ls(y),rs(y)),rt=merge(merge(x,y),z);
}
il int rnk(int key)
{
    split(rt,key-1,x,y); int res=tr[x].siz+1;
    rt=merge(x,y); return res;
}
il int kth(int rk)
{
    int now=rt;
    while(now)
    {
        int sz=tr[ls(now)].siz+1;
        if(sz<rk) rk-=sz,now=rs(now);
        else if(sz==rk) return tr[now].key;
        else now=ls(now);
    }
    assert(false); return 0;
}
il int pre(int key)
{
    split(rt,key-1,x,y); int now=x;
    while(rs(now)) now=rs(now);
    rt=merge(x,y); return tr[now].key;
}
il int nxt(int key)
{
    split(rt,key,x,y); int now=y;
    while(ls(now)) now=ls(now);
    rt=merge(x,y); return tr[now].key;
}