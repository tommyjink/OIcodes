#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2005;
int n,dfn[N],low[N],in[N],rk[N];
int f[N][N],col[N],ff[N][N],vis[N];
int tot=0,num=0;
vector<int> g[N],e[N];
vector<int> V[N];
stack<int> s;
void tarjan(int x)
{
    dfn[x]=low[x]=++tot;
    in[x]=true;
    s.push(x);
    for(int v:g[x])
    {
        if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
        else if(!col[v])low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x])
    {
        num++;
        while(1)
        {
            int t=s.top();s.pop();
            in[t]=false;
            col[t]=num;
            V[num].push_back(t);
            if(t==x)break;
        }
    }
}
vector<int> topo(int n,vector<int> *g,int *in)
{
    queue<int> q;
    vector<int> res;
    for(int i=1;i<=n;i++)
        if(!in[i])q.push(i);
    while(!q.empty())
    {
        int t=q.front();q.pop();
        res.push_back(t);
        for(int v:g[t])
            if(!--in[v])q.push(v);
    }
    return res;
}
void cal(vector<int> &a)
{
    vector<int> res,tmp;
    for(int x:a)
    {
        tmp.clear();
        if(res.size()==0){res.push_back(x);continue;}
        if(f[x][res[0]])
        {
            tmp.push_back(x);
            for(int i:res)tmp.push_back(i);
            res=tmp;
            continue;
        }
        if(f[res.back()][x])
        {
            res.push_back(x);
            continue;
        }
        for(int i=0;i<res.size()-1;i++)
        {
            int l=res[i],r=res[i+1];
            if(f[l][x]&&f[x][r])
            {
                for(int j=0;j<=i;j++)
                    tmp.push_back(res[j]);
                tmp.push_back(x);
                for(int j=i+1;j<res.size();j++)
                    tmp.push_back(res[j]);
                res=tmp;
                break;
            }
        }
    }
    a=res;
}
void cal1(vector<int> &a)
{
    int m=a.size();
    if(m==1)return;
    int k=0;
    for(int i=1;i<m;i++)
        if(f[a[i]][a[0]])k=i;
    vector<int> res,tmp;
    for(int i=0;i<=k;i++)
        res.push_back(a[i]);
    int l=k+1;
    for(int r=l;r<m;r++)
    {
        int p=-1,len=res.size();
        for(int j=0;j<len;j++)
        {
            int x=res[j],y=res[(j+1)%len];
            if(f[x][a[l]]&&f[a[r]][y])
            {
                p=j;
                break;
            }
        }
        if(p==-1)continue;
        tmp.clear();
        for(int j=0;j<=p;j++)
            tmp.push_back(res[j]);
        for(int j=l;j<=r;j++)
            tmp.push_back(a[j]);
        for(int j=p+1;j<len;j++)
            tmp.push_back(res[j]);
        res.swap(tmp);
        l=r+1;
    }
    a=res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            int x;cin>>x;
            if(x)f[j][i]=1;
            else f[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j])g[i].push_back(j);
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
    // for(int i=1;i<=n;i++)
    //     cout<<col[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         cout<<
    for(int i=1;i<=n;i++)
        in[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(f[i][j]&&col[i]!=col[j])
                ff[col[i]][col[j]]=1;
    for(int i=1;i<=num;i++)
        for(int j=1;j<=num;j++)
            if(ff[i][j])e[i].push_back(j),in[j]++;
    vector<int> A=topo(num,e,in);
    // for(int i:A)cout<<i<<endl;
    for(int i=0;i<A.size();i++)
        rk[A[i]]=i;
    for(int i=1;i<=num;i++)
        cal(V[i]),cal1(V[i]);
    for(int i=1;i<=n;i++)
    {
        int p=0;
        vector<int> ans;
        while(V[col[i]][p]!=i)p++;
        for(int j=p;j<V[col[i]].size();j++)
            ans.push_back(V[col[i]][j]);
        for(int j=0;j<p;j++)
            ans.push_back(V[col[i]][j]);
        for(int j=rk[col[i]]+1;j<A.size();j++)
            for(int k:V[A[j]])ans.push_back(k);
        cout<<ans.size()<<" ";
        for(int j:ans)cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}