#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e15;
struct node
{
    int l,r,val1,val2,val3,val4;
}t[N*4];
const node IINF=(node){0,0,-INF,-INF,-INF,-INF};
int n,q,X[N],Y[N];
void pushup(int k)
{
    t[k].val1=max(t[k*2].val1,t[k*2+1].val1);
    t[k].val2=max(t[k*2].val2,t[k*2+1].val2);
    t[k].val3=max(t[k*2].val3,t[k*2+1].val3);
    t[k].val4=max(t[k*2].val4,t[k*2+1].val4);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        int x=X[l],y=Y[l];
        t[k].val1=x+y;
        t[k].val2=x-y;
        t[k].val3=-x+y;
        t[k].val4=-x-y;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int pos,int x,int y)
{
    if(t[k].l>pos||t[k].r<pos)return;
    if(t[k].l==t[k].r)
    {
        t[k].val1=x+y;
        t[k].val2=x-y;
        t[k].val3=-x+y;
        t[k].val4=-x-y;
        return;
    }
    modify(k*2,pos,x,y);
    modify(k*2+1,pos,x,y);
    pushup(k);
}
node query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return IINF;
    if(l<=t[k].l&&t[k].r<=r)return t[k];
    node res1=query(k*2,l,r);
    node res2=query(k*2+1,l,r);
    res1.val1=max(res1.val1,res2.val1);
    res1.val2=max(res1.val2,res2.val2);
    res1.val3=max(res1.val3,res2.val3);
    res1.val4=max(res1.val4,res2.val4);
    return res1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>X[i]>>Y[i];
    build(1,1,n);
    while(q--)
    {
        int op;cin>>op;
        if(op==1)
        {
            int i,x,y;
            cin>>i>>x>>y;
            modify(1,i,x,y);
        }
        else
        {
            int l,r,x,y;
            cin>>l>>r>>x>>y;
            node res=query(1,l,r);
            int ans=max(
                {
                    -x-y+res.val1,
                    -x+y+res.val2,
                    +x-y+res.val3,
                    +x+y+res.val4
                }
            );
            cout<<ans<<endl;
        }
    }
    return 0;
}