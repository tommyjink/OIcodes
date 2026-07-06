#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5010;
int n,dep[N],fa[N],vis[N],tim;
vector<int> g[N];
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int ask1(int u,int v)
{
    cout<<"? 1 "<<u<<" "<<v<<endl;
    cout.flush();
    int x;cin>>x;
    return x;
}
vector<int> ask2(int u)
{
    cout<<"? 2 "<<u<<endl;
    cout.flush();
    int num;cin>>num;
    vector<int> res;
    res.reserve(num);
    for(int i=1;i<=num;i++)
    {
        int x;cin>>x;
        res.push_back(x);
    }
    return res;
}
void dfs(int x)
{
    vector<int> now;
    now.swap(g[x]);
    if(now.empty())return;
    vector<int> son;
    for(auto y:now)
        if(dep[y]==dep[x]+1)
            son.push_back(y),fa[y]=x;
    if(son.empty())return;
    if(son.size()==now.size())return;
    if(son.size()==1)
    {
        int y=son[0];
        g[y].clear();
        g[y].reserve(now.size()-1);
        for(auto z:now)
            if(z!=y)
                g[y].push_back(z);
        vector<int>().swap(now);
        dfs(y);
        return;
    }
    int rt=0,tmp=now[rnd()%now.size()];
    if(dep[tmp]==dep[x]+1)rt=tmp;
    else
    {
        shuffle(son.begin(),son.end(),rnd);
        for(auto y:son)
            if(ask1(y,tmp)==dep[tmp]-dep[y])
            {
                rt=y;
                break;
            }
    }
    ++tim;
    for(auto y:son)
    {
        if(y==rt)continue;
        auto res=ask2(y);
        g[y].clear();
        g[y].reserve(max(0ll,(int)res.size()-1));
        for(auto z:res)
        {
            vis[z]=tim;
            if(z!=y)g[y].push_back(z);
        }
    }
    g[rt].clear();
    g[rt].reserve(now.size());
    for(auto y:now)
        if(y!=rt&&vis[y]!=tim)
            g[rt].push_back(y);
    vector<int>().swap(now);
    for(auto y:son)
        dfs(y);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    dep[1]=0;
    for(int i=2;i<=n;i++)
        dep[i]=ask1(1,i),g[1].push_back(i);
    dfs(1);
    cout<<"!";
    for(int i=2;i<=n;i++)
        cout<<" "<<fa[i];
    cout<<endl;
    cout.flush();
    return 0;
}
