#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e15;
int n,m,a[N],b[N];
struct node
{
    int l,r,maxa,minb,maxab,maxba,maxaba;
}t[N*4];
struct Point
{
    int maxa,minb,maxab,maxba,maxaba;
};
void pushup(int k)
{
    t[k].maxa=max(t[k*2].maxa,t[k*2+1].maxa);
    t[k].minb=min(t[k*2].minb,t[k*2+1].minb);
    t[k].maxab=max({t[k*2].maxab,t[k*2+1].maxab,t[k*2].maxa-t[k*2+1].minb});
    t[k].maxba=max({t[k*2].maxba,t[k*2+1].maxba,t[k*2+1].maxa-t[k*2].minb});
    t[k].maxaba=max({t[k*2].maxaba,t[k*2+1].maxaba,t[k*2].maxab+t[k*2+1].maxa,t[k*2].maxa+t[k*2+1].maxba});
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    t[k].maxa=t[k].maxab=t[k].maxaba=t[k].maxba=-INF;
    t[k].minb=INF;
    if(l==r)
    {
        t[k].maxa=a[l];
        t[k].minb=b[l];
        t[k].maxab=t[k].maxba=t[k].maxaba=-INF;
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void updateA(int k,int x,int d)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        t[k].maxa=d;
        return;
    }
    updateA(k*2,x,d);
    updateA(k*2+1,x,d);
    pushup(k);
}
void updateB(int k,int x,int d)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        t[k].minb=d;
        return;
    }
    updateB(k*2,x,d);
    updateB(k*2+1,x,d);
    pushup(k);
}
Point query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return (Point){-INF,-INF,-INF,-INF,-INF};
    if(l<=t[k].l&&t[k].r<=r)return (Point){t[k].maxa,t[k].minb,t[k].maxab,t[k].maxba,t[k].maxaba};
    Point ll=query(k*2,l,r),rr=query(k*2+1,l,r);
    return (Point){
            max(ll.maxa,rr.maxa),
            max(ll.minb,rr.minb),
            max({ll.maxab,rr.maxab,ll.maxa-rr.minb}),
            max({ll.maxba,rr.maxba,rr.maxa-ll.minb}),
            max({ll.maxaba,rr.maxaba,ll.maxab+rr.maxa,ll.maxa+rr.maxba})};
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    build(1,1,n);
    while(m--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)updateA(1,x,y);
        if(op==2)updateB(1,x,y);
        if(op==3)cout<<query(1,x,y).maxaba<<endl;
    }
    return 0;
}
/*
6 6
1 4 2 3 5 6
5 3 4 1 6 7
3 2 5
3 1 6
1 2 3
3 1 6
2 6 1
3 1 6


8
9
8
8
*/