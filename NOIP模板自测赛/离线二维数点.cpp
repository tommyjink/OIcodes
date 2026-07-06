#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) ((x)&(-x))
#define pii pair<int,int>
using namespace std;
const int N=2e6+10;
int n,m,a[N],t[N],ans[N];
struct node
{
    int id,y1,y2,d;
};
vector<node> q[N];
void add(int x,int d)
{
    if(!x)return;
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
        int x,y,z;
        cin>>x>>y>>z;
        q[x-1].emplace_back((node){i,1,z,-1});
        q[y].emplace_back((node){i,1,z,1});
    }
    for(int i=1;i<N;i++)
    {
        add(a[i],1);
        for(auto j:q[i])
            ans[j.id]+=j.d*(sum(j.y2)-sum(j.y1-1));
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
    return 0;
}