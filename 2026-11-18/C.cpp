#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,P=998244353;
int n,a[N],b[N],rt[N],fa[N],siz[N];
int nxt[N*31][2],cnt[N*31],lazy[N*31];
int ans[N],sum[N*31];
queue<signed> q;
vector<int> V[N*31],tmp;
struct node{int x,y,z;}e[N];
bool cmp(node x,node y){return x.z<y.z;}
int getfa(int x){return x==fa[x]?x:(fa[x]=getfa(fa[x]));}
int tot()
{
    int res=q.front();
    q.pop();
    return res;
}
void cl(int x)
{
    nxt[x][0]=nxt[x][1]=0;
    cnt[x]=0;
    lazy[x]=0;
    sum[x]=0;
    V[x].clear();
    q.push(x);
}
void insert(int p,int x,int id)
{
    cnt[p]++;
    for(int i=29;i>=0;i--)
    {
        int c=(x>>i)&1ll;
        if(!nxt[p][c])nxt[p][c]=tot();
        p=nxt[p][c];
        cnt[p]++;
        sum[p]+=b[id];
        ans[id]-=lazy[p];
    }
    V[p].push_back(id);
}
void dfs(int p,int now)
{
    if(!p)return;
    now+=lazy[p];
    for(int c=0;c<=1;c++)
        dfs(nxt[p][c],now);
    for(int i:V[p])ans[i]+=now,tmp.push_back(i);
    cl(p);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n*31;i++)q.push(i);
    for(int i=1;i<=n;i++)
        rt[i]=tot(),fa[i]=i,siz[i]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        insert(rt[i],a[i],i);
    }
    for(int i=1;i<n;i++)
        cin>>e[i].x>>e[i].y>>e[i].z;
    sort(e+1,e+n,cmp);
    for(int i=1;i<n;i++)
    {
        int x=getfa(e[i].x),y=getfa(e[i].y),z=e[i].z;
        // cout<<x<<","<<y<<","<<z<<endl;
        if(siz[x]>siz[y])swap(x,y);
        tmp.clear();
        dfs(rt[x],0);
        for(int j:tmp)
        {
            int x=a[j],p=rt[y];
            // cout<<j<<"."<<ans[j]<<","<<p<<"!"<<endl;
            for(int k=29;k>=0;k--)
            {
                int c=(x>>k)&1ll;
                int d=(z>>k)&1ll;
                if(d)p=nxt[p][c^1];
                else 
                {
                    if(nxt[p][c^1])ans[j]+=sum[nxt[p][c^1]];
                    p=nxt[p][c];
                }
                if(!p)break;
            }
        }
        for(int j:tmp)
        {
            int x=a[j],p=rt[y];
            // cout<<j<<"."<<ans[j]<<","<<p<<"!"<<endl;
            for(int k=29;k>=0;k--)
            {
                int c=(x>>k)&1ll;
                int d=(z>>k)&1ll;
                if(d)p=nxt[p][c^1];
                else 
                {
                    if(nxt[p][c^1])lazy[nxt[p][c^1]]+=b[j];
                    p=nxt[p][c];
                }
                if(!p)break;
            }
        }
        for(int j:tmp)
            insert(rt[y],a[j],j);
        fa[x]=y;
        siz[y]+=siz[x];
    }
    dfs(rt[getfa(1)],0);
    for(int i=1;i<=n;i++)
        cout<<ans[i]%P*b[i]%P<<" ";
    cout<<endl;
    return 0;
}