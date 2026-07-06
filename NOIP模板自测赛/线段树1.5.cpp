#include<bits/stdc++.h>
#define int unsigned long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,num=0,root=0;
struct node
{
    int ls,rs,l,r,val,lazy;
}t[N*16];
void newnode(int &k,int l,int r)
{
    if(k)return;
    k=++num;
    t[k].l=l;
    t[k].r=r;
    // t[k].val=(l+r)*(r-l+1)/2;
}
void pushdown(int k)
{
    int l=t[k].l,r=t[k].r,mid=(l+r)>>1;
    newnode(t[k].ls,l,mid);
    newnode(t[k].rs,mid+1,r);
    t[t[k].ls].val+=t[k].lazy*(t[t[k].ls].r-t[t[k].ls].l+1);
    t[t[k].rs].val+=t[k].lazy*(t[t[k].rs].r-t[t[k].rs].l+1);
    t[t[k].ls].lazy+=t[k].lazy;
    t[t[k].rs].lazy+=t[k].lazy;
    t[k].lazy=0;
}
void pushup(int k)
{
    t[k].val=t[t[k].ls].val+t[t[k].rs].val;
}
void add(int &k,int l,int r,int L,int R,int d)
{
    newnode(k,l,r);
    if(l>R||r<L)return;
    if(L<=l&&r<=R)
    {
        t[k].val+=d*(r-l+1);
        t[k].lazy+=d;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(k);
    add(t[k].ls,l,mid,L,R,d);
    add(t[k].rs,mid+1,r,L,R,d);
    pushup(k);
}
int query(int &k,int l,int r,int L,int R)
{
    newnode(k,l,r);
    if(l>R||r<L)return 0;
    if(L<=l&&r<=R)return t[k].val;
    int mid=(l+r)>>1;
    pushdown(k);
    return query(t[k].ls,l,mid,L,R)+query(t[k].rs,mid+1,r,L,R);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y,z;
            cin>>x>>y>>z;
            add(root,1,n,x,y,z);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            cout<<query(root,1,n,x,y)+(x+y)*(y-x+1)/2<<endl;
        }
        // for(int i=1;i<=n;i++)
        //     cout<<query(root,1,n,i,i)<<" ";
        // cout<<endl;
    }
    return 0;
}
/*

5 5
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4


*/