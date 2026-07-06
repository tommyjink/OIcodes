#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define ls(x) t[x].l
#define rs(x) t[x].r
using namespace std;
const int N=4e6+10,INF=1e16;
int n,m,tot,rt,x,y,z;
struct node
{
    int l,r,siz,pri,sum,val,rev,modi,mx,lmx,rmx;
}t[N];
int add(int k)
{
    t[++tot]=(node){0,0,1,rand(),k,k,0,INF,k,k,k};
    return tot;
}
void addrev(int x)
{
    if(!x)return;
    t[x].rev^=1;
    swap(ls(x),rs(x));
    swap(t[x].lmx,t[x].rmx);
}
void addmodi(int x,int d)
{
    if(!x)return;
    t[x].modi=d;
    if(d<0)t[x].lmx=t[x].rmx=t[x].mx=d;
    else t[x].lmx=t[x].rmx=t[x].mx=d*t[x].siz;
    t[x].val=d;
    t[x].sum=d*t[x].siz;
}
void pushup(int x)
{
    t[x].siz=t[ls(x)].siz+t[rs(x)].siz+1;
    t[x].sum=t[ls(x)].sum+t[rs(x)].sum+t[x].val;
    t[x].mx=max({t[ls(x)].mx,t[rs(x)].mx,max(0,t[ls(x)].rmx)+max(0,t[rs(x)].lmx)+t[x].val});
    t[x].lmx=max(t[ls(x)].lmx,t[ls(x)].sum+t[x].val+max(0,t[rs(x)].lmx));
    t[x].rmx=max(t[rs(x)].rmx,t[rs(x)].sum+t[x].val+max(0,t[ls(x)].rmx));
}
void pushdown(int x)
{
    if(t[x].modi!=INF)
    {
        addmodi(ls(x),t[x].modi);
        addmodi(rs(x),t[x].modi);
        t[x].modi=INF;
    }
    if(t[x].rev)
    {
        addrev(ls(x));
        addrev(rs(x));
        t[x].rev=0;
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
    if(t[ls(now)].siz+1<=k)
    {
        pushdown(now);
        x=now,split(rs(x),k-t[ls(now)].siz-1,rs(x),y);
        pushup(x);
        return;
    }
    else
    {
        pushdown(now);
        y=now,split(ls(y),k,x,ls(y));
        pushup(y);
        return;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    cin>>n>>m;
    t[0].lmx=t[0].mx=t[0].rmx=-INF;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        rt=merge(rt,add(x));
    }
    while(m--)
    {
        string s;
        cin>>s;
        if(s=="INSERT")
        {
            int posi,nn;
            cin>>posi>>nn;
            split(rt,posi,x,y);
            for(int i=1;i<=nn;i++)
            {
                int k;cin>>k;
                x=merge(x,add(k));
            }
            rt=merge(x,y);
        }
        if(s=="DELETE")
        {
            int posi,nn;
            cin>>posi>>nn;
            split(rt,posi-1,x,y);
            split(y,nn,y,z);
            rt=merge(x,z);
        }
        if(s=="MAKE-SAME")
        {
            int posi,nn,c;
            cin>>posi>>nn>>c;
            split(rt,posi-1,x,y);
            split(y,nn,y,z);
            addmodi(y,c);
            rt=merge(x,merge(y,z));
        }
        if(s=="REVERSE")
        {
            int posi,nn;
            cin>>posi>>nn;
            split(rt,posi-1,x,y);
            split(y,nn,y,z);
            addrev(y);
            rt=merge(x,merge(y,z));
        }
        if(s=="GET-SUM")
        {
            int posi,nn;
            cin>>posi>>nn;
            split(rt,posi-1,x,y);
            split(y,nn,y,z);
            cout<<t[y].sum<<endl;
            rt=merge(x,merge(y,z));
        }
        if(s=="MAX-SUM")
        {
            cout<<t[rt].mx<<endl;
        }
    }
    return 0;
}