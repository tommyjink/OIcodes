#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ls(x) t[x].l
#define rs(x) t[x].r
using namespace std;
const int N=1e6+10;
int n,mn,x,y,z,tot,tag,rt,ans;
struct node
{
    int l,r,val,pri,siz;
}t[N];
int add(int k)
{
    t[++tot]=(node){0,0,k,rand(),1};
    return tot;
}
void pushup(int now)
{
    t[now].siz=t[ls(now)].siz+t[rs(now)].siz+1;
}
void split(int now,int k,int &x,int &y)
{
    if(!now){x=y=0;return;}
    if(t[now].val<=k)
        x=now,split(rs(x),k,rs(x),y),pushup(now);
    else y=now,split(ls(y),k,x,ls(y)),pushup(now);
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
void ins(int k)
{
    if(k<mn)return;
    k-=tag;
    split(rt,k,x,y);
    rt=merge(merge(x,add(k)),y);
}
void del()
{
    split(rt,mn-tag-1,x,y);
    rt=y;
    ans+=t[x].siz;
}
int kth(int k)
{
    if(k<1||k>t[rt].siz)return -1;
    int now=rt;
    while(now)
    {
        int tmp=t[ls(now)].siz+1;
        if(tmp<k)k-=tmp,now=rs(now);
        else if(tmp==k)return t[now].val+tag;
        else now=ls(now);
    }
    return -1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    cin>>n>>mn;
    for(int i=1;i<=n;i++)
    {
        char c;int k;
        cin>>c>>k;
        if(c=='I')ins(k);
        if(c=='A')tag+=k;
        if(c=='S')tag-=k,del();
        if(c=='F')cout<<kth(t[rt].siz-k+1)<<endl;
    }
    cout<<ans<<endl;
    return 0;
}