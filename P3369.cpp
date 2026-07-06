//FHQ模板
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
struct node{int l,r,val,pri,siz;}t[N];
int rt,tot,x,y,z;
int add(int k){t[++tot]={0,0,k,rand(),1};return tot;}
void upd(int x){t[x].siz=t[t[x].l].siz+t[t[x].r].siz+1;}
void split(int now,int k,int &x,int &y)
{
    if(!now){x=y=0;return;}
    if(t[now].val<=k)x=now,split(t[x].r,k,t[x].r,y),upd(x);
    else y=now,split(t[y].l,k,x,t[y].l),upd(y);
}
int merge(int x,int y)
{
    if(!x||!y)return x+y;
    if(t[x].pri<t[y].pri){t[x].r=merge(t[x].r,y),upd(x);return x;}
    else {t[y].l=merge(x,t[y].l),upd(y);return y;}
}
void ins(int k){split(rt,k,x,y),rt=merge(merge(x,add(k)),y);}
void del(int k)
{
    split(rt,k,y,z),split(y,k-1,x,y);
    y=merge(t[y].l,t[y].r),rt=merge(merge(x,y),z);
}
int rnk(int k)
{
    split(rt,k-1,x,y);
    int res=t[x].siz+1;
    rt=merge(x,y);
    return res;
}
int kth(int rk)
{
    int now=rt;
    while(now)
    {
        int sz=t[t[now].l].siz+1;
        if(sz<rk)rk-=sz,now=t[now].r;
        else if(sz==rk)return t[now].val;
        else now=t[now].l;
    }
    return -1;
}
int pre(int k)
{
    split(rt,k-1,x,y);int now=x;
    while(t[now].r)now=t[now].r;
    rt=merge(x,y);return t[now].val;
}
int nxt(int k)
{
    split(rt,k,x,y);int now=y;
    while(t[now].l)now=t[now].l;
    rt=merge(x,y);return t[now].val;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    int q;cin>>q;
    while(q--)
    {
        int op,x;cin>>op>>x;
        if(op==1)ins(x);
        if(op==2)del(x);
        if(op==3)cout<<rnk(x)<<endl;
        if(op==4)cout<<kth(x)<<endl;
        if(op==5)cout<<pre(x)<<endl;
        if(op==6)cout<<nxt(x)<<endl;
    }
    return 0;
}