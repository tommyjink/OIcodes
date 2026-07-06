#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ls(x) t[x].l
#define rs(x) t[x].r
using namespace std;
const int N=1e6+10;
int n,m,tot,x,y,z,rt;
struct node
{
    int l,r,val,pri,siz,rev;
}t[N];
int add(int k)
{
    t[++tot]=(node){0,0,k,rand(),1,0};
    return tot;
}
void pushup(int now)
{
    t[now].siz=t[ls(now)].siz+t[rs(now)].siz+1;
}
void pushdown(int now)
{
    if(t[now].rev)
    {
        t[now].rev=0;
        t[ls(now)].rev^=1;
        t[rs(now)].rev^=1;
        swap(ls(ls(now)),rs(ls(now)));
        swap(ls(rs(now)),rs(rs(now)));  
    }
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
    if(!now){x=y=0;return;}
    pushdown(now);
    if(t[ls(now)].siz+1<=k)
    {
        x=now;
        split(rs(x),k-t[ls(now)].siz-1,rs(x),y);
        pushup(x);
    }
    else
    {
        y=now;
        split(ls(y),k,x,ls(y));
        pushup(y);
    }
}
void addrev(int l,int r)
{
    split(rt,l-1,x,y);
    split(y,r-l+1,y,z);
    t[y].rev^=1;
    swap(ls(y),rs(y));
    rt=merge(x,merge(y,z));
}
void print(int now)
{
    if(!now)return;
    pushdown(now);
    print(ls(now));
    cout<<t[now].val<<" ";
    print(rs(now));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        rt=merge(rt,add(i));
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        addrev(l,r);
    }
    print(rt);
    return 0;
}