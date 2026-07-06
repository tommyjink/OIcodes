#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=2e6+10;
int n,m,a[N],t[N],ans[N];
struct node
{
    int x,op,id;
};
vector<node> q[N];
void add(int x,int d)
{
    for(int i=x;i<N;i+=lowbit(i))
        t[i]+=d;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        q[r].push_back({x,1,i});
        q[l-1].push_back({x,-1,i});
    }
    for(int i=1;i<=n;i++)
    {
        // cout<<a[i]<<"!"<<endl;
        add(a[i],1);
        for(auto j:q[i])
            ans[j.id]+=sum(j.x)*j.op;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}