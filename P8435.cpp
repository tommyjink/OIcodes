#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,tot,head[N];
int low[N],dfn[N],s[N],top=0,num=0,ans=0;
vector<int> V[N];
struct node
{
    int to,next;
}e[N*4];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void tarjan(int x,int rt)
{
    int siz=0;
    low[x]=dfn[x]=++num;
    s[top++]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            tarjan(v,rt),low[x]=min(low[x],low[v]),siz++;
            if(low[v]>=dfn[x])
            {
                ans++;
                while(1)
                {
                    int t=s[--top];
                    V[ans].push_back(t);
                    if(t==v)break;
                }
                V[ans].push_back(x);
            }
        }
        else low[x]=min(low[x],dfn[v]);
    }
    if(siz==0&&x==rt)
        V[++ans].push_back(x);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])tarjan(i,i);
    }
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++)
    {
        cout<<V[i].size()<<" ";
        for(auto j:V[i])cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}