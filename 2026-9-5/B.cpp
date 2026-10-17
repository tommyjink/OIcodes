#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10,M=2e5+10;
int n,m,head[N],tot=0,now,dis[N],vis[N],ans,mx;
vector<int> x[N],v[N];
struct node
{
    int to,next,val;
}e[M];
void add(int x,int y,int z)
{
    e[++tot]=(node){y,head[x],z};
    head[x]=tot;
}
bool cmp(int xx,int yy)
{
    return x[xx][now]>x[yy][now];
}
int gcd(int x,int y)
{
    while(y)
    {
        int t=x%y;
        x=y;
        y=t;
    }
    return x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        x[i].resize(n+1);
        for(int j=1;j<=n;j++)
        {
            cin>>x[i][j];
            mx=max(mx,x[i][j]);
            if(x[i][j])
                v[j].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        now=i;
        sort(v[i].begin(),v[i].end(),cmp);
        int len=v[i].size();
        for(int xx=0;xx<len-1;xx++)
        {
            int yy=xx+1;
            add(v[i][xx],v[i][yy],x[v[i][xx]][i]-x[v[i][yy]][i]);
            add(v[i][yy],v[i][xx],x[v[i][yy]][i]-x[v[i][xx]][i]);
        }
    }
    for(int i=1;i<=m;i++)
        if(!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int x=q.front();q.pop();
                for(int j=head[x];j;j=e[j].next)
                {
                    int y=e[j].to;
                    if(!vis[y])
                    {
                        vis[y]=1;
                        dis[y]=dis[x]+e[j].val;
                        q.push(y);
                    }
                    else ans=gcd(ans,abs(dis[x]+e[j].val-dis[y]));
                }
            }
        }
    if(!ans)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}
