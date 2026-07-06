#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,q,lazy[N*4],d[N],cnt[N],tot=0;
vector<pii> v;
struct node
{
    int l,r;
}t[N*4];
void pushup(int k)
{
    if(~lazy[k*2]&&~lazy[k*2+1])
        if(lazy[k*2+1]==lazy[k*2]+t[k*2].r-t[k*2].l+1)
            lazy[k]=lazy[k*2];
}
void pushdown(int k)
{
    if(~lazy[k])
    {
        lazy[k*2]=lazy[k];
        lazy[k*2+1]=lazy[k]+t[k*2].r-t[k*2].l+1;
        lazy[k]=-1;
    }
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    lazy[k]=-1;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}
void modify(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        lazy[k]=d+(t[k].l-l);
        return;
    }
    pushdown(k);
    modify(k*2,l,r,d);
    modify(k*2+1,l,r,d);
    pushup(k);
}
void query(int k,int l,int r,int d)
{
    if(lazy[k]==-1&&t[k].l==t[k].r)return;
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r&&~lazy[k])
    {
        v.push_back(pii(d+t[k].l-l-lazy[k]-1,t[k].r-t[k].l+1));
        return;
    }
    pushdown(k);
    query(k*2,l,r,d);
    query(k*2+1,l,r,d);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    int now=1;
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        query(1,l,r,now);
        modify(1,l,r,now);
        now+=r-l+1;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        int j=i,now=0;
        while(j<v.size()&&v[j].first==v[i].first)j++;
        j--;
        for(int k=i;k<=j;k++)now+=v[k].second;
        // cout<<i<<","<<j<<"!!!"<<now<<endl;
        d[++tot]=v[i].first;
        cnt[tot]=now+cnt[tot-1];
        i=j;
    }
    // for(int i=1;i<=tot;i++)
    //     cout<<d[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=tot;i++)
    //     cout<<cnt[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=q;i++)
    {
        int x;
        cin>>x;
        int p=lower_bound(d+1,d+1+tot,x)-d;
        cout<<cnt[tot]-cnt[p-1]<<" ";
    }
    // cout<<endl;
    // for(pii i:v)cout<<i.first<<","<<i.second<<endl;
    return 0;
}
/*
5 3 7
1 3
3 5
2 3
0 1 2 3 4 5 6



6 6 7
1 6
1 5
1 4
1 3
1 2
1 1
1 2 3 4 5 6 7
*/