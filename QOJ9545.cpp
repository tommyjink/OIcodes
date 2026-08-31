#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100,INF=1e16;
int n,a[N],tot=1,head[N];
int s,t,cnt,dis[N],in[N],now[N];
map<int,int> f,num;
vector<int> fac;
struct node{int to,next,w,c;}e[N*10];
void add(int x,int y,int w,int c)
{
    e[++tot]=(node){y,head[x],w,c};
    head[x]=tot;
    e[++tot]=(node){x,head[y],0,-c};
    head[y]=tot;
}
bool spfa()
{
    for(int i=0;i<=t;i++)dis[i]=-INF,now[i]=head[i];
    queue<int> q;
    q.push(s);
    in[s]=1;
    dis[s]=0;
    while(!q.empty())
    {
        int t=q.front();q.pop();in[t]=0;
        for(int i=head[t];i;i=e[i].next)
        {
            int v=e[i].to;
            if(e[i].w&&dis[t]+e[i].c>dis[v])
            {
                dis[v]=dis[t]+e[i].c;
                if(!in[v])q.push(v),in[v]=1;
            }
        }
    }
    return dis[t]!=-INF;
}
int dfs(int x,int sum)
{
    int res=0;
    if(x==t)return sum;
    in[x]=1;
    for(int i=now[x];i&&sum;i=e[i].next,now[x]=i)
    {
        int v=e[i].to;
        if(!in[v]&&dis[x]+e[i].c==dis[v]&&e[i].w)
        {
            int k=dfs(v,min(sum,e[i].w));
            e[i].w-=k,e[i^1].w+=k;
            sum-=k,res+=k;
        }
    }
    in[x]=0;
    return res;
}   
int mincost()
{
    int res=0;
    while(spfa())
    {
        int k=dfs(s,n);
        res+=k*dis[t];
    }
    return res;
}
void getfac(int x)
{
    vector<pair<int,int>> p;
    int y=x;
    for(int i=2;i*i<=y;i++)
    {
        if(y%i==0)
        {
            int c=0;
            while(y%i==0)y/=i,c++;
            p.push_back({i,c});
        }
    }
    if(y>1)p.push_back({y,1});

    vector<pair<int,int>> d;
    d.push_back({1,0});

    for(auto [P,c]:p)
    {
        int siz=d.size(),pw=1;
        for(int k=1;k<=c;k++)
        {
            pw*=P;
            for(int j=0;j<siz;j++)
                d.push_back({d[j].first*pw,d[j].second+k});
        }
    }

    for(auto [v,c]:d)
    {
        fac.push_back(v);
        f[v]=c;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;cnt=n;
    for(int i=1;i<=n;i++)
        cin>>a[i],getfac(a[i]);
    sort(fac.begin(),fac.end());
    fac.erase(unique(fac.begin(),fac.end()),fac.end());
    for(auto i:fac)
        num[i]=++cnt;
    s=fac.size()+n+1;
    t=s+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j*j<=a[i];j++)
        {
            if(a[i]%j)continue;
            add(i,num[j],1,f[a[i]]-f[j]);
            if(j*j!=a[i])add(i,num[a[i]/j],1,f[a[i]]-f[a[i]/j]);
        }
    }
    for(int i=1;i<=n;i++)
        add(s,i,1,0);
    for(int i=n+1;i<=cnt;i++)
        add(i,t,1,0);
    for(int i=1;i<=t;i++)
        now[i]=head[i];
    cout<<mincost()<<endl;
    // cout<<endl;

    return 0;
}