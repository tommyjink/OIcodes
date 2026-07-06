//zhengzhou 2025
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+5;
int n,m,a[N],lazy[N*4];
struct node
{
    int l,r,val,num;
}t[N*4];
struct Point
{
    int l,r,d,num;
};
bool operator<(Point a,Point b)
{
    return a.l<b.l;
}
set<Point> s;
void pushdown(int k)
{
    if(lazy[k])
    {
        lazy[k*2]+=lazy[k];
        lazy[k*2+1]+=lazy[k];
        t[k*2].val+=lazy[k];
        t[k*2+1].val+=lazy[k];
        lazy[k]=0;
    }
}
void pushup(int k)
{
    t[k].val=max(t[k*2].val,t[k*2+1].val);
    if(t[k*2].val>t[k*2+1].val)
        t[k].num=t[k*2].num;
    else t[k].num=t[k*2+1].num;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].val=a[l];
        t[k].num=l;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void add(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].val+=d;
        lazy[k]+=d;
        return;
    }
    pushdown(k);
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}
void solve()
{
    s.clear();
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s.insert((Point){i,i,a[i]});
    }
    build(1,1,n);
    while(m--)
    {
        int l,r,d;
        cin>>l>>r>>d;
        auto it1=--s.upper_bound((Point){l,0,0});
        int l1=it1->l,r1=it1->r,d1=it1->d;
        auto it2=--s.upper_bound((Point){r,0,0});
        int l2=it2->l,r2=it2->r,d2=it2->d;
        for(auto it=it1;it!=it2;)
        {
            add(1,it->d,it->d+(r-l),-1);
            auto next_it = it; 
            ++next_it;    
            s.erase(it);      
            it = next_it;
        }
        s.insert((Point){l,r,d});
        s.insert((Point){l1,l,d1});
        s.insert((Point){r,r2,d2+r-l2});
        add(1,d,d+(r-l),1);
        add(1,d1,d1+(l-l1),1);
        add(1,d2+r-l2,d2+r-l2+(r2-r),1);
        cout<<t[1].num<<" "<<t[1].val<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}