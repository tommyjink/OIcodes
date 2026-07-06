#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,M='z'-'a';
int n,q;
string s;
struct node
{
    int l,r,val,lazy;
}t[M+1][N*4];
void pushup(node *t,int k)
{
    t[k].val=t[k*2].val+t[k*2+1].val;
}
void pushdown(node *t,int k)
{
    if(t[k].lazy==-1)return;
    t[k*2].lazy=t[k*2+1].lazy=t[k].lazy;
    t[k*2].val=t[k].lazy*(t[k*2].r-t[k*2].l+1);
    t[k*2+1].val=t[k].lazy*(t[k*2+1].r-t[k*2+1].l+1);
    t[k].lazy=-1;
}
void build(node *t,int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    t[k].lazy=-1;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(t,k*2,l,mid);
    build(t,k*2+1,mid+1,r);
    pushup(t,k);
}
void modify(node *t,int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].lazy=d;
        t[k].val=d*(t[k].r-t[k].l+1);
        return;
    }
    pushdown(t,k);
    modify(t,k*2,l,r,d);
    modify(t,k*2+1,l,r,d);
    pushup(t,k);
}
int query(node *t,int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 0;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(t,k);
    return query(t,k*2,l,r)+query(t,k*2+1,l,r);
}
void test()
{
    int n=10;
    build(t[0],1,1,n);
    while(1)
    {
        int op;
        cin>>op;
        if(op==1)
        {   
            int x,y,z;
            cin>>x>>y>>z;
            modify(t[0],1,x,y,z);
        }
        else if(op==2)
        {
            int x,y;
            cin>>x>>y;
            cout<<query(t[0],1,x,y)<<endl;
        }
        else
        {
            for(int i=1;i<=n;i++)
                cout<<query(t[0],1,i,i)<<" ";
            cout<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // test();
    cin>>n>>q;
    for(int i=0;i<=M;i++)
        build(t[i],1,1,n);
    cin>>s;s=" "+s;
    for(int i=1;i<=n;i++)
        modify(t[s[i]-'a'],1,i,i,1);
    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(z)
        {
            int now=x;
            for(int i=0;i<=M;i++)
            {
                int res=query(t[i],1,x,y);
                modify(t[i],1,x,y,0);
                modify(t[i],1,now,now+res-1,1);
                now+=res;
            }
        }
        else
        {
            int now=x;
            for(int i=M;i>=0;i--)
            {
                int res=query(t[i],1,x,y);
                modify(t[i],1,x,y,0);
                modify(t[i],1,now,now+res-1,1);
                now+=res;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int j=0;
        while(j<=M&&!query(t[j],1,i,i))j++;
        cout<<(char)(j+'a');
    }
    return 0;
}