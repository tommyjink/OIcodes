#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,c,a[N],b[N],tag[N];
struct node
{
    int l,r;
    mutable int col,val;
};
struct Node
{
    int l,r,val,maxval,minval;
}t[N*4];
bool operator < (node a,node b)
{
    return a.l<b.l;
}
set<node> s;
void pushup(int k)
{
    t[k].maxval=max(t[k*2].maxval,t[k*2+1].maxval);
    t[k].val=t[k*2].val+t[k*2+1].val;
    t[k].minval=min(t[k*2].minval,t[k*2+1].minval);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=t[k].maxval=a[l];
        t[k].minval=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid),build(k*2+1,mid+1,r);
    pushup(k);
}
void add(int k,int x,int d)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        t[k].val+=d;
        t[k].maxval+=d;
        return;
    }
    add(k*2,x,d),add(k*2+1,x,d);
    pushup(k);
}
int querymax(int k,int l,int r)
{ 
    if(t[k].l>r||t[k].r<l)return 0;
    if(t[k].l>=l&&t[k].r<=r)return t[k].maxval;
    return max(querymax(k*2,l,r),querymax(k*2+1,l,r));
}
int sum(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(t[k].l>=l&&t[k].r<=r)return t[k].val;
    return sum(k*2,l,r)+sum(k*2+1,l,r);
}
int querymin(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 1e15;
    if(t[k].l>=l&&t[k].r<=r)return t[k].minval;
    return min(querymin(k*2,l,r),querymin(k*2+1,l,r));
}
auto split(int x)
{
    auto it=s.lower_bound((node){x,0,0,0});
    if(it!=s.end()&&it->l==x)return it;
    it--;
    node tmp=*it;
    s.erase(it);
    s.insert((node){tmp.l,x-1,tmp.col,sum(1,tmp.l,x-1)});
    return s.insert((node){x,tmp.r,tmp.col,sum(1,x,tmp.r)}).first;
}
void change(int l,int r,int c)
{
    auto it2=split(r+1),it=split(l);
    // for(auto i=it;i!=it2;i++) 
    //     i->col=c;
    s.erase(it,it2);
    s.insert((node){l,r,c,sum(1,l,r)});
}
int query1(int l,int r)
{ 
    for(int i=1;i<=c;i++)
        tag[i]=0;
    auto it2=split(r+1),it=split(l);
    auto p=it;
    int cnt=0,res=1e15;
    if(next(it)==it2&&c==1)
        return querymin(1,l,r);
    for(auto i=it;i!=it2;i++)
    {
        tag[i->col]++;
        if(tag[i->col]==1)
            cnt++;
        while(p!=it2&&tag[p->col]>1)
            tag[p->col]--,p++;
        if(cnt==c)
            res=min(res,sum(1,p->r,i->l));
    }
    return res;
}
int query2(int l,int r)
{
    for(int i=1;i<=c;i++)
        tag[i]=0;
    auto it2=split(r+1),it=split(l); 
    int p=it->l;
    auto pp=it;
    int now=0,res=querymax(1,l,r);
    for(auto i=it;i!=it2;i++)
    {
        tag[i->col]++;
        while(pp!=i&&tag[i->col]>1)
        {
            tag[pp->col]--;
            now-=sum(1,p,pp->r);
            pp++;
            p=pp->l;
        }
        if(i->l!=i->r)
        {
            res=max(res,now+sum(1,i->l,i->l));
            now=sum(1,i->r,i->r);
            for(auto j=pp;j!=i;j++)
                tag[j->col]--;
            pp=i;
            p=i->r;
        }
        else now+=sum(1,i->l,i->l);
        res=max(res,now);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        s.insert((node){i,i,b[i],a[i]});
    }
    while(m--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op!=1&&x>y)swap(x,y);
        if(op==1)
            add(1,x,-sum(1,x,x)+y);
        else if(op==2)
        {
            int z;
            cin>>z;
            change(x,y,z);
        }
        else if(op==3)
        {
            int res=query1(x,y);
            cout<<(res==1e15?-1:res)<<endl;
        }
        else
        {
            cout<<query2(x,y)<<endl;
        }
    }
    return 0;
}