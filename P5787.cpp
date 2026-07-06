#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,K,fa[N],h[N],ans[N];
pii E[N];
struct Node
{
    int x,y,add;
};
stack<Node> s;
struct node
{
    int l,r;
    vector<int> v;
}t[N*4];
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)return;
    build(k*2,l,(l+r)/2);
    build(k*2+1,(l+r)/2+1,r);
}
void modify(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].v.push_back(d);
        return;
    }
    modify(k*2,l,r,d);
    modify(k*2+1,l,r,d);
}
int getfa(int x)
{
    return x==fa[x]?x:getfa(fa[x]);
}
void merge(int x,int y)
{
    int fx=getfa(x),fy=getfa(y);
    if(h[fx]>h[fy])swap(fx,fy);
    s.push((Node){fx,fy,h[fx]==h[fy]});
    fa[fx]=fy;
    if(h[fx]==h[fy])h[fy]++;
}
void rev(int siz)
{
    while(s.size()>siz)
    {
        h[fa[s.top().x]]-=s.top().add;
        fa[s.top().x]=s.top().x;
        s.pop();
    }
}
void solve(int k)
{
    // cout<<t[k].l<<","<<t[k].r<<endl;
    int siz=s.size();
    for(auto i:t[k].v)
    {
        int fx=getfa(E[i].first);
        int fy=getfa(E[i].second);
        if(fx==fy)
        {
            for(int j=t[k].l;j<=t[k].r;j++)
                cout<<"No"<<endl;
            rev(siz);
            return;
        }
        merge(E[i].first,E[i].second+n);
        merge(E[i].first+n,E[i].second);
    }
    if(t[k].l==t[k].r)cout<<"Yes"<<endl;
    else solve(k*2),solve(k*2+1);
    rev(siz);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>K;
    build(1,1,K);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>E[i].first>>E[i].second>>l>>r;
        modify(1,l+1,r,i);
    }
    for(int i=1;i<=2*n;i++)fa[i]=i,h[i]=1;
    solve(1);
    return 0;
}