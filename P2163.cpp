#include<bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=5e5+100;
int n,m,ans[N],px[N],py[N],qx[N],qy[N],qxx[N],qyy[N];
struct Tree
{
    int t[N];
    void init(){memset(t,0,sizeof(t));}
    void add(int x,int d)
    {
        x++;
        for(int i=x;i<N;i+=lowbit(i))
            t[i]+=d;
    }
    int sum(int x)
    {
        x++;
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=t[i];
        return res;
    }
}t;
struct node
{
    int l,r,id,op;
};
vector<node> q[N];
vector<int> v[N];
vector<int> X,Y;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        X.push_back(x);
        Y.push_back(y);
        px[i]=x;
        py[i]=y;
        // v[x].push_back(y);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,xx,yy;
        cin>>x>>y>>xx>>yy;
        X.push_back(x);
        X.push_back(xx);
        Y.push_back(y);
        Y.push_back(yy);
        qx[i]=x;
        qy[i]=y;
        qxx[i]=xx;
        qyy[i]=yy;
        // if(x-1>=0)q[x-1].push_back({y,yy,i,-1});
        // q[xx].push_back({y,yy,i,1});
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    for(int i=1;i<=n;i++)
    {
        px[i]=lower_bound(X.begin(),X.end(),px[i])-X.begin();
        py[i]=lower_bound(Y.begin(),Y.end(),py[i])-Y.begin();
        v[px[i]].push_back(py[i]);
    }
    for(int i=1;i<=m;i++)
    {
        qx[i]=lower_bound(X.begin(),X.end(),qx[i])-X.begin();
        qy[i]=lower_bound(Y.begin(),Y.end(),qy[i])-Y.begin();
        qxx[i]=lower_bound(X.begin(),X.end(),qxx[i])-X.begin();
        qyy[i]=lower_bound(Y.begin(),Y.end(),qyy[i])-Y.begin();
        if(qx[i]-1>=0)q[qx[i]-1].push_back({qy[i],qyy[i],i,-1});
        q[qxx[i]].push_back({qy[i],qyy[i],i,1});
    }
    t.init();
    for(int i=0;i<N;i++)
    {
        for(auto j:v[i])t.add(j,1);
        for(auto j:q[i])
        {
            ans[j.id]+=j.op*(t.sum(j.r)-t.sum(j.l-1));
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}