#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=1e15;
int n,m,head[N],tot=0,x[N],y[N],ss[N];
int p[N],num[N],in[N],col[N],now=0;
vector<int> e[N],v[N];
bool cmp(int x,int y)
{
    return v[x][0]<v[y][0];
}
inline void add(int x,int y)
{
    e[x].emplace_back(y);
}
void dfs(int x,int fa)
{
    col[x]=now;
    v[now].emplace_back(x);
    for(auto v:e[x])
    {
        if(v==fa||col[v])continue;
        dfs(v,x);
    }
}
void dfs1(int x,int fa,vector<int> &V)
{
    V.emplace_back(x);
    for(auto v:e[x])
    {
        if(v==fa)continue;
        dfs1(v,x,V);
    }
}
bool check(int now)
{
    if(v[now].size()==1)return true;
    int cnt1=0,cnt2=0,mn=INF;
    vector<int> tmp;
    for(auto x:v[now])
    {
        if(e[x].size()==1)cnt1++,mn=min(mn,num[x]);
        if(e[x].size()==2)cnt2++;
    }
    if(cnt1+cnt2!=v[now].size())return false;
    if(cnt1!=2)return false;
    v[now].clear();
    dfs1(p[mn],0,v[now]);
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=m;i++)
    {
        int xx=p[x[i]],yy=p[y[i]];
        add(xx,yy),add(yy,xx);
        swap(p[x[i]],p[y[i]]);
    }
    for(int i=1;i<=n;i++)
    {
        sort(e[i].begin(),e[i].end());
        e[i].erase(unique(e[i].begin(),e[i].end()),e[i].end());
    }
    for(int i=1;i<=n;i++)
        num[p[i]]=i;
    for(int i=1;i<=n;i++)
        if(!col[i])++now,dfs(i,i);
    for(int i=1;i<=now;i++)
    {
        if(!check(i))
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(int i=1;i<=now;i++)ss[i]=i;
    sort(ss+1,ss+1+now,cmp);

    cout<<"Yes"<<endl;
    for(int i=1;i<=now;i++)
        for(auto j:v[ss[i]])cout<<num[j]<<endl;
    return 0;
}