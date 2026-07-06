#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,q;
set<int> s;
struct node
{
    int l,r,val;
}t[N*4];
void pushup(int k)
{
    t[k].val=min(t[k*2].val,t[k*2+1].val);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=n+2;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int x,int d)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        t[k].val=min(t[k].val,d);
        return;
    }
    modify(k*2,x,d);
    modify(k*2+1,x,d);
    pushup(k);
}
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return 1e9;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    return min(query(k*2,l,r),query(k*2+1,l,r));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=0;i<=n+1;i++)
        s.insert(i);
    build(1,1,n);
    while(q--)
    {
        int op;
        cin>>op;
        if(op==0)
        {
            int l,r,x;
            cin>>l>>r>>x;
            if(x==0)
            {
                while(!s.empty())
                {
                    auto xx=s.lower_bound(l);
                    if(xx!=s.end()&&*xx<=r)
                        s.erase(xx);
                    else break;
                }
            }
            else
                modify(1,l,r);
        }
        else
        {
            int x;
            cin>>x;
            if(s.find(x)==s.end())
                cout<<"NO"<<endl;
            else
            {
                auto xx=s.find(x);
                int l=*prev(xx)+1,r=*next(xx)-1;
                if(query(1,l,x)<=r)cout<<"YES"<<endl;
                else cout<<"N/A"<<endl;
            }
        }
    }
    return 0;
}