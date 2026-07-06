#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+10;
int n,nxt[N][30],tot=0,tag[N],tt=0,head[N],in[30];
string w[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    // cout<<char('a'+x-1)<<"!"<<char('a'+y-1)<<endl;
    e[++tt]=(node){y,head[x]};
    head[x]=tt;
    in[y]++;
}
void init()
{
    tt=0;
    for(int i=0;i<='z'-'a';i++)
        head[i+1]=in[i+1]=0;
}
void insert(string s)
{
    int len=s.length(),p=0;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!nxt[p][c])
            nxt[p][c]=++tot;
        p=nxt[p][c];
    }
    tag[p]=true;
}
int topo()
{
    queue<int> q;
    for(int i=0;i<='z'-'a';i++)
        if(in[i+1]==0)q.push(i+1);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        for(int i=head[t];i;i=e[i].next)
        {
            int v=e[i].to;
            if(--in[v]==0)
                q.push(v);
        }
    }
    for(int i=0;i<='z'-'a';i++)
        if(in[i+1])return true;
    return false;
}
int query(string s)
{
    init();
    int len=s.length(),p=0;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        for(int j=0;j<='z'-'a';j++)
            if(nxt[p][j]&&j!=c)
                add(c+1,j+1);
        if(tag[p])return true;
        p=nxt[p][c];
    }
    if(topo())return true;
    return false;
}
vector<string> ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>w[i],insert(w[i]);
    for(int i=1;i<=n;i++)
    {
        if(!query(w[i]))ans.push_back(w[i]);
        // cout<<"__";
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)
        cout<<x<<endl;
    return 0;
}