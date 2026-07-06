#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ls(x) t[x].l
#define rs(x) t[x].r
using namespace std;
const int N=1e6+10;
int n,m,id[N],tot,rt,x,y,z,w;
struct node
{
    int l,r,val,siz,pri,fa;
}t[N];
int add(int k)
{
    t[++tot]=(node){0,0,k,1,rand(),0};
    return tot;
}
void pushup(int now)
{
    t[now].siz=t[ls(now)].siz+t[rs(now)].siz+1;
    if(ls(now))t[ls(now)].fa=now;
    if(rs(now))t[rs(now)].fa=now;
}
int merge(int x,int y)
{
    if(!x||!y)return x+y;
    if(t[x].pri<t[y].pri)
    {
        rs(x)=merge(rs(x),y);
        pushup(x);
        t[x].fa=0;
        return x;
    }
    else
    {
        ls(y)=merge(x,ls(y));
        pushup(y);
        t[y].fa=0;
        return y;
    }
}
void split(int now,int k,int &x,int &y)
{
    if(!now){x=y=0;return;}
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
    if(x)t[x].fa=0;
    if(y)t[y].fa=0;
}
int rnk(int k)
{
    int now=id[k],res=t[ls(now)].siz+1,f;
    while(f=t[now].fa)
    {
        if(now==rs(f))res+=t[ls(f)].siz+1;
        now=f;
    }
    return res;
}
int kth(int k)
{
    split(rt,k-1,x,y);
    split(y,1,y,z);
    int res=t[y].val;
    rt=merge(x,merge(y,z));
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        id[x]=add(x);
        rt=merge(rt,id[x]);
    }
    while(m--)
    {
        string op;cin>>op;
        if(op[0]=='T')
        {
            int k;cin>>k;
            int res=rnk(k);
            split(rt,res-1,x,y);
            split(y,1,y,z);
            rt=merge(y,merge(x,z));
        }
        if(op[0]=='B')
        {
            int k;cin>>k;
            int res=rnk(k);
            split(rt,res-1,x,y);
            split(y,1,y,z);
            rt=merge(merge(x,z),y);
        }
        if(op[0]=='I')
        {
            int k,t;
            cin>>k>>t;
            int res=rnk(k);
            if(t==0)continue;
            if(t==1)
            {
                split(rt,res-1,x,y);
                split(y,1,y,z);
                split(z,1,z,w);
                rt=merge(x,merge(merge(z,y),w));
            }
            if(t==-1)
            {
                split(rt,res-2,x,y);
                split(y,1,y,z);
                split(z,1,z,w);
                rt=merge(x,merge(merge(z,y),w));
            }
        }
        if(op[0]=='A')
        {
            int k;cin>>k;
            cout<<rnk(k)-1<<endl;
        }
        if(op[0]=='Q')
        {
            int k;cin>>k;
            cout<<kth(k)<<endl;
        }
    }
    return 0;
}