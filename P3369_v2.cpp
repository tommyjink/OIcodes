#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ls(x) t[x].l
#define rs(x) t[x].r
using namespace std;
const int N=1e5+10;
int m,rt,tot=0,x,y,z;
struct node
{
    int l,r,rd,val,siz;
}t[N];
void pushup(int now)
{
    t[now].siz=t[ls(now)].siz+t[rs(now)].siz+1;
}
int newnode(int val)
{
    t[++tot]={0,0,rand(),val,1};
    return tot;
}
void split(int now,int &x,int &y,int k)
{
    if(!now){x=y=0;return;}
    if(t[now].val<=k)
    {
        split(rs(now),rs(now),y,k);
        x=now;
        pushup(x);
    }
    else
    {
        split(ls(now),x,ls(now),k);
        y=now;
        pushup(y);
    }
}
int merge(int x,int y)
{
    if(!x||!y)return x+y;
    if(t[x].rd>t[y].rd)
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
void insert(int val)
{
    split(rt,x,y,val);
    rt=merge(merge(x,newnode(val)),y);
}
void del(int val)
{
    split(rt,x,y,val-1);
    split(y,y,z,val);
    y=merge(ls(y),rs(y));
    rt=merge(merge(x,y),z);
}
int qrk(int x)
{
    int res=0,now=rt;
    while(now)
    {
        int tmp=t[ls(now)].siz+1;
        if(t[now].val<x)res+=tmp,now=t[now].r;
        else now=t[now].l;
    }
    return res+1;
}
int rk(int k)
{
    int now=rt;
    while(now)
    {
        int tmp=t[ls(now)].siz+1;
        if(tmp==k)return t[now].val;
        if(tmp<k)k-=tmp,now=rs(now);
        else now=ls(now);
    }
}
int pre(int val)
{
    split(rt,x,y,val-1);
    int now=x;
    while(rs(now))now=rs(now);
    rt=merge(x,y);
    return t[now].val;
}
int nxt(int val)
{
    split(rt,x,y,val);
    int now=y;
    while(ls(now))now=ls(now);
    rt=merge(x,y);
    return t[now].val;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    cin>>m;
    while(m--)
    {
        int op,x;
        cin>>op>>x;
        if(op==1)
        {
            insert(x);
        }
        else if(op==2)
        {
            del(x);
        }
        else if(op==3)
        {
            cout<<qrk(x)<<endl;
        }
        else if(op==4)
        {
            cout<<rk(x)<<endl;
        }
        else if(op==5)
        {
            cout<<pre(x)<<endl;
        }
        else 
        {
            cout<<nxt(x)<<endl;
        }
    }
    return 0;
}