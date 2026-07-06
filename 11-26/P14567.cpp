#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,c[N],v[N],f[N],lst[N],cnt[N];
int st[N],ed[N],front[N],back[N];
vector<pii> a,b;
struct node
{
    int l,r,front,back;
}t[N*4];
void pushup(int k)
{
    t[k].front=min(t[k*2].front,t[k*2+1].front);
    t[k].back=max(t[k*2].back,t[k*2+1].back);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        t[k].back=back[l];
        t[k].front=front[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int x,int d,int mode)
{
    if(t[k].l>x||t[k].r<x)return;
    if(t[k].l==t[k].r)
    {
        if(mode)t[k].back=d;
        else t[k].front=d;
        return;
    }
    modify(k*2,x,d,mode);
    modify(k*2+1,x,d,mode);
    pushup(k);
}
int query(int k,int l,int r,int mode)
{
    if(t[k].l>r||t[k].r<l)return mode?-1:1e10;
    if(l<=t[k].l&&t[k].r<=r)return mode?t[k].back:t[k].front;
    return mode?max(query(k*2,l,r,mode),query(k*2+1,l,r,mode)):
                min(query(k*2,l,r,mode),query(k*2+1,l,r,mode));
}
signed main()
{
    // freopen("./interval/interval8.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>f[i];
    for(int i=1;i<=n;i++)
    {
        if(!st[c[i]])st[c[i]]=i;
        ed[c[i]]=i;
        // if(c[i]==184)cout<<i<<"!"<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        back[i]=ed[c[i]];
        front[i]=st[c[i]];
    }
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        if(front[i]!=1e10)
        {
            // cout<<front[i]<<"__"<<i<<endl;
            front[i]=query(1,front[i],i,0);
            modify(1,i,front[i],0);
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(back[i]!=-1)
        {
            back[i]=query(1,i,back[i],1);
            modify(1,i,back[i],1);
        }
    }
    // for(int i=1;i<=n;i++)
    //     cout<<front[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<back[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        int x=front[ed[i]],y=back[st[i]];
        if(x&&y)a.emplace_back(pii(x,y));
        st[i]=x;
        ed[i]=y;
    }
    // for(int i=1;i<=n;i++)
    //     cout<<st[i]<<","<<ed[i]<<endl;
    int l=1,r=n;
    sort(a.begin(),a.end());
    for(auto i:a)
    {
        if(l<=i.first&&i.second<=r)
            l=i.first,r=i.second;
        else if(r<i.first)
            b.emplace_back(pii(l,r)),
            l=i.first,r=i.second;
        else r=max(r,i.second);
    }
    b.emplace_back(pii(l,r));
    // for(auto i:b)cout<<i.first<<","<<i.second<<endl;
    int ans=1e18;
    for(auto now:b)
    {
        int l=now.first,r=now.second;
        int res=0;
        for(int i=l;i<=r;i++)
        {
            res+=v[i]*f[i-l+1];
        }
        ans=min(ans,res);
        // if(res==5)for(int j=l;j<=r;j++)
        //     cout<<j<<":"<<c[j]<<endl;
    }  
    cout<<ans<<endl; 
    return 0;
}
/*

6
1 1 2 1 2 1
1 1 1 1 3 3
1 1 2 3 3 3

*/