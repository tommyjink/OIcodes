#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,lazy[N*8],p=1,ans=1e15;
vector<int> b;
struct node
{
    int l,r;
}a[N];
struct node1
{
    int k,l,r,val;
}t[N*8];
bool cmp(node x,node y)
{
    return x.r-x.l<y.r-y.l;
}
void pushup(int k)
{
    t[k].val=max(t[k*2].val,t[k*2+1].val);
}
void pushdown(int k)
{
    lazy[k*2]+=lazy[k];
    lazy[k*2+1]+=lazy[k];
    t[k*2].val+=lazy[k];
    t[k*2+1].val+=lazy[k];
    lazy[k]=0;
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)return;
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
int query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return -1e9;
    if(l<=t[k].l&&t[k].r<=r)return t[k].val;
    pushdown(k);
    return max(query(k*2,l,r),query(k*2+1,l,r));
}
signed main()
{
    // freopen("P1712_17.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r;
        b.push_back(a[i].l);
        b.push_back(a[i].r);
    }
    sort(a+1,a+1+n,cmp);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    // unique(b.begin(),b.end());
    build(1,1,2*n);
    for(int i=1;i<=n;i++)
    {
        a[i].l=lower_bound(b.begin(),b.end(),a[i].l)-b.begin()+1;
        a[i].r=lower_bound(b.begin(),b.end(),a[i].r)-b.begin()+1;
        add(1,a[i].l,a[i].r,1);
        while(query(1,1,2*n)>=m&&p<=i)
        {
            ans=min(ans,(b[a[i].r-1]-b[a[i].l-1]+1)-(b[a[p].r-1]-b[a[p].l-1]+1));
            add(1,a[p].l,a[p].r,-1);
            p++;
        }
    }
    cout<<(ans==1e15?-1:ans)<<endl;
    return 0;
}