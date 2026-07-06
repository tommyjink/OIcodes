#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5;
int n,typ[N],val[N];
int head[N],tot=0,ans[N];
struct node
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){x,y,head[x]};
    head[x]=tot;
}
stack<int> q;
void dfs(int x,int fa)
{
    int t=0;
    if(typ[x]==1)
        q.push(val[x]);
    if(typ[x]==2)
        t=q.top(),q.pop();
    if(!q.empty())
        ans[x]=q.top();
    else ans[x]=-1;
    // stack<int> st;
    // printf("x=%lld:\n",x);
    // while(!q.empty())
    // {
    //     cout<<q.top()<<" ";
    //     st.push(q.top());
    //     q.pop();
    // }
    // cout<<endl;
    // while(!st.empty())
    //     q.push(st.top()),st.pop();
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
    }
    if(typ[x]==1)
        q.pop();
    if(typ[x]==2)
        q.push(t);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if(c=='a')
        {
            typ[i]=1;
            cin>>val[i];
            add(i-1,i);
            add(i,i-1);
        }
        if(c=='s')
        {
            typ[i]=2;
            add(i,i-1);
            add(i-1,i);
        }
        if(c=='t')
        {
            typ[i]=3;
            cin>>val[i];
            add(i,val[i]-1);
            add(val[i]-1,i);
        }
    }
    dfs(0,-1);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
    return 0;
}
/*
12
a 5
a 3
a 7
s
t 2
a 2
t 4
a 4
s
t 7
s
s

*/