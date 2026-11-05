#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,h[N],l[N],r[N];
vector<int> s[N];
struct node
{
    int l,r,mn;
}t[N*4];
void pushup(int k)
{
    t[k].mn=min(t[k*2].mn,t[k*2+1].mn);
}
void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r;
    if(l==r)
    {
        if(s[l].empty())t[k].mn=N;
        else t[k].mn=s[l].back(),s[l].pop_back();
        return;
    }
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    pushup(k);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i];
        s[l[i]].push_back(r[i]);
    }
    for(int i=1;i<=n;i++)
        sort(s[i].begin(),s[i].end(),greater<int>());
    
    return 0;
}