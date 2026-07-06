#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+10;
int n,a[N],m,lst[N],ans[N];
vector<pii> q[N];
struct Tree
{
    int t[N];
    void init()
    {
        for(int i=0;i<N;i++)
            t[i]=0;
    }
    void add(int x,int y)
    {
        // cout<<"add:"<<x<<","<<y<<endl;
        for(int i=x;i<N;i+=lowbit(i))
            t[i]+=y;
    }
    int sum(int x)
    {
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=t[i];
        return res;
    }
}t;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        q[y].emplace_back(pii(x,i));
    }
    t.init();
    for(int i=1;i<N;i++)
    {
        t.add(i,1);
        if(lst[a[i]])
            t.add(lst[a[i]],-1);
        lst[a[i]]=i;
        for(auto [x,id]:q[i])
        {
            // cout<<x<<","<<id<<":";
            // for(int j=1;j<=n;j++)
            //     cout<<t.sum(j)-t.sum(j-1)<<" ";
            // cout<<endl;
            ans[id]=t.sum(i)-t.sum(x-1);
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
    return 0;
}