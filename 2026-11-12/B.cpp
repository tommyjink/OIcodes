#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],pos[N];
int tot,head[N],in[N];
vector<int> ans;
stack<int> s;
struct node
{
    int l,r;
}t[N];
struct node1
{
    int to,next;
}e[N*8];
void add(int x,int y)
{
    e[++tot]={y,head[x]};
    head[x]=tot;
    in[y]++;
}
void topo()
{
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=n;i++)
        if(in[i]==0)q.push({i});
    while(!q.empty())
    {
        int t=q.top();q.pop();
        ans.push_back(t);
        for(int i=head[t];i;i=e[i].next)
        {
            int v=e[i].to;
            if(!--in[v])q.push(v);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i],pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int now=0,x=pos[i];
        while(!s.empty()&&pos[s.top()]>x)now=s.top(),s.pop();
        if(!s.empty())t[s.top()].r=i;
        if(now)t[i].l=now;
        s.push(i);
    }
    while(!s.empty())s.pop();
    for(int i=1;i<=n;i++)
    {
        if(t[i].l)add(i,t[i].l);
        if(t[i].r)add(i,t[i].r);
        t[i]={0,0};
    }
    for(int i=1;i<=n;i++)
    {
        int now=0,x=pos[i];
        while(!s.empty()&&pos[s.top()]<x)now=s.top(),s.pop();
        if(!s.empty())t[s.top()].r=i;
        if(now)t[i].l=now;
        s.push(i);
    }   
    for(int i=1;i<=n;i++)
    {
        if(t[i].l)add(t[i].l,i);
        if(t[i].r)add(t[i].r,i);
    }
    topo();
    // cout<<"??"<<endl;
    for(int i:ans)cout<<i<<" ";
    return 0;
}