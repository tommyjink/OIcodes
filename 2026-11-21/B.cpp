#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
const int N=5e5+10;
int n,q,h[N],lst[N],pre[N],fr[N],to[N];
map<int,int> mp;
struct node
{
    pii p;
    int fr,to;
}t[N*4];
pii merge(pii x,pii y)
{
    if(h[x.first]>h[y.first])return x;
    if(h[x.first]<h[y.first])return y;
    return {x.first,y.second};
}
void pushup(int k)
{
    t[k].p=merge(t[ls(k)].p,t[rs(k)].p);
    t[k].fr=max(t[ls(k)].fr,t[rs(k)].fr);
    t[k].to=max(t[ls(k)].to,t[rs(k)].to);
}
void build(int k,int L,int R)
{
    if(L==R){
        t[k]={{L,L},fr[L],to[L]};
        return;
    }
    int mid=(L+R)>>1;
    build(ls(k),L,mid);
    build(rs(k),mid+1,R);
    pushup(k);
}
pii get(int k,int L,int R,int l,int r)
{
    if(l<=L&&R<=r)return t[k].p;
    int mid=(L+R)>>1;
    if(r<=mid)return get(ls(k),L,mid,l,r);
    if(l>mid)return get(rs(k),mid+1,R,l,r);
    return merge(get(ls(k),L,mid,l,r),get(rs(k),mid+1,R,l,r));
}
int query(int k,int L,int R,int l,int r,bool dir)
{
    if(l>r)return 0;
    if(l<=L&&R<=r)return dir?t[k].to:t[k].fr;
    int mid=(L+R)>>1,res=0;
    if(mid>=l)res=max(res,query(ls(k),L,mid,l,r,dir));
    if(mid+1<=r)res=max(res,query(rs(k),mid+1,R,l,r,dir));
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    stack<int> s;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        while(!s.empty()&&h[s.top()]<=h[i])s.pop();
        if(!s.empty())lst[i]=s.top();
        pre[i]=mp[h[i]];
        s.push(i);
        mp[h[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(pre[i]<=lst[i])continue;
        fr[i]=fr[pre[i]]+(i-pre[i])*h[i];
    }
    for(int i=n;i>=1;i--){
        if(pre[i]<=lst[i])continue;
        to[pre[i]]=to[i]+(i-pre[i])*h[i];
    }
    build(1,1,n);
    int l=0,r=0,z=0,ans=0;
    for(int now=1;now<=q;now++){
        if(now==1)cin>>l>>r;
        else{
            int x=(l+37*z)%n+1;
            int y=(l+r+53*z)%n+1;
            l=min(x,y);
            r=max(x,y);
        }
        auto [a,b]=get(1,1,n,l,r);
        z=max({(b-a)*h[a],query(1,1,n,l,a-1,1),query(1,1,n,b+1,r,0)});
        ans^=z+now;
    }
    cout<<ans<<endl;
    return 0;
}
