#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m,typ[N],res[N],tot,head[N];
int in[N],cnt=0;
vector<int> ans;
queue<int> q[5];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
bool del(int num)
{
    if(q[num].empty())return false;
    int t=q[num].front();q[num].pop();
    ans.push_back(t);cnt++;
    for(int i=head[t];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!--in[v])q[typ[v]].push(v);
    }
    return true;
}
bool work()
{
    for(int i=1;i<=n;i++)
        if(!in[i])q[typ[i]].push(i);
    while(del(4));
    if(cnt==n)return true;
    if(!del(1))return false;
    while(del(2));
    if(cnt==n)return true;
    if(!del(3))return false;
    while(del(4));
    return cnt==n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s,t;
        cin>>s>>t;
        s+=t;
        if(s=="settrue")typ[i]=1;
        else if(s=="setfalse")typ[i]=2;
        else if(s=="unsettrue")typ[i]=3;
        else typ[i]=4;
        // cout<<typ[i]<<" "; 
    }
    // cout<<endl;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        in[y]++;
    }
    if(work())
        for(int i:ans)cout<<i<<" ";
    else cout<<"-1"<<endl;
    return 0;
}
/*
set true 1
set false 2
unset true 3
unset false 4
*/