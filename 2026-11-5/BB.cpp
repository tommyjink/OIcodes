#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,h[N],l[N],r[N],id[N],H=0;
int lst[N],nxt[N],ans[N],tag[N];
vector<int> s[N];
bool cmp(int x,int y)
{
    return h[x]<h[y];
}
struct info{int mn,from;};
struct node
{
    int l,r;
    info c;
}t[N*4];
info merge(info x,info y)
{
    return {min(x.mn,y.mn),x.mn<y.mn?x.from:y.from};
}
void pushup(int k)
{
    t[k].c=merge(t[k*2].c,t[k*2+1].c);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        if(s[l].empty())t[k].c={N,l};
        else t[k].c={s[l].back(),l},s[l].pop_back();
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
info query(int k,int l,int r)
{
    if(t[k].l>r||t[k].r<l)return {N,0};
    if(l<=t[k].l&&t[k].r<=r)return t[k].c;
    return merge(query(k*2,l,r),query(k*2+1,l,r));   
}
void upd(int k,int x)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        if(s[t[k].l].empty())t[k].c={N,t[k].l};
        else t[k].c={s[t[k].l].back(),t[k].l},s[t[k].l].pop_back();
        return;
    }
    upd(k*2,x);
    upd(k*2+1,x);
    pushup(k);
}
void check(int x);
void del(int i)
{
    if(tag[i])return;
    tag[i]=true;
    int x=lst[i],y=nxt[i];
    if(x)nxt[x]=y;
    if(y)lst[y]=x;
    if(x)check(x);
    if(y)check(y);
}
void check(int x)
{
    if(tag[x]||!x||x>n)return;
    // cout<<"check:"<<x<<endl;
    int L=lst[x],R=nxt[x]?nxt[x]:n+1;
    if(L+1>R-1)return;
    while(1)
    {
        info res=query(1,L+1,x);
        if(res.mn>=R)break;
        upd(1,res.from);
        if(res.mn<x)continue;
        // cout<<x<<"!"<<endl;
        ans[x]=H;
        del(x);
        break;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>h[i],id[i]=i,lst[i]=i-1,nxt[i]=i+1;
    nxt[n]=0;
    sort(id+1,id+1+n,cmp);
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i];
        s[l[i]].push_back(r[i]);
    }
    for(int i=1;i<=n;i++)
        sort(s[i].begin(),s[i].end(),greater<int>());
    build(1,1,n);
    for(int ii=1;ii<=n;ii++)
    {
        int i=id[ii];
        if(tag[i])continue;
        H=h[i];
        ans[i]=H;
        del(i);
    }   
    int sum=0;
    // for(int i=1;i<=n;i++)
    //     cout<<ans[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
        sum+=ans[i];
    cout<<sum<<endl;
    return 0;
}