#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
struct node
{
    int l,r;
}a[N];
bool cmp(node x,node y)
{
    return x.l<y.l;
}
priority_queue<int,vector<int>,greater<int>> q;
void solve()
{
    while(!q.empty())q.pop();
    int n,k,ans=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        while((!q.empty())&&q.top()<a[i].l)
            q.pop();
        ans=ans*max((k-(int)q.size()),0ll)%P;
        q.push(a[i].r);
    }    
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}