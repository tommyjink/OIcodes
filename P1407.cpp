#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,m,tot,head[N],tt,dfn[N],low[N],now=0,col[N],c,in[N],cc[N];
map<string,int> mp;
string X[N],Y[N],Z[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
int num(string s)
{
    if(!mp.count(s))mp[s]=++tt;
    Z[tt]=s;
    return mp[s];
}
stack<int> st;
void tarjan(int x)
{
    dfn[x]=low[x]=++now;
    in[x]=true;
    st.push(x);
    // cout<<Z[x]<<endl;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
        else if(in[v])low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        c++;
        while(!st.empty())
        {
            int v=st.top();st.pop();
            col[v]=c,in[v]=false;
            cc[c]++;
            if(v==x)break;
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
        string x,y;
        cin>>x>>y;
        X[i]=x,Y[i]=y;
        add(num(x),num(y));
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        string x,y;
        cin>>x>>y;
        add(num(y),num(x));
    }
    for(int i=1;i<=tt;i++)
        if(!dfn[i])tarjan(i);
    for(int i=1;i<=n;i++)
    {
        if(col[num(X[i])]==col[num(Y[i])])
            cout<<"Unsafe"<<endl;
        else cout<<"Safe"<<endl;
    }
    return 0;
}