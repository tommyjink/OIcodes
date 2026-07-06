#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
struct node
{
    int val,mx,lazy;
    int pri,siz;
    node *l,*r;
    node(int x)
    {
        val=mx=x;
        lazy=0;
        pri=rand();
        siz=1;
        l=r=nullptr;
    }
};
int siz(node *x)
{
    return x?x->siz:0;
}
void addtag(node *x,int v)
{
    if(!x)return;
    x->val+=v;
    x->mx+=v;
    x->lazy+=v;
}
void push(node *x)
{
    if(!x||!x->lazy)return;
    addtag(x->l,x->lazy);
    addtag(x->r,x->lazy);
    x->lazy=0;
}
void pushup(node *x)
{
    if(!x)return;
    x->siz=siz(x->l)+siz(x->r)+1;
    x->mx=x->val;
    if(x->l)x->mx=max(x->mx,x->l->mx);
    if(x->r)x->mx=max(x->mx,x->r->mx);
}
node *merge(node *x,node *y)
{
    if(!x)return y;
    if(!y)return x;
    if(x->pri<y->pri)
    {
        push(x);
        x->r=merge(x->r,y);
        pushup(x);
        return x;
    }
    else
    {
        push(y);
        y->l=merge(x,y->l);
        pushup(y);
        return y;
    }
}
void split(node *rt,int v,node *&x,node *&y)
{
    if(!rt)
    {
        x=y=nullptr;
        return;
    }
    push(rt);
    if(rt->val<=v)
    {
        split(rt->r,v,rt->r,y);
        x=rt;
        pushup(x);
    }
    else
    {
        split(rt->l,v,x,rt->l);
        y=rt;
        pushup(y);
    }
}
void del(node *x)
{
    if(!x)return;
    del(x->l);
    del(x->r);
    delete x;
}
void solve()
{
    int n;
    cin>>n;
    node *rt=nullptr;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        node *l,*r;
        split(rt,x,l,r);
        addtag(r,x);
        node *cur=new node(x);
        rt=merge(merge(l,cur),r);
    }
    cout<<rt->mx<<endl;
    del(rt);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
