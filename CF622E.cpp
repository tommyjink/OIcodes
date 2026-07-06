#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,head[N],tot=0,dep[N];
vector<int> d;
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    int tag=0;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa)dfs(e[i].to,x),tag=true;
    if(!tag)d.emplace_back(dep[x]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    int ans=0;
    for(int i=head[1];i;i=e[i].next)
    {
        int v=e[i].to;
        d.clear();
        dfs(v,1);
        sort(d.begin(),d.end());
        for(int i=1;i<d.size();i++)
            d[i]=max(d[i],d[i-1]+1);
        if(d.size())ans=max(ans,d[d.size()-1]);
    }
    cout<<ans<<endl;
    return 0;
}