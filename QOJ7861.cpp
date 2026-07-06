#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],vis[N],ans=1,in[N];
vector<int> g[N];
vector<int> topo1()
{
    priority_queue<int> q;
    for(int i=1;i<=n;i++)in[i]=0;
    for(int i=1;i<=n;i++)
        for(auto v:g[i])in[v]++;
    for(int i=1;i<=n;i++)
        if(!in[i])q.push(i);
    vector<int> v;
    while(!q.empty())
    {
        int t=q.top();q.pop();
        v.push_back(t);
        for(auto v:g[t])
            if(!--in[v])q.push(v);
    }
    return v;
}   
vector<int> topo2()
{
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=n;i++)in[i]=0;
    for(int i=1;i<=n;i++)
        for(auto v:g[i])in[v]++;
    for(int i=1;i<=n;i++)
        if(!in[i])q.push(i);
    vector<int> v;
    while(!q.empty())
    {
        int t=q.top();q.pop();
        v.push_back(t);
        for(auto v:g[t])
            if(!--in[v])q.push(v);
    }
    return v;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    stack<int> s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&a[i]>=a[s.top()])s.pop();
        if(!s.empty())g[a[s.top()]].push_back(a[i]);
        s.push(i);
    }
    while(!s.empty())s.pop();
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&b[i]<=b[s.top()])s.pop();
        if(!s.empty())g[b[s.top()]].push_back(b[i]);
        s.push(i);
    }
    vector<pii> v;
    for(int i=1;i<=n;i++)
    {
        sort(g[i].begin(),g[i].end());
        g[i].erase(unique(g[i].begin(),g[i].end()),g[i].end());
        for(auto j:g[i])v.push_back(pii(i,j));
    }
    for(int i=1;i<=n;i++)g[i].clear();
    for(auto i:v)g[i.first].push_back(i.second);
    vector<int> A,B;
    for(int i=1;i<=n;i++)A.push_back(a[i]);
    for(int i=1;i<=n;i++)B.push_back(b[i]);
    if(topo2()!=A||topo1()!=B)cout<<"No"<<endl,exit(0);
    cout<<"Yes"<<endl;
    cout<<(int)v.size()<<endl;
    for(auto i:v)cout<<i.first<<" "<<i.second<<endl;
    return 0;
}